/**
@file
*/
/*

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_HMI_
#define _Application_atApp_HMI_
#define HMI_Lite
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/lvgl/atService_LVGL_HMI_Lite.h"
// #include "../gui/hmi_lite/HMI_lite_Monitoring_Screen.h"
// #include "../gui/hmi_lite/HMI_lite_Menu_Screen.h"
// #include "../gui/hmi_lite/HMI_lite_Detail_Screen.h"
#include "../gui/screen_system/atScr_Monitoring.h"
#include "../gui/screen_system/atScr_Detail.h"
#include "../gui/screen_system/atScr_Menu.h"
#include "../gui/screen_system/Sources.h"
#include "../services/SPI/atService_VSPI.h"
// #include "../services/lvgl/atService_atButtons_LEDs_PCF8575.h"

/* _____DEFINETIONS__________________________________________________________ */
bool count = 0;
/* _____GLOBAL VARIABLES_____________________________________________________ */
static TimerHandle_t screen_monitoring_update_timer = NULL;
///////////////////////////////////////////////Testing part//

/* _____GLOBAL FUNCTION______________________________________________________ */
TaskHandle_t Task_atApp_HMI;  
void atApp_HMI_Task_Func(void *parameter);
void update_data_to_screens(TimerHandle_t xTimer);
/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This Application class is the application to manage the 
 */
class App_HMI : public Application
{
public:
  	App_HMI();
 	~App_HMI();
  	static void  App_HMI_Pend();
	static void  App_HMI_Start();
	static void  App_HMI_Restart();
	static void  App_HMI_Execute();
	static void  App_HMI_Suspend();
	static void  App_HMI_Resume();	  
	static void  App_HMI_End();

	static const TickType_t update_screen_time = 2000/ portTICK_PERIOD_MS;;   // 2 second
	// bool update = 0;
protected:

private:
}  atApp_HMI ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_HMI::App_HMI(/* args */)
{
  	_Pend_User 	     = *App_HMI_Pend;
	_Start_User 	 = *App_HMI_Start;
	_Restart_User 	 = *App_HMI_Restart;
	_Execute_User 	 = *App_HMI_Execute;
	_Suspend_User	 = *App_HMI_Suspend;
	_Resume_User	 = *App_HMI_Resume;
	_End_User	     = *App_HMI_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"HMI Application";
	// change the ID of SNM

}	
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_HMI::~App_HMI()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. 
 * In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_HMI::App_HMI_Pend()
{
	// atService_LVGL_HMI_Lite.Debug();
	// atButtons_LEDs_PCF8575.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_HMI::App_HMI_Start()
{
	//screens map
	atScr_Monitoring.setup_Forward_Screen = *atScr_Menu.Start;
	atScr_Monitoring.Forward_Screen = &atScr_Menu.Object;

	atScr_Menu.setup_Forward_Screen = *atScr_Detail.Start;
	atScr_Menu.Forward_Screen = &atScr_Detail.Object;

	atScr_Menu.setup_Backward_Screen = *atScr_Monitoring.Start;
	atScr_Menu.Backward_Screen = &atScr_Monitoring.Object;

	atScr_Detail.setup_Backward_Screen = *atScr_Menu.Start;
	atScr_Detail.Backward_Screen = &atScr_Menu.Object;

	//init timer
	screen_monitoring_update_timer = xTimerCreate(
										"screen monitoring update timer",       // Name of timer
										update_screen_time,  					// Period of timer (in ticks)
										pdTRUE,                    				// Auto-reload
										(void *)0,                  			// Timer ID
										update_data_to_screens);           		// Callback function
	atService_VSPI.Run_Service();
	// atService_VSPI.check_In();
	atService_LVGL_HMI_Lite.Run_Service();	
	// atScr_Detail.Run_Screen();
	// atScr_Menu.Run_Screen();
	atScr_Monitoring.Run_Screen();
	//start timer
	xTimerStart(screen_monitoring_update_timer, portMAX_DELAY);
	lv_scr_load(atScr_Monitoring.Object);
	// atService_VSPI.check_Out();
}  
/**
 * Restart function of SNM  app
 */
void  App_HMI::App_HMI_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_HMI::App_HMI_Execute()
{	
	atService_VSPI.check_In();
	atService_LVGL_HMI_Lite.Run_Service();
	atService_VSPI.check_Out();
	
	if(atScr_Monitoring.screen_status == ACTIVE)
	{
		atScr_Monitoring.Run_Screen();
	}

	if(atScr_Menu.screen_status == ACTIVE)
	{
		atScr_Menu.Run_Screen();
		int roller_selected = atScr_Menu.get_roller_selected(atScr_Menu.roller_1);
		if(atApp_HMI.User_Mode == APP_USER_MODE_DEBUG)
    	{
			Serial.printf("roller selected: %d\n",roller_selected);
    	} 
	}	
	if(atScr_Detail.screen_status == ACTIVE)
	{
		atScr_Detail.Run_Screen();
	}
	// atScr_Monitoring.Update_Scr_Monitoring();

	//get roller selected

	if(atApp_HMI.User_Mode == APP_USER_MODE_DEBUG)
    {
		
    }   
}
void  App_HMI::App_HMI_Suspend(){}
void  App_HMI::App_HMI_Resume(){}	  
void  App_HMI::App_HMI_End(){}
void atApp_HMI_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_HMI.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(10/ portTICK_PERIOD_MS);
  }
}

void update_data_to_screens(TimerHandle_t xTimer)
{
	if(count == 0)
	{
		atScr_Detail.SD_active 		= ON;
		atScr_Detail.wifi_active 	= ON;
		atScr_Detail.modbus_active 	= ON;
		atScr_Detail.warning_active = ON;

		atScr_Monitoring.SD_active 		= ON;
		atScr_Monitoring.wifi_active 	= ON;
		atScr_Monitoring.modbus_active 	= ON;
		atScr_Monitoring.warning_active = ON;

		atScr_Menu.SD_active 		= ON;
		atScr_Menu.wifi_active 		= ON;
		atScr_Menu.modbus_active 	= ON;
		atScr_Menu.warning_active 	= ON;
		count =1;
	}
	else
	{
		atScr_Detail.SD_active 		= OFF;
		atScr_Detail.wifi_active 	= OFF;
		atScr_Detail.modbus_active 	= OFF;
		atScr_Detail.warning_active = OFF;

		atScr_Monitoring.SD_active 		= OFF;
		atScr_Monitoring.wifi_active 	= OFF;
		atScr_Monitoring.modbus_active 	= OFF;
		atScr_Monitoring.warning_active = OFF;

		atScr_Menu.SD_active 		= OFF;
		atScr_Menu.wifi_active 		= OFF;
		atScr_Menu.modbus_active 	= OFF;
		atScr_Menu.warning_active 	= OFF;
		count =0;
	}
}
#endif