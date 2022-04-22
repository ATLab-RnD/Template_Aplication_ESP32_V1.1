/**
@file
Objective for control with Esp32 Wrover.
*/
/*
  Object_EMMs_Data.h - Arduino library for control with ESP32
  Library:: Object_EMMs_Data
  This version is
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef Object_EMMs_Data_h
#define Object_EMMs_Data_h


/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
#include "Object.h"

/* _____DEFINETIONS__________________________________________________________ */

struct EMM_1_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_2_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_3_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_4_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_5_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_6_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_7_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_8_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_9_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_10_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_11_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_12_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_13_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_14_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_15_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_16_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_17_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_18_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_19_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

struct EMM_20_data
{
    uint DID = 0;
    char Status_EMMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t Alert;
    float voltage_phase_A;
    float voltage_phase_B;
    float voltage_phase_C;
    float current_phase_A;
    float current_phase_B;
    float current_phase_C;
    float active_power;
    float reactive_power;
    float apparent_power;
    float cosfi;
    float frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

EMM_1_data EMM_1;
EMM_2_data EMM_2;
EMM_3_data EMM_3;
EMM_4_data EMM_4;
EMM_5_data EMM_5;
EMM_6_data EMM_6;
EMM_7_data EMM_7;
EMM_8_data EMM_8;
EMM_9_data EMM_9;
EMM_10_data EMM_10;
EMM_11_data EMM_11;
EMM_12_data EMM_12;
EMM_13_data EMM_13;
EMM_14_data EMM_14;
EMM_15_data EMM_15;
EMM_16_data EMM_16;
EMM_17_data EMM_17;
EMM_18_data EMM_18;
EMM_19_data EMM_19;
EMM_20_data EMM_20;

/* _____GLOBAL VARIABLES_____________________________________________________ */


/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This class is the application to manage the 
 */

class Object_EMMs_Data :public Object
{
public:
    static void   Object_Cont_Start();
    static void   Object_Cont_Execute();    
    static void   Object_Cont_End();
    
    uint8_t Get_Fault_State();
    Object_EMMs_Data(/* args */);
    ~Object_EMMs_Data();
    uint8_t EMM_number = 0;
protected: 
    
private:
    /* data */ 
} atObject_EMMs_Data;
/**
 * @brief This function code is executed one time when class is init
 * 
 */
Object_EMMs_Data::Object_EMMs_Data(/* args */)
{
     _Start_User      = *Object_Cont_Start;
     _Execute_User    = *Object_Cont_Execute;
     _End_User        = *Object_Cont_End;
}
/**
 * @brief This function code is executed one time when class is deinit
 * 
 */
Object_EMMs_Data::~Object_EMMs_Data()
{
}
/**
 * This start function will init some critical function 
 */
void  Object_EMMs_Data::Object_Cont_Start()
{
  
} 
/**
 * Execute fuction of EMM app
 */
void  Object_EMMs_Data:: Object_Cont_Execute()
{   

}    
void  Object_EMMs_Data:: Object_Cont_End(){}

#endif