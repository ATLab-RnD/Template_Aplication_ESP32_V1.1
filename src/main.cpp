// // Template_Application_ESP32_V2.0

// // #include "../src/apps/atApp_ABC.h"
// #include "../src/apps/atApp_Wifi.h"
// #include "../src/apps/atApp_CP.h"
// // #include "../src/apps/atApp_MB_RTU_SL.h"
// // #include "../src/apps/atApp_MB_TCP_SL.h"
// // #include "../src/apps/atApp_INVT.h"
// // #include "../src/apps/atApp_ADE.h"
// // #include "../src/apps/atApp_CD.h"
// #include "../src/apps/atApp_SHT30.h"
// // #include "../src/apps/atApp_SGP30.h"
// // #include "../src/apps/atApp_exHMI.h"
// // #include "../src/apps/atApp_DS18B20.h"
// #include "../src/apps/atApp_HMI.h"
// #include "../src/apps/atApp_DataBase.h"
// #include "../src/apps/atApp_Ethernet.h"

// void setup() {
// // uncomment to put the app in debug mod

//   // atApp_ABC.Debug();
//   // atApp_Wifi.Debug();
//   // atApp_CP.Debug();
//   // atApp_MB_RTU_SL.Debug();
//   // atApp_MB_TCP_SL.Debug();
//   // atApp_INVT.Debug();
//   // atApp_CD.Debug();
//   // atApp_SGP30.Debug();
//   // atApp_SHT30.Debug();
//   // atApp_ADE.Debug();
//   // atApp_HMI.Debug();
//   // atApp_DataBase.Debug();
//   atApp_Ethernet.Debug();


// //--------------------------------------------------------------------Tasks table ----------------------------------------------------------------------------------//     
// //------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// // || Creation           ||     Task function         ||     PC name                    || heap size  || Parameter || Priority  || Task handle          || CoreID   ||
//   // xTaskCreatePinnedToCore(  atApp_ABC_Task_Func       , "atApp_ABC_Application"         ,  1000       ,     NULL    ,   1       , &Task_atApp_ABC       ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_CP_Task_Func        , "atApp_CP_Application"          ,  10000      ,     NULL    ,   1       , &Task_atApp_CP        ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_Wifi_Task_Func      , "atApp_Wifi_Application"        ,  10000      ,     NULL    ,   1       , &Task_atApp_Wifi      ,    1     );
//   // xTaskCreatePinnedToCore(  atApp_MB_RTU_SL_Task_Func , "atApp_MB_RTU_SL_Application"   ,  10000      ,     NULL    ,   1       , &Task_atApp_MB_RTU_SL ,    1     );
//   // xTaskCreatePinnedToCore(  atApp_MB_TCP_SL_Task_Func , "atApp_MB_TCP_SL_Application"   ,  10000      ,     NULL    ,   1       , &Task_atApp_MB_TCP_SL ,    1     );
//   // xTaskCreatePinnedToCore(  atApp_INVT_Task_Func      , "atApp_INVT_Application"        ,  10000      ,     NULL    ,   1       , &Task_atApp_CP        ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_ADE_Task_Func       , "atApp_ADE_Application"         ,  10000      ,     NULL    ,   1       , &Task_atApp_ADE       ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_CD_Task_Func        , "atApp_CD_Application"          ,  10000      ,     NULL    ,   1       , &Task_atApp_CD        ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_SGP30_Task_Func     , "atApp_SGP30_Application"       ,  10000      ,     NULL    ,   1       , &Task_atApp_SGP30     ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_SHT30_Task_Func     , "atApp_SHT30_Application"       ,  10000      ,     NULL    ,   1       , &Task_atApp_SHT30     ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_exHMI_Task_Func     , "atApp_exHMI_Application"       ,  10000      ,     NULL    ,   1       , &Task_atApp_exHMI     ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_DataBase_Task_Func  , "atApp_DataBase_Application"    ,  10000      ,     NULL    ,   1       , &Task_atApp_DataBase  ,    1     );
//   // xTaskCreatePinnedToCore(  atApp_HMI_Task_Func       , "atApp_HMI_Application"         ,  100000     ,     NULL    ,   1       , &Task_atApp_HMI       ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_DS18B20_Task_Func   , "atApp_DS18B20_Application"     ,  10000      ,     NULL    ,   1       , &Task_atApp_DS18B20   ,    0     );
//   // xTaskCreatePinnedToCore(  atApp_PCF8575_Task_Func   , "atApp_PCF8575_Application"     ,  10000      ,     NULL    ,   1       , &Task_atApp_PCF8575  ,    0     );
//   xTaskCreatePinnedToCore(  atApp_Ethernet_Task_Func  , "atApp_Ethernet_Application"    ,  10000      ,     NULL    ,   1       , &Task_atApp_Ethernet  ,    0     );
//   //------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//   // Some tasks will be suspended after initing 
//   // vTaskSuspend(Task_atApp_MB_TCP_SL);
// }

// void loop() {}
#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.
// gateway and subnet are optional:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
IPAddress myDns(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);


// telnet defaults to port 23
EthernetServer server(23);
boolean alreadyConnected = false; // whether or not the client was connected previously

void setup() {
  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

  // initialize the ethernet device
  Ethernet.begin(mac, ip, myDns, gateway, subnet);

  // Open serial communications and wait for port to open:
  Serial.begin(112500);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start listening for clients
  server.begin();

  Serial.print("Chat server address:");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // wait for a new client:
  EthernetClient client = server.available();

  // when the client sends the first byte, say hello:
  if (client) {
    if (!alreadyConnected) {
      // clear out the input buffer:
      client.flush();
      Serial.println("We have a new client");
      client.println("Hello, client!");
      alreadyConnected = true;
    }

    if (client.available() > 0) {
      // read the bytes incoming from the client:
      char thisChar = client.read();
      // echo the bytes back to the client:
      server.write(thisChar);
      // echo the bytes to the server as well:
      Serial.write(thisChar);
    }
  }
}
