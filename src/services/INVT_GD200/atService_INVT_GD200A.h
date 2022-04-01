/**
@file
Arduino library for communicating with GD200 Inverter over RS/485 (via RTU protocol).
*/
/*

  INVT_GD200A_V1.h - Arduino library for communicating with OP320A&S HMI
  over RS232/485 (via RTU protocol).

  Library:: INVT_GD200A_V1

  This version sofware driver is dev for GD200 series of INVT inverter. Prequisites is
  P00.01 = 2;
  P00.06 = 8;
  P00.17 = 1 ;// if the load is low
  p02.01 = 5.5;// Load Power
  p06.04 = 5 ;
  P14.00 = 3; //MODBUS_INVT_ADDRESS 
  P14.01 = 3;
  P14.02 = 1;
  P14.03 = 0;
  _RW_ characteristics means the function is with read and write characteristics
  _R_ characteristic can only read other than write 
  _W_ characteristic can only write other than read
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef INVT_GD200A_h
#define INVT_GD200A_h

/* _____PROJECT INCLUDES____________________________________________________ */
#include <SoftwareSerial.h>
#include"../modbus_master/atService_MB_RTU_MA.h"
#include "Arduino.h"
#include "util/word.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */
#ifndef _Modbus_Isolated_
#define _Modbus_Isolated_
atService_MB_RTU_MA Modbus_Isolated;
#endif

/* _____DEFINETIONS__________________________________________________________ */
// time delay between 2 command
#include "INVT_GD200A_Defines.h"
/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * this public class is compatible with esp32. To interact with the GD200 INVT, 
 * this class need a serial port as a stream to transciever data with inverter.
 * Init by begin
*/
class INVT_GD200A 
{
public :
  uint8_t   ID_Modbus = 0;
  void      Begin(uint8_t INVT_ID, int Baudrate, SoftwareSerialConfig Serial_config);
  // information
  uint8_t   Fault_Code(void);
  char*     Fault_Char(void);
  uint8_t   Control_Command(void);
  float     Frequency_Operating(void);
  float     Frequency_Setting(void);
  float     Speed_Operating(void);
  float     Voltage_Bus(void);
  float     Voltage_Output(void);
  float     Current_Output(void);
  float     Power_Output(void);
  float     Torque_Output(void);
 
protected:
 // command
  uint8_t   Set_Frequency(uint16_t Set_Frequency);
  uint8_t   Set_Frequency_Limit(uint16_t Forward_Limit, uint16_t Reverse_Limit);
  uint8_t   Run(bool Direction);
  uint8_t   Stop_Running(void);
  uint8_t   Jog(bool Direction);
  uint8_t   Stop_Jogging(void);
  uint8_t   Stop_Emergency(void);
  uint8_t   Reset_Fault(void);

  uint8_t  Get_Data_From_INVT(void);
  uint16_t INVT_Buffer_RW_Registers[15];
  uint16_t INVT_Buffer_R_Registers_1[4];
  uint16_t INVT_Buffer_R_Registers_2[16];
private :
  
  uint16_t INVT_Buffer_Fault_Code = 0;
  
};
/**
 * Initialize class object. 
 *
 * Assigns the INVT slave ID and serial port.
 * Call once class has been instantiated, typically within setup(). this function will * open a software serial port and init modbus at this port.*
 *
 * @param INVT_ID HMI slave ID (1..255)
 * @param Baudrate is th baudrate of serial port for (1200, 2400, 4800, 9600, 19200, 38400, 57600)
 * @param Serial_config is the construction of data frame that is transmit by serial 
 * @ingroup setup
*/
void INVT_GD200A::Begin(uint8_t INVT_ID, int Baudrate, SoftwareSerialConfig Serial_config = SWSERIAL_8N1)
{ 
  if (Modbus_Isolated.Status == NOT_OPENNED)
  {
    Serial_ModBus_Isolated.begin(Baudrate, Serial_config);
    Modbus_Isolated.begin(INVT_ID, Serial_ModBus_Isolated);
    Modbus_Isolated.Status = OPENNED;
  }
}
/**
 * Get read registers from inverter. 
 * This function will read all read register from form inverter and write it to INVT_Buffer.
 * Need to be call regularly to get data from 
 */
