/**
@file
Arduino library for communicating with OP320A&S HMI over RS232/485 (via RTU protocol).
*/
/*

  chickyPig_OP320_V1.h - Arduino library for communicating with OP320A&S HMI
  over RS232/485 (via RTU protocol).

  Library:: chickyPig_OP320_V1

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef chickyPig_OP320_h
#define chickyPig_OP320_h

/* _____PROJECT INCLUDES____________________________________________________ */
#include <SoftwareSerial.h>
#include "../modbus_master/atService_MB_RTU_MA.h"
#include "Arduino.h"
#include "util/word.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */
/* _____DEFINETIONS__________________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * this public class is compatible with esp32. To interact with the HMI, this class need a serial port as a stream to
*/ 
class HMI_OPA320_AS
{
    public:
      uint8_t ID_Modbus;
      void    Begin(uint8_t HMI_ID,SoftwareSerial &serialPort, int Baudrate, SoftwareSerialConfig Serial_config);
      uint8_t SendDataToHMI_1st(void);
      uint8_t SendDataToHMI(void);
      uint8_t GetDataFromHMI(void);
      uint8_t Application(void);
      // internal data : the user definition
      uint16_t HMI_Fan_Speed               = 0 ;
      uint16_t HMI_Fan_Speed_High_Limit    = 0 ;
      uint16_t HMI_Fan_Speed_Low_Limit     = 0 ;
      bool HMI_Temperature_On_Off      = 0 ;
      uint16_t HMI_Temperature_Monitoring = 0 ;
      uint16_t HMI_Temperature_High_Limit  = 0 ;
      uint16_t HMI_Temperature_Low_Limit   = 0 ;
      bool HMI_Humidity_On_Off         = 0 ;
      uint16_t HMI_Humidity_Monitoring    = 0 ;
      uint16_t HMI_Humidity_High_Limit     = 0 ;
      uint16_t HMI_Humidity_Low_Limit      = 0 ;
      bool HMI_CO2_On_Off              = 0 ;
      uint16_t HMI_CO2_Monitoring         = 0 ;
      uint16_t HMI_CO2_High_Limit          = 0 ;
      uint16_t HMI_CO2_Low_Limit           = 0 ;
      bool HMI_Plugging                = 0 ;
      uint16_t HMI_Number_Of_Holding_Registers = 19;
      // the address of variables  in HMI
    private:
      static const uint8_t ADDRESS_HMI_Fan_Speed               = 0;
      static const uint8_t ADDRESS_HMI_Fan_Speed_High_Limit    = 1;
      static const uint8_t ADDRESS_HMI_Fan_Speed_Low_Limit     = 2;
      static const uint8_t ADDRESS_HMI_Temperature_On_Off      = 3;
      static const uint8_t ADDRESS_HMI_Temperature_Monitoring = 4;
      static const uint8_t ADDRESS_HMI_Temperature_High_Limit  = 5;
      static const uint8_t ADDRESS_HMI_Temperature_Low_Limit   = 6;
      static const uint8_t ADDRESS_HMI_Humidity_On_Off         = 7;
      static const uint8_t ADDRESS_HMI_Humidity_Monitoring    = 8;
      static const uint8_t ADDRESS_HMI_Humidity_High_Limit     = 9;
      static const uint8_t ADDRESS_HMI_Humidity_Low_Limit      = 10;
      static const uint8_t ADDRESS_HMI_CO2_On_Off              = 11;
      static const uint8_t ADDRESS_HMI_CO2_Monitoring         = 12;
      static const uint8_t ADDRESS_HMI_CO2_High_Limit          = 14;
      static const uint8_t ADDRESS_HMI_CO2_Low_Limit           = 16;
      static const uint8_t ADDRESS_HMI_Plugging                = 18; 
};

