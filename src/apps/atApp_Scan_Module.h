/**
@file

*/
/*
  Application example t

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_MD_
#define _Application_atApp_MD_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "..\services\modbus_master\atService_MB_TCP_MA.h"
#include "..\services\modbus_slave\Modbus_Registers.h"
#include "..\obj\atObj_EMMs_Data.h"
#include "..\obj\atObj_HDMs_Data.h"
#include "..\obj\atObj_IDMs_Data.h"
#include "..\obj\atObj_RDMs_Data.h"
#include "..\obj\atObj_SNMs_Data.h"
/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_MD;  
void atApp_MD_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */
enum Network_Index_IPV4
{
    A = 0,
    B,
    C,
    D,
    IPV4_Index_Number
};

/* _____CLASS DEFINITION_____________________________________________________ */

/**
 * This Application class is the application to manage the 
 */
class App_MD : public Application
{
public:
  	App_MD();
 	~App_MD();
  	static void  App_MD_Pend();
	static void  App_MD_Start();
	static void  App_MD_Restart();
	static void  App_MD_Execute();
	static void  App_MD_Suspend();
	static void  App_MD_Resume();	  
	static void  App_MD_End();
	uint8_t SNM_number_BF = 0;
	uint8_t IDM_number_BF = 0;
	uint8_t EMM_number_BF = 0;
	uint8_t RDM_number_BF = 0;
	uint8_t HDM_number_BF = 0;
	uint8_t X = 0;
	uint8_t Y = 2;
protected:
private:
} atApp_MD ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_MD::App_MD(/* args */)
{
  	_Pend_User 	     = *App_MD_Pend;
	_Start_User 	 = *App_MD_Start;
	_Restart_User 	 = *App_MD_Restart;
	_Execute_User 	 = *App_MD_Execute;
	_Suspend_User	 = *App_MD_Suspend;
	_Resume_User	 = *App_MD_Resume;
	_End_User	     = *App_MD_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"MD Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_MD::~App_MD()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_MD::App_MD_Pend()
{
}
/**
 * This start function will init some critical function 
 */
void  App_MD::App_MD_Start()
{
	// init atXYZ Service in the fist running time
}  
/**
 * Restart function of SNM  app
 */
void  App_MD::App_MD_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_MD::App_MD_Execute()
{	
	for(atApp_MD.X = 0; atApp_MD.X <=255; atApp_MD.Y++)
	{
		for(atApp_MD.Y = 2; atApp_MD.Y <=255; atApp_MD.Y++)
		{
			IPAddress remote(192, 168, atApp_MD.X, atApp_MD.Y); 
			atService_MB_TCP_MA.connect(remote); 
		}
	}
    if(atApp_MD.User_Mode == APP_USER_MODE_DEBUG)
    {
		
    }   
}
void  App_MD::App_MD_Suspend(){}
void  App_MD::App_MD_Resume(){}	  
void  App_MD::App_MD_End(){}
void atApp_MD_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_MD.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}


#endif