uint8_t INVT_GD200A::Get_Data_From_INVT(void)
{
  // INVT_Buffer_RW_Register
  // Read all the holding register form HMI 3 if there any fault.
  uint8_t result =  0;
  uint8_t atCount = 0;
  for(int i = 0; i<3; i++)
  {
    // read the
    result = Modbus_Isolated.readHoldingRegisters_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND,sizeof(INVT_Buffer_RW_Registers)/2);
    delay(Time_Delay_5ms);
    if ( result == 0) break;
  }
  // if there is any fault will update the data that is read from HMI, to user data
  if (result != 0) return result;
  else
  {
    for(atCount = 0; atCount < sizeof(INVT_Buffer_RW_Registers)/2; atCount ++)
    {
      // read data from modbus buffer and write to INVT buffer
      INVT_Buffer_RW_Registers[atCount] = Modbus_Isolated.getResponseBuffer(atCount);      
    }
  }

  // INVT_Buffer_R_Registers_1
  for(int i = 0; i<3; i++)
  {
    // read the
    result = Modbus_Isolated.readHoldingRegisters_at(ID_Modbus,INVT_REGISTER_R_SW1,sizeof(INVT_Buffer_R_Registers_1)/2);
    delay(Time_Delay_5ms);
    if ( result == 0) break;
  }
  // if there is any fault will update the data that is read from HMI, to user data
  if (result != 0) return result;
  else
  {
    for(atCount = 0; atCount < sizeof(INVT_Buffer_R_Registers_1)/2; atCount ++)
    {
      // read data from modbus buffer and write to INVT buffer
      INVT_Buffer_R_Registers_1[atCount] = Modbus_Isolated.getResponseBuffer(atCount);      
    }
  }

  // INVT_Buffer_R_Registers_2
  for(int i = 0; i<3; i++)
  {
    // read the
    result = Modbus_Isolated.readHoldingRegisters_at(ID_Modbus,INVT_REGISTER_R_OPERATION_FREQUENCY,sizeof(INVT_Buffer_R_Registers_2)/2);
    delay(Time_Delay_5ms);
    if ( result == 0) break;
  }
  // if there is any fault will update the data that is read from HMI, to user data
  if (result != 0) return result;
  else
  {
    for(atCount = 0; atCount < sizeof(INVT_Buffer_R_Registers_2)/2; atCount ++)
    {
      // read data from modbus buffer and write to INVT buffer
      INVT_Buffer_R_Registers_2[atCount] = Modbus_Isolated.getResponseBuffer(atCount);      
    }
  }

  // inverter fault code
  for(int i = 0; i<3; i++)
  {
    // read the
    result = Modbus_Isolated.readHoldingRegisters_at(ID_Modbus,INVT_REGISTER_R_FAULT_CODE,1);
    delay(Time_Delay_5ms);
    if ( result == 0) break;
  }
  // if there is any fault will  update the data that is read from HMI, to user data
  if (result != 0) return result;
  else
  {
    INVT_Buffer_Fault_Code = Modbus_Isolated.getResponseBuffer(0);      
  }
    
  Modbus_Isolated.clearResponseBuffer();
  return result;
}
/**
 * Run the inverter fellow the direction and the frequency that have been set.
 * @param Direction : FORWARD or REVERSE
 */
uint8_t INVT_GD200A::Run(bool Direction)
{
  uint8_t result =  0;
  if (Direction == FORWARD)
    result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND, INVT_VALUE_FORWARD_RUNNING);
  else
    result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND, INVT_VALUE_REVERSE_RUNNING);
  delay(Time_Delay_5ms);
  return result;
}
/**
 * Stop running.
 * This will stop the inverter 
 */
