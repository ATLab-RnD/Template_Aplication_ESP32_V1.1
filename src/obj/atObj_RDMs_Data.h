/**
@file
Objective for control with Esp32 Wrover.
*/
/*
  Object_RDMs_Data.h - Arduino library for control with ESP32
  Library:: Object_RDMs_Data
  This version is
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef Object_RDMs_Data_h
#define Object_RDMs_Data_h


/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
#include "Object.h"

/* _____DEFINETIONS__________________________________________________________ */

struct RDM_1_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_2_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_3_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_4_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_5_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_6_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_7_data
{
        uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_8_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_9_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_10_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_11_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_12_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_13_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_14_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_15_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_16_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_17_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_18_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_19_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

struct RDM_20_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In3;
    bool In4;
    bool In5;
    bool In6; 
    bool In7;
    bool In8;
    bool In9;
    bool In10;
    bool In11; 
    bool In12;
    bool In13;
    bool In14;
    bool In15;
    bool Out0;
    bool Out1; 
    bool Out2;
    bool Out3;
    bool Out4;
    bool Out5;
    bool Out6; 
    bool Out7;
    bool Out8;
    bool Out9;
    bool Out10;
    bool Out11; 
    bool Out12;
    bool Out13;
    bool Out14;
    bool Out15;
};

RDM_1_data RDM_1;
RDM_2_data RDM_2;
RDM_3_data RDM_3;
RDM_4_data RDM_4;
RDM_5_data RDM_5;
RDM_6_data RDM_6;
RDM_7_data RDM_7;
RDM_8_data RDM_8;
RDM_9_data RDM_9;
RDM_10_data RDM_10;
RDM_11_data RDM_11;
RDM_12_data RDM_12;
RDM_13_data RDM_13;
RDM_14_data RDM_14;
RDM_15_data RDM_15;
RDM_16_data RDM_16;
RDM_17_data RDM_17;
RDM_18_data RDM_18;
RDM_19_data RDM_19;
RDM_20_data RDM_20;
/* _____GLOBAL VARIABLES_____________________________________________________ */


/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This class is the application to manage the 
 */

class Object_RDMs_Data :public Object
{
public:
    static void   Object_Cont_Start();
    static void   Object_Cont_Execute();    
    static void   Object_Cont_End();
    
    uint8_t Get_Fault_State();
    Object_RDMs_Data(/* args */);
    ~Object_RDMs_Data();
    uint8_t RDM_number = 0;

protected: 
    
    
private:
    /* data */ 
} atObject_RDMs_Data;
/**
 * @brief This function code is executed one time when class is init
 * 
 */
Object_RDMs_Data::Object_RDMs_Data(/* args */)
{
     _Start_User      = *Object_Cont_Start;
     _Execute_User    = *Object_Cont_Execute;
     _End_User        = *Object_Cont_End;
}
/**
 * @brief This function code is executed one time when class is deinit
 * 
 */
Object_RDMs_Data::~Object_RDMs_Data()
{
}
/**
 * This start function will init some critical function 
 */
void  Object_RDMs_Data::Object_Cont_Start()
{
  
} 
/**
 * Execute fuction of RDM app
 */
void  Object_RDMs_Data:: Object_Cont_Execute()
{   

}    
void  Object_RDMs_Data:: Object_Cont_End(){}

#endif