/**
 * Initialize class object. 
 *
 * Assigns the HMI slave ID and serial port.
 * Call once class has been instantiated, typically within setup(). this function will * open a software serial port and init modbus at this port.*
 *
 * @param HMI_ID HMI slave ID (1..255)
 * @param &serialPort reference to serial port object (Serial, Serial1, ... Serial3)
 * @param Baudrate is th baudrate of serial port for instance (9600, 115200, ...)
 * @param Serial_config is the construction of data frame that is transmit by serial 
 * @ingroup setup
*/
void HMI_OPA320_AS::Begin(uint8_t HMI_ID, SoftwareSerial &serialPort, int Baudrate, SoftwareSerialConfig Serial_config = SWSERIAL_8N1)
{ 
    serialPort.begin(Baudrate, Serial_config);
    Modbus_Isolated.begin(HMI_ID, serialPort);
}

/**
 * Send the data form internal data to hmi. Firstly, this function will push data ro TX buffer, the register 0 will be wrote to TransmitBuffer[0], 
 * the register 1 will be wrote to TransmitBuffer[1] ... Thus, they will be sent to HMI by Modbus. This function will send all data event output 
 * register and input register form LMC to HMI. Just call one time when power up system
 * @param HMI_Fan_Speed                
 * @param HMI_Fan_Speed_High_Limit     
 * @param HMI_Fan_Speed_Low_Limit      
 * @param HMI_Temperature_On_Off       
 * @param HMI_Temperature_Monitoring  
 * @param HMI_Temperature_High_Limit   
 * @param HMI_Temperature_Low_Limit    
 * @param HMI_Humidity_On_Off              
 * @param HMI_Humidity_Monitoring     
 * @param HMI_Humidity_High_Limit      
 * @param HMI_Humidity_Low_Limit       
 * @param HMI_CO2_On_Off               
 * @param HMI_CO2_Monitoring          
 * @param HMI_CO2_High_Limit           
 * @param HMI_CO2_Low_Limit            
 * @param HMI_Plugging   
 * @return 0 on success; exception number on failure
 * @ingroup Operate
*/
uint8_t HMI_OPA320_AS::SendDataToHMI_1st(void)
{
  // write the use data to Transmit buffer
  // write the information of fan speed
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Fan_Speed, HMI_Fan_Speed);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Fan_Speed_High_Limit, HMI_Fan_Speed_High_Limit);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Fan_Speed_Low_Limit, HMI_Fan_Speed_Low_Limit);

  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Temperature_On_Off, HMI_Temperature_On_Off);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Temperature_Monitoring, HMI_Temperature_Monitoring);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Temperature_High_Limit, HMI_Temperature_High_Limit);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Temperature_Low_Limit, HMI_Temperature_Low_Limit);
  
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Humidity_On_Off, HMI_Humidity_On_Off);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Humidity_Monitoring, HMI_Humidity_Monitoring);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Humidity_High_Limit, HMI_Humidity_High_Limit);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Humidity_Low_Limit, HMI_Humidity_Low_Limit);    

  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_CO2_On_Off, HMI_CO2_On_Off);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_CO2_Monitoring, HMI_CO2_Monitoring);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_CO2_High_Limit, HMI_CO2_High_Limit);
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_CO2_Low_Limit, HMI_CO2_Low_Limit); 