uint8_t INVT_GD200A::Stop_Running(void)
{
  uint8_t result =  0;
  result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND, INVT_VALUE_STOP);
  delay(Time_Delay_5ms);
  return result;
}
/**
 * Jogging 
 * @param Direction  FORWARD or REVERSE
 */
uint8_t INVT_GD200A::Jog(bool Direction)
{
  uint8_t result =  0;
  if (Direction == FORWARD)
    result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND, INVT_VALUE_FORWARD_JOGGING);
  else
    result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND, INVT_VALUE_REVERSE_JOGGING);
    delay(Time_Delay_5ms);
  return result;
}
/**
 * Stop jogging
 */
uint8_t INVT_GD200A::Stop_Jogging()
{
  uint8_t result =  0;
  result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND, INVT_VALUE_JOGGING_STOP);
  delay(Time_Delay_5ms);
  return result;
}
/**
 * Emergency stop. Just use in emergency case
 */
uint8_t INVT_GD200A::Stop_Emergency(void)
{
  uint8_t result =  0;
  result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND, INVT_VALUE_COAST_TO_STOP);
  delay(Time_Delay_5ms);
  return result;
}
/**
 * reset fault.
 * This function will erase the fault history in inverter. Should be call after an electrical fault
 */
uint8_t INVT_GD200A::Reset_Fault(void)
{
  uint8_t result =  0;
  delay(Time_Delay_5ms);
  result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_CONTROL_COMMAND, INVT_VALUE_FAULT_RESET);
  delay(Time_Delay_500ms);
  return result;
}
/**
 * Set frequency for inverter.
 * this frequency will be send to inverter and udpate to operate inverter. To
 * ensure if the defined user frequency, user can check by Frequency_Setting();
 * There are 2 Fmaxs for 2 rotation direction: forward and reverse rotation frequency
 * Range: 0~Fmax
 * Unit: 0.01Hz
 * @param Set_Frequency the frequency will be set for inverter
 */
uint8_t INVT_GD200A::Set_Frequency(uint16_t Set_Frequency)
{
  uint8_t result =  0;
  result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_SETTING_FREQUENCY, Set_Frequency);
  delay(Time_Delay_5ms);
  return result;
}

/**
 * Set limits for forward and reverse rotation frequency. The setting frequency must be less than limit
 * @param Forward_Limit the upper forward rotation frequency (0.00Hz)
 * @param Reverse_Limit the upper reverse rotation frequency (0.00Hz)
 */
uint8_t INVT_GD200A::Set_Frequency_Limit(uint16_t Forward_Limit, uint16_t Reverse_Limit)
{
  uint8_t result =  0;
  result = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_FORWARD_ROTATION_LIMIT_FREQ, Forward_Limit);
  delay(Time_Delay_5ms);
  // if there is any fault, return error code
  if (result == 0) return result;
  INVT_Buffer_Fault_Code = Modbus_Isolated.writeSingleRegister_at(ID_Modbus,INVT_REGISTER_RW_REVERSE_ROTATION_LIMIT_FREQ, Reverse_Limit);
  delay(Time_Delay_5ms);
  return result;
}
/**
 * read the code of inverter fault 
 */
uint8_t INVT_GD200A::Fault_Code()
{
  return INVT_Buffer_Fault_Code;
}
/**
 * return the fault by char*
 */
