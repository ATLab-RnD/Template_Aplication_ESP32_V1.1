// Template_Application_ESP32_V2.0

#include "../src/apps/atApp_ABC.h"
#include "../src/apps/atApp_Wifi.h"
#include "../src/apps/atApp_CP.h"

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
void atApp_Wifi_Application(void *parameter)
{
  while (1)
  {
    atApp_Wifi.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

TaskHandle_t Task_atApp_CP;  
void atApp_CP_Application(void *parameter)
{
  while (1)
  {
    atApp_CP.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

void setup() {
  // put your setup code here, to run once:

  // atApp_ABC.Debug();
  // {                           // create a task to run ABC application            
  //   xTaskCreatePinnedToCore(
  //     atApp_ABC_Application,      // task function
  //     "atApp_ABC_Application",      // name task
  //     50000,                  // stack size of task
  //     NULL,   
  //     1,                      // priority
  //     &Task_atApp_ABC,              // Task handle
  //     1                       // on core 1
  //   );
  // };

  atApp_Wifi.Debug();
  {                           // create a task to run ABC application            
    xTaskCreatePinnedToCore(
      atApp_Wifi_Application,      // task function
      "atApp_Wifi_Application",      // name task
      50000,                  // stack size of task
      NULL,   
      1,                      // priority
      &Task_atApp_Wifi,              // Task handle
      1                       // on core 1
    );
  };

  // atApp_CP.Debug();
  {                           // create a task to run ABC application            
    xTaskCreatePinnedToCore(
      atApp_CP_Application,      // task function
      "atApp_CP_Application",      // name task
      10000,                  // stack size of task
      NULL,   
      1,                      // priority
      &Task_atApp_CP,              // Task handle
      0                       // on core 1
    );
  };

}

void loop() {
  // put your main code here, to run repeatedly:
}