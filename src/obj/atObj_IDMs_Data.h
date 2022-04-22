/**
@file
Objective for control with Esp32 Wrover.
*/
/*
  Object_IDMs_Data.h - Arduino library for control with ESP32
  Library:: Object_IDMs_Data
  This version is
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef Object_IDMs_Data_h
#define Object_IDMs_Data_h


/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
#include "Object.h"

/* _____DEFINETIONS__________________________________________________________ */

struct IDM_1_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_2_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_3_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_4_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_5_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_6_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_7_data
{
        uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_8_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_9_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_10_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_11_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_12_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_13_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_14_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_15_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_16_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_17_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_18_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_19_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

struct IDM_20_data
{
    uint DID = 0;
    char Status_IDMs[100];
    float ID[4] = {0,0,0,0};
    uint8_t invt_type;  
    bool direction_run;
    float set_frequency = 0;
	float operating_frequency = 0;
	float input_voltage  = 0;
	float input_current = 0;
	float output_voltage  = 0;
	float output_current = 0;
    uint8_t fault_code; 
};

IDM_1_data IDM_1;
IDM_2_data IDM_2;
IDM_3_data IDM_3;
IDM_4_data IDM_4;
IDM_5_data IDM_5;
IDM_6_data IDM_6;
IDM_7_data IDM_7;
IDM_8_data IDM_8;
IDM_9_data IDM_9;
IDM_10_data IDM_10;
IDM_11_data IDM_11;
IDM_12_data IDM_12;
IDM_13_data IDM_13;
IDM_14_data IDM_14;
IDM_15_data IDM_15;
IDM_16_data IDM_16;
IDM_17_data IDM_17;
IDM_18_data IDM_18;
IDM_19_data IDM_19;
IDM_20_data IDM_20;

/* _____GLOBAL VARIABLES_____________________________________________________ */


/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This class is the application to manage the 
 */

class Object_IDMs_Data :public Object
{
public:
    static void   Object_Cont_Start();
    static void   Object_Cont_Execute();    
    static void   Object_Cont_End();
    
    uint8_t Get_Fault_State();
    Object_IDMs_Data(/* args */);
    ~Object_IDMs_Data();
    uint8_t IDM_number = 0;

protected: 
    
    
private:
    /* data */ 
} atObject_IDMs_Data;
/**
 * @brief This function code is executed one time when class is init
 * 
 */
Object_IDMs_Data::Object_IDMs_Data(/* args */)
{
     _Start_User      = *Object_Cont_Start;
     _Execute_User    = *Object_Cont_Execute;
     _End_User        = *Object_Cont_End;
}
/**
 * @brief This function code is executed one time when class is deinit
 * 
 */
Object_IDMs_Data::~Object_IDMs_Data()
{
}
/**
 * This start function will init some critical function 
 */
void  Object_IDMs_Data::Object_Cont_Start()
{
  
} 
/**
 * Execute fuction of IDM app
 */
void  Object_IDMs_Data:: Object_Cont_Execute()
{   

}    
void  Object_IDMs_Data:: Object_Cont_End(){}

#endif