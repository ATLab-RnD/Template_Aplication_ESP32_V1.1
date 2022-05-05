// /**
// @file

// */
// /*
//   Application example t

//   Library:: 

//   This version is

//   Copyright:: 2021 nguyentrinhtuan1996@gmail.com
// */

// #ifndef _Application_atApp_IDM_
// #define _Application_atApp_IDM_
// /* _____PROJECT INCLUDES____________________________________________________ */
// #include "..\App.h"
// #include "..\src\services\modbus_master\atService_MB_TCP_MA.h"
// #include "..\src\obj\atObj_IDMs_Data.h"

// /* _____DEFINETIONS__________________________________________________________ */
// enum Status_of_device
// {
// 	Offline,
// 	Online
// };
// enum direction_run
// {
// 	Forward,
// 	Reverse
// };
// /* _____GLOBAL VARIABLES_____________________________________________________ */
// TaskHandle_t Task_atApp_IDM;  
// void atApp_IDM_Task_Func(void *parameter);
// ///////////////////////////////////////////////Testing part//
// /* _____GLOBAL FUNCTION______________________________________________________ */

// /* _____CLASS DEFINITION_____________________________________________________ */

// /**
//  * This Application class is the application to manage the 
//  */
// class App_IDM : public Application
// {
// public:
//   	App_IDM();
//  	~App_IDM();
//   	static void  App_IDM_Pend();
// 	static void  App_IDM_Start();
// 	static void  App_IDM_Restart();
// 	static void  App_IDM_Execute();
// 	static void  App_IDM_Suspend();
// 	static void  App_IDM_Resume();	  
// 	static void  App_IDM_End();
//   uint8_t number_of_try_to_connect = 3;
//   uint16_t invt_type;
//   bool direction_run;
//   uint16_t set_frequency;
// protected:
//   uint8_t buffer;
//   uint8_t number_device;
// private:
// } atApp_IDM ;
// /**
//  * This function will be automaticaly called when a object is created by this class
//  */
// App_IDM::App_IDM(/* args */)
// {
//   	_Pend_User 	     = *App_IDM_Pend;
// 	_Start_User 	 = *App_IDM_Start;
// 	_Restart_User 	 = *App_IDM_Restart;
// 	_Execute_User 	 = *App_IDM_Execute;
// 	_Suspend_User	 = *App_IDM_Suspend;
// 	_Resume_User	 = *App_IDM_Resume;
// 	_End_User	     = *App_IDM_End;

// 	// change the ID of application
// 	ID_Application = 1;
// 	// change the application name
// 	Name_Application = (char*)"IDM Application";
// 	// change the ID of IDM
// }
// /**
//  * This function will be automaticaly called when the object of class is delete
//  */
// App_IDM::~App_IDM()
// {
	
// }
// /**
//  * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
//  */
// void  App_IDM::App_IDM_Pend()
// {
//     atService_MB_TCP_MA.Run_Service();
// }
// /**
//  * This start function will init some critical function 
//  */
// void  App_IDM::App_IDM_Start()
// {
// 	// init atXYZ Service in the fist running time
	
// }  
// /**
//  * Restart function of IDM  app
//  */
// void  App_IDM::App_IDM_Restart()
// {

// }
// /**
//  * Execute fuction of IDM app
//  */
// void  App_IDM::App_IDM_Execute()
// {	
//   if(atObject_IDMs_Data.IDM_number >= 1)
//   {
//     if(atApp_IDM.User_Mode == APP_USER_MODE_DEBUG)
//     {
//       Serial.println(" IDM number  ");
//     }
//     for( atApp_IDM.number_device = 1; atApp_IDM.number_device <= atObject_IDMs_Data.IDM_number;
//                                                                     atApp_IDM.number_device++ )
//     {	
//       IPAddress IP_module( 	atObject_IDMs_Data.IDM[atApp_IDM.number_device].IP[0], 
//                          	  atObject_IDMs_Data.IDM[atApp_IDM.number_device].IP[1],
//                          	  atObject_IDMs_Data.IDM[atApp_IDM.number_device].IP[2],
// 		  					            atObject_IDMs_Data.IDM[atApp_IDM.number_device].IP[3]);         
//       // try to connect slave device
//       for( uint8_t try_connect = 1; try_connect <= atApp_IDM.number_of_try_to_connect; try_connect++)
//       {     
//         if(mb_TCP.isConnected(IP_module))
// 		    {    
//           for( uint8_t try_read = 0; try_read <= 2; try_read++)
//           {
//             mb_TCP.writeHreg(IP_module, GENERAL_REGISTER_RW_DEVICE_ID, atApp_IDM.number_device);
//             mb_TCP.writeHreg(IP_module,IDM_REGISTER_RW_INVERTER_TYPE,atApp_IDM.invt_type);
//             if(atApp_IDM.direction_run = Forward)
//             {
//               mb_TCP.writeHreg(IP_module,IDM_REGISTER_RW_DIRECTION_RUN,Forward);
//             }
//             else
//             {
//               mb_TCP.writeHreg(IP_module,IDM_REGISTER_RW_DIRECTION_RUN,Reverse);
//             }
          