// this register will always be wrote by 1 - Plugged
  Modbus_Isolated.setTransmitBuffer(ADDRESS_HMI_Plugging, 1);
  // try to send 3 times til successfully sending data
  uint8_t result =  0;
  for(int i = 0; i<3; i++)
  {
    result = Modbus_Isolated.writeMultipleRegisters_chicky(ID_Modbus,0,HMI_Number_Of_Holding_Registers);
    if ( result == 0) break;
  }
  return result;
}
/**
 * Send the data form internal data to hmi. Firstly, this function will push data ro TX buffer, the register
 *  0 will be wrote to TransmitBuffer[0], the register 1 will be wrote to TransmitBuffer[1] ... Thus, they will
 *  be sent to HMI by Modbus. This function will send all output register from LCM to HMI.
 * @param HMI_Fan_Speed                
 * @param HMI_Temperature_Monitoring  
 * @param HMI_Humidity_Monitoring     
 * @param HMI_CO2_Monitoring          
 * @param HMI_Plugging   
 * @return 0 on success; exception number on failure
 * @ingroup Operate
*/
uint8_t HMI_OPA320_AS::SendDataToHMI(void)
{
  uint8_t result = 0;
  // send the tha data of fan speed to HMI
  result =+ Modbus_Isolated.writeSingleRegister_chicky(ID_Modbus,ADDRESS_HMI_Fan_Speed, HMI_Fan_Speed);
  // Send the infomation of Temperature to HMI
  result =+ Modbus_Isolated.writeSingleRegister_chicky(ID_Modbus,ADDRESS_HMI_Temperature_Monitoring, HMI_Temperature_Monitoring);
  // Send the infomation of Humidity to HMI
  result =+ Modbus_Isolated.writeSingleRegister_chicky(ID_Modbus,ADDRESS_HMI_Humidity_Monitoring, HMI_Humidity_Monitoring);
  // Send the infomation of Co2 to HMI
  result =+ Modbus_Isolated.writeSingleRegister_chicky(ID_Modbus,ADDRESS_HMI_CO2_Monitoring, HMI_CO2_Monitoring);
  // this register will always be wrote by 1 - Plugged
  // result =+ Modbus_Isolated.writeSingleRegister_chicky(ID_Modbus,ADDRESS_HMI_Plugging, 1);
  // try to send 3 times til successfully sending data
  return result;
}

/**
 * Get data from the hmi and write to user data. This funcion reads data form hmi what will be back to ResponseBuffer, 
 * and take to to the user data. Just the inputs register will be read back thi buffer
 * @param HMI_Fan_Speed_High_Limit     
 * @param HMI_Fan_Speed_Low_Limit      
 * @param HMI_Temperature_On_Off       
 * @param HMI_Temperature_High_Limit   
 * @param HMI_Temperature_Low_Limit    
 * @param HMI_Humidity_On_Off              
 * @param HMI_Humidity_High_Limit      
 * @param HMI_Humidity_Low_Limit       
 * @param HMI_CO2_On_Off               
 * @param HMI_CO2_High_Limit           
 * @param HMI_CO2_Low_Limit            
 * @param HMI_Plugging   
 * @return 0 on success; exception number on failure
 * @ingroup Operate
 **/
uint8_t HMI_OPA320_AS::GetDataFromHMI(void)
{
// Read all the holding register form HMI 3 if there any fault.
  uint8_t result =  0;
  for(int i = 0; i<3; i++)
  {
    result = Modbus_Isolated.readHoldingRegisters_chicky(ID_Modbus,0,HMI_Number_Of_Holding_Registers);
    if ( result == 0) break;
  }
// if there is any fault will update the data that is read from HMI, to user data
  if (result != 0) 
  {
    HMI_Plugging = 0;
    return result;
  }
// unless, update the data what is read from HMI, to user data
  if (result == Modbus_Isolated.ku8MBSuccess)
  {
    HMI_Plugging = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Plugging);
    if(HMI_Plugging)
    {
      HMI_Fan_Speed_High_Limit = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Fan_Speed_High_Limit);
      HMI_Fan_Speed_Low_Limit  = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Fan_Speed_Low_Limit );

      HMI_Temperature_On_Off     = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Temperature_On_Off );
      HMI_Temperature_High_Limit = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Temperature_High_Limit);
      HMI_Temperature_Low_Limit = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Temperature_Low_Limit);

      HMI_Humidity_On_Off     = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Humidity_On_Off );
      HMI_Humidity_High_Limit = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Humidity_High_Limit);
      HMI_Humidity_Low_Limit = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_Humidity_Low_Limit);;               

      HMI_CO2_On_Off     = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_CO2_On_Off );
      HMI_CO2_High_Limit = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_CO2_High_Limit);
      HMI_CO2_Low_Limit = Modbus_Isolated.getResponseBuffer(ADDRESS_HMI_CO2_Low_Limit);
    }
  }
  Modbus_Isolated.clearResponseBuffer();
  return result;
}

/**
 * The default application for OP320A&S class, Use an run this application at 1HZ fo slower
 * The application has no critical process,
 */ 
#endif// end of file