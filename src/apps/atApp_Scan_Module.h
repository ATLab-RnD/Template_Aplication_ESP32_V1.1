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

	uint8_t X = 0;
	uint8_t Y = 2;
	uint8_t IP[IPV4_Index_Number]        = 	{192,168,X,Y};
	//Device type
	uint16_t REG_DT = 10;
	uint16_t DT = 0;
	//Device Identify
	uint16_t REG_DID = 11;
	uint16_t DID = 0;
	// Number buffer
	uint8_t SNM_number_BF = 0;
	uint8_t IDM_number_BF = 0;
	uint8_t EMM_number_BF = 0;
	uint8_t RDM_number_BF = 0;
	uint8_t HDM_number_BF = 0;
	
	// Register of SNM
	uint16_t REG_Temperature = 3001;
	uint16_t REG_Humidity = 3002;
	uint16_t REG_CO2 = 3003;
	uint16_t REG_H2 = 3004;
	uint16_t REG_TVOC = 3005;
	uint16_t REG_Ethanol = 3006;


protected:
	void create_id_of_SNM();
	void create_id_of_EMM();
	void create_id_of_IDM();
	void create_id_of_RDM();
	void create_id_of_HDM();

	void take_information_SNM();
	void take_information_EMM();
	void take_information_IDM();
	void take_information_RDM();
	void take_information_HDM();
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
	atService_MB_TCP_MA.Run_Service();
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
			mb_TCP.connect(atApp_MD.IP); 
			mb_TCP.task();
			mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_DT, &atApp_MD.DT);
			switch (atApp_MD.DT)
			{
				case 3:
					atApp_MD.SNM_number_BF++;
					atApp_MD.create_id_of_SNM();
					atApp_MD.take_information_SNM();
					break;
				case 4:
					atApp_MD.EMM_number_BF++;
					atApp_MD.create_id_of_EMM();
					atApp_MD.take_information_EMM();
					break;
				case 5:
					atApp_MD.IDM_number_BF++;
					atApp_MD.create_id_of_IDM();
					atApp_MD.take_information_IDM();
					break;
				case 6:
					atApp_MD.RDM_number_BF++;
					atApp_MD.take_information_RDM();
					atApp_MD.create_id_of_RDM();
					break;
				case 7:
					atApp_MD.HDM_number_BF++;
					atApp_MD.take_information_HDM();
					atApp_MD.create_id_of_HDM();
					break;
			}
		}
	}

	// Save the number of module
	atObject_SNMs_Data.SNM_number = atApp_MD.SNM_number_BF;
	atObject_EMMs_Data.EMM_number = atApp_MD.EMM_number_BF;
	atObject_IDMs_Data.IDM_number = atApp_MD.IDM_number_BF;
	atObject_RDMs_Data.RDM_number = atApp_MD.RDM_number_BF;
	atObject_HDMs_Data.HDM_number = atApp_MD.HDM_number_BF;
	
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

void App_MD::create_id_of_SNM()
{	
	mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_DID, &atApp_MD.DID);
	if (atApp_MD.DID == 0)
	{	
		for (uint16_t a = 1; a <= 20; a++)
		{
			if(atObject_SNMs_Data.Status_of_SNMs[a] = 0)
			{
				mb_TCP.writeHreg(atApp_MD.IP, atApp_MD.REG_DID, a);
				atObject_SNMs_Data.Status_of_SNMs[a] = 1;
				break;
			}
		}
	}
}

void App_MD::create_id_of_EMM()
{	
	mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_DID, &atApp_MD.DID);
	if (atApp_MD.DID == 0)
	{	
		for (uint16_t a = 1; a <= 20; a++)
		{
			if(atObject_SNMs_Data.Status_of_SNMs[a] = 0)
			{
				mb_TCP.writeHreg(atApp_MD.IP, atApp_MD.REG_DID, a);
				atObject_SNMs_Data.Status_of_SNMs[a] = 1;
				break;
			}
		}
	}
}

void App_MD::take_information_SNM()
{
	atObject_SNMs_Data.Host_1[atApp_MD.SNM_number_BF] = atApp_MD.X;
	atObject_SNMs_Data.Host_2[atApp_MD.SNM_number_BF] = atApp_MD.Y;

	mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_Temperature, 
					&atObject_SNMs_Data.Temperature[atApp_MD.SNM_number_BF]);

	mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_Humidity, 
					&atObject_SNMs_Data.Humidity[atApp_MD.SNM_number_BF]);

	mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_CO2, 
					&atObject_SNMs_Data.CO2[atApp_MD.SNM_number_BF]);

	mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_H2, 
					&atObject_SNMs_Data.H2[atApp_MD.SNM_number_BF]);

	mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_TVOC, 
					&atObject_SNMs_Data.TVOC[atApp_MD.SNM_number_BF]);	
					
	mb_TCP.readHreg(atApp_MD.IP, atApp_MD.REG_Ethanol, 
					&atObject_SNMs_Data.Ethanol[atApp_MD.SNM_number_BF]);									
}


#endif