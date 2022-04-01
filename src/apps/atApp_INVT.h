/**
@file
Application for communicating with inverter (via RTU protocol).
*/
/*
  Application_INVT.h - Arduino library for communicating with OP320A&S INVT
  over RS232/485 (via RTU protocol).

  Library:: INVT_GD200A.h

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_INVT_
#define _Application_atApp_INVT_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
#include "App.h"
#include "../services/INVT_GD200/atService_INVT_GD200A.h"
/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_INVT;  
void atApp_INVT_Task_Func(void *parameter);
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This Application class is the application to manage the 
 */
class App_INVT: public Application, public Service_INVT_GD200A
{
public:
  App_INVT();
  ~App_INVT();
  
  float Frequency = 25.25 ;// Unit (Hz)
  bool direction = FORWARD;
protected:
  static void  App_INVT_Pend();
	static void  App_INVT_Start();
	static void  App_INVT_Restart();
	static void  App_INVT_Execute();
	static void  App_INVT_Suspend();
	static void  App_INVT_Resume();	  
	static void  App_INVT_End();
private:
} atApp_INVT ;
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_INVT::App_INVT()
{
	_Pend_User 	    = *App_INVT_Pend;
	_Start_User 	  = *App_INVT_Start;
	_Restart_User   = *App_INVT_Restart;
	_Execute_User 	= *App_INVT_Execute;
	_Suspend_User	  = *App_INVT_Suspend;
	_Resume_User	  = *App_INVT_Resume;
	_End_User	      = *App_INVT_End;
  	// change the ID of application
	atApp_INVT.ID_Application = 2;
	// change the application name
	atApp_INVT.Name_Application = (char*)"INVT GD200A";
  // change the ID
  atApp_INVT.ID_Modbus = 3;
}
/**
 * 
 * This function will be automaticaly called when the object of class is delete
 */

App_INVT::~App_INVT()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. 
 * In the debug mode, task will send information of application to terminal to start the application.
 */
void  App_INVT::App_INVT_Pend()
{
	
}
/**
 * This start function will init some critical function 
 */
void  App_INVT::App_INVT_Start(){
  int8_t result = 0;
	// open the port
	atApp_INVT.Begin(atApp_INVT.ID_Modbus,9600,SWSERIAL_8E1);
  // reset all fault
  result = atApp_INVT.Reset_Fault();
  if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG) 
  { 
    Serial.printf_P("    reset fault : ");
    Serial.printf_P(atApp_INVT.Modbus_Error(result));
  }
  // set limit for frequency
  result = atApp_INVT.Set_Frequency_Limit(5000,5000);
  if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG) 
  {
    Serial.printf_P("    set limit : ");
    Serial.printf_P(atApp_INVT.Modbus_Error(result));
  }
} 

/**
 * Restart function of inverter app
 */
void  App_INVT::App_INVT_Restart()
{
  
}
/**
 * Execute fuction of INVT app
 */
void App_INVT::App_INVT_Execute()
{
  uint8_t result = 0;

  result = atApp_INVT.Get_Data_From_INVT();
  
  if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG)
  {
    Serial.printf_P("    get data : ");
    Serial.printf_P(atApp_INVT.Modbus_Error(result));

    Serial.printf_P("        INVT_Buffer_RW_Registers:");
    for ( int8_t i = 0; i < sizeof(INVT_Buffer_RW_Registers)/2; i++)
    {
      Serial.printf_P(" - [200%x]:%d",i, atApp_INVT.INVT_Buffer_RW_Registers[i]);
    }
    Serial.printf_P("\n");

    Serial.printf_P("        INVT_Buffer_R_Registers_1:");
    for ( int8_t i = 0; i < sizeof(INVT_Buffer_R_Registers_1)/2; i++)
    {
      Serial.printf_P("- [210%x]:%d",i, atApp_INVT.INVT_Buffer_R_Registers_1[i]);
    }
    Serial.printf_P("\n");

    Serial.printf_P("        INVT_Buffer_R_Registers_2:");
    for ( int8_t i = 0; i < sizeof(INVT_Buffer_R_Registers_2)/2; i++)
    {
      Serial.printf_P(" - [300%x]:%d",i, atApp_INVT.INVT_Buffer_R_Registers_2[i]);
    }
    Serial.printf_P("\n");

    Serial.printf_P("    fault INVT : ");
    Serial.printf_P(atApp_INVT.Fault_Char());

    Serial.printf_P("    Setting frequency: %.2f (Hz)\n",   atApp_INVT.Frequency_Setting());
    Serial.printf_P("    Operating frequency: %.2f (Hz)\n", atApp_INVT.Frequency_Operating());
    Serial.printf_P("    Operating speed: %.1f (RPM)\n",    atApp_INVT.Speed_Operating());
    Serial.printf_P("    Bus voltage: %.1f (V)\n",          atApp_INVT.Voltage_Bus());
    Serial.printf_P("    Output voltage: %.1f (V)\n",       atApp_INVT.Voltage_Output());
    Serial.printf_P("    Output currentL %.1f (A)\n",       atApp_INVT.Current_Output());
    Serial.printf_P("    Output Power: %.1f (%%)\n",        atApp_INVT.Power_Output());
    Serial.printf_P("    Output torque: %.1f (N.m)\n",      atApp_INVT.Torque_Output());
  }

  // reset fault if there remain
  if (atApp_INVT.Fault_Code() == FAULT10)
  {
    result = atApp_INVT.Reset_Fault();
    if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG) 
    { 
      Serial.printf_P("    reset fault : ");
      Serial.printf_P(atApp_INVT.Modbus_Error(result));
    }
  }

  // Set frequency to run
  result = atApp_INVT.Set_Frequency((uint16_t)(atApp_INVT.Frequency*100));
  if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG) 
  {  
    Serial.printf_P("    set inverter frequency to %2.2f : ",atApp_INVT.Frequency);
    Serial.printf_P(atApp_INVT.Modbus_Error(result));
  }
 
 // run the inverter with preciously setted frequency
  if(atApp_INVT.Frequency_Operating() == 0)
  {
    result = atApp_INVT.Stop_Running();
    if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG) 
    {  
      Serial.printf_P("    Stop running : ");
      Serial.printf_P(atApp_INVT.Modbus_Error(result));
    }
    result = atApp_INVT.Run(atApp_INVT.direction);
    if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG) 
    {  
      Serial.printf_P("    Run inverter: ");
      Serial.printf_P(atApp_INVT.Modbus_Error(result));
    }
  }

  // change the direction of inverter if the inverter's direction is different from user choice
  if(atApp_INVT.Control_Command() <= INVT_VALUE_REVERSE_RUNNING)
    if (atApp_INVT.direction != atApp_INVT.Control_Command())
    {
      result = atApp_INVT.Run(atApp_INVT.direction);
      if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG) 
      {  
        Serial.printf_P("    Run inverter: ");
        Serial.printf_P(atApp_INVT.Modbus_Error(result));
      }
    }

  if (atApp_INVT.User_Mode == APP_USER_MODE_DEBUG) 
  {
    Serial.printf_P("\n");
  }
}
void  App_INVT::App_INVT_Suspend(){}
void  App_INVT::App_INVT_Resume(){}	  
void  App_INVT::App_INVT_End(){}

void atApp_INVT_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_INVT.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}
#endif
