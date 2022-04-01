// Template_Application_ESP32_V2.0

#include "../src/apps/atApp_ABC.h"
#include "../src/apps/atApp_Wifi.h"
#include "../src/apps/atApp_CP.h"
#include "../src/apps/atApp_MB_RTU_SL.h"

TaskHandle_t Task_atApp_ABC;  
void atApp_ABC_Application(void *parameter)
{
  while (1)
  {
    atApp_ABC.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

TaskHandle_t Task_atApp_Wifi;  
void atApp_Wifi_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_Wifi.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

TaskHandle_t Task_atApp_CP;  
void atApp_CP_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_CP.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

TaskHandle_t Task_atApp_MB_RTU_SL;  
void atApp_MB_RTU_SL_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_MB_RTU_SL.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1/ portTICK_PERIOD_MS);
  }
}

void setup() {
  // uncomment to put the app in debug mod
  // atApp_ABC.Debug();
  // atApp_Wifi.Debug();
  // atApp_CP.Debug();
  atApp_MB_RTU_SL.Debug();

//---------------------------------------------  Tasks table -------------------------------------------------------//     
//------------------------------------------------------------------------------------------------------------------//
// || Creation           ||     Task function         ||     PC name                    || heap size  || Parameter || Priority  || Task handle       || CoreID   ||
  // xTaskCreatePinnedToCore(  atApp_Wifi_Task_Func      , "atApp_Wifi_Application"        ,  50000      ,     NULL    ,   1       , &Task_atApp_Wifi    ,    1     );
  // xTaskCreatePinnedToCore(  atApp_CP_Task_Func        , "atApp_CP_Application"          ,  50000      ,     NULL    ,   1       , &Task_atApp_CP      ,    0     );
  xTaskCreatePinnedToCore(  atApp_MB_RTU_SL_Task_Func , "atApp_MB_RTU_SL_Application"   ,  50000      ,     NULL    ,   1       , &Task_atApp_CP      ,    0     );
}

void loop() {}