char* INVT_GD200A::Fault_Char(void)
{
  switch (INVT_Buffer_Fault_Code)
  {
  case FAULT1:
    return FAULT1_Char;
    break;
  case FAULT2:
    return FAULT2_Char;
    break;
  case FAULT3:
    return FAULT3_Char;
    break;
  case FAULT4:
    return FAULT4_Char;
    break;
  case FAULT5:
    return FAULT5_Char;
    break;
  case FAULT6:
    return FAULT6_Char;
    break;
  case FAULT7:
    return FAULT7_Char;
    break;
  case FAULT8:
    return FAULT8_Char;
    break;
  case FAULT9:
    return FAULT9_Char;
    break;
  case FAULT10:
    return FAULT10_Char;
    break;
  case FAULT11:
    return FAULT11_Char;
    break;
  case FAULT12:
    return FAULT12_Char;
    break;
  case FAULT13:
    return FAULT13_Char;
    break;
  case FAULT14:
    return FAULT14_Char;
    break;
  case FAULT15:
    return FAULT15_Char;
    break;
  case FAULT16:
    return FAULT16_Char;
    break;
  case FAULT17:
    return FAULT17_Char;
    break;
  case FAULT18:
    return FAULT18_Char;
    break;
  case FAULT19:
    return FAULT19_Char;
    break;
  case FAULT20:
    return FAULT20_Char;
    break;
  case FAULT21:
    return FAULT21_Char;
    break;
  case FAULT22:
    return FAULT22_Char;
    break;
  case FAULT23:
    return FAULT23_Char;
    break;
  case FAULT24:
    return FAULT24_Char;
    break;
  case FAULT25:
    return FAULT25_Char;
    break;
  case FAULT26:
    return FAULT26_Char;
    break;
  case FAULT27:
    return FAULT27_Char;
    break;
  case FAULT28:
    return FAULT28_Char;
    break;
  case FAULT32:
    return FAULT32_Char;
    break;
  case FAULT33:
    return FAULT33_Char;
    break;
  case FAULT36:
    return FAULT36_Char;
    break;

  default:
    return FAULT0_Char;
    break;
  }
}

uint8_t INVT_GD200A::Control_Command(void)
{
  return INVT_Buffer_RW_Registers[INVT_Buffer_RW_Index_Control_Command];
}
/**
 * return the operating frequency
 * Unit: Hz
 */
float INVT_GD200A::Frequency_Operating(void)
{
  return (float)INVT_Buffer_R_Registers_2[INVT_Buffer_R_Index_OPERATION_FREQUENCY] / 100;
}
/**
 * return the setting frequency
 * Unit: Hz
 */
float INVT_GD200A::Frequency_Setting(void)
{
  return (float)INVT_Buffer_R_Registers_2[INVT_Buffer_R_Index_SETTING_FREQUENCY] / 100;
}
/**
 * Bus voltage. 
 * Range: 0~1200V
 * Unit: V
 */
float INVT_GD200A::Voltage_Bus(void)
{
  return (float)INVT_Buffer_R_Registers_2[INVT_Buffer_R_Index_BUS_VOLTAGE]/10;
}
/**
 * output voltage
 * Range: 0~1200V
 * Unit: V
 */
float INVT_GD200A::Voltage_Output(void)
{
  return INVT_Buffer_R_Registers_2[INVT_Buffer_R_Index_OUTPUT_VOLTAGE];
}
/**
 * Output current
 * Range: 0.0~5000.0A
 * Unit; A
 */
float INVT_GD200A::Current_Output(void)
{
  return (float)INVT_Buffer_R_Registers_2[INVT_Buffer_R_Index_OUTPUT_CURRENT]/10;
}
/**
 * output power
 * Range: -300.0~300.0%
 * Unit: %
 */
float  INVT_GD200A::Power_Output(void)
{
  return (float)INVT_Buffer_R_Registers_2[INVT_Buffer_R_Index_OUTPUT_POWER]/10;
}

/**
 * operation speed
 * Range: 0-65535 
 * Unit: RPM
 */
float INVT_GD200A::Speed_Operating()
{
  return (float)INVT_Buffer_R_Registers_2[INVT_Buffer_R_Index_OPERATION_SPEED];
}

/**
 * output torque
 * Range: 0.0 - 6553.5
 * Unit: N.m
 */
float INVT_GD200A::Torque_Output()
{
  return (float)((int16_t)INVT_Buffer_R_Registers_2[INVT_Buffer_R_Index_OUTPUT_TORQUE])/10;
}
#endif