//             mb_TCP.readHreg(IP_module,IDM_REGISTER_RW_INVERTER_TYPE, 
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].invt_type);
//             mb_TCP.readCoil(IP_module, IDM_REGISTER_RW_DIRECTION_RUN,
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].direction_run);
//             mb_TCP.readHreg(IP_module, IDM_REGISTER_RW_SET_FREQUENCY,
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].set_frequency);
//             mb_TCP.readIreg(IP_module, IDM_REGISTER_R_OPERATION_FREQUENCY,
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].operating_frequency);
//             mb_TCP.readIreg(IP_module, IDM_REGISTER_R_INPUT_VOLTAGE,
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].input_voltage);  
//             mb_TCP.readIreg(IP_module, IDM_REGISTER_R_INPUT_CURRENT,
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].input_current);
//             mb_TCP.readIreg(IP_module, IDM_REGISTER_R_OUTPUT_VOLTAGE,
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].output_voltage); 
//             mb_TCP.readIreg(IP_module, IDM_REGISTER_R_OUTPUT_CURRENT,
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].output_current);
//             mb_TCP.readIreg(IP_module, IDM_REGISTER_R_FAULT_CODE,
//                                       &atObject_IDMs_Data.IDM[atApp_IDM.number_device].fault_code);
//             atService_MB_TCP_MA.check_In();   
//             atService_MB_TCP_MA.Run_Service();
//             atService_MB_TCP_MA.check_Out();
//           }     
//           atApp_IDM.buffer = 0;
//         }
//         else
//         {
//           mb_TCP.connect(IP_module);
//           atService_MB_TCP_MA.check_In();   
//           atService_MB_TCP_MA.Run_Service();
//           atService_MB_TCP_MA.check_Out();
//           atApp_IDM.buffer++;
//         }                                                                                                                   
//       }
//     if(atApp_IDM.buffer >= 1)
//     {
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].Status_of_IDMs = Offline;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].invt_type = 0;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].direction_run = 0;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].set_frequency = 0;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].operating_frequency = 0;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].input_voltage = 0;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].input_current = 0;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].output_voltage = 0;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].output_current = 0;
//       atObject_IDMs_Data.IDM[atApp_IDM.number_device].fault_code = 0;
//       // atObject_IDMs_Data.IDM[atApp_IDM.number_device].IP[0] = 0; 
//       // atObject_IDMs_Data.IDM[atApp_IDM.number_device].IP[1] = 0;    
//       // atObject_IDMs_Data.IDM[atApp_IDM.number_device].IP[2] = 0;    
//       // atObject_IDMs_Data.IDM[atApp_IDM.number_device].IP[3] = 0;     
//       // atObject_IDMs_Data.IDM_number = atObject_IDMs_Data.IDM_number - 1 ;  
//     }
//     if(atApp_IDM.User_Mode == APP_USER_MODE_DEBUG)
//     {
      
//     }
//   }
// }
// }
// void  App_IDM::App_IDM_Suspend(){}
// void  App_IDM::App_IDM_Resume(){}	  
// void  App_IDM::App_IDM_End(){}
// void atApp_IDM_Task_Func(void *parameter)
// {
//   while (1)
//   {
//     atApp_IDM.Run_Application(APP_RUN_MODE_AUTO);
//     vTaskDelay(1000/ portTICK_PERIOD_MS);
//   }
// }
// #endif