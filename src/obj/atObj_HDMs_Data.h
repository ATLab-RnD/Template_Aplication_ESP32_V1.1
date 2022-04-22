/**
@file
Objective for control with Esp32 Wrover.
*/
/*
  Object_HDMs_Data.h - Arduino library for control with ESP32
  Library:: Object_HDMs_Data
  This version is
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef Object_HDMs_Data_h
#define Object_HDMs_Data_h


/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
#include "Object.h"

/* _____DEFINETIONS__________________________________________________________ */

struct HDM_1_data
{
    uint DID = 0;
    char Status_HDMs[100];
    float ID[4] = {0,0,0,0};
    bool operation_mode;
    float low_limit_temperature;
    float high_limit_temperature;
    float power;
    float low_limit_power;
    float high_limit_power;
    float temperature;
  
};

struct HDM_2_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_3_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_4_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_5_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_6_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_7_data
{
        uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_8_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_9_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_10_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_11_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_12_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_13_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_14_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_15_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_16_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_17_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_18_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_19_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

struct HDM_20_data
{
    uint DID = 0;
    char Status_HDMs[100];
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

HDM_1_data HDM_1;
HDM_2_data HDM_2;
HDM_3_data HDM_3;
HDM_4_data HDM_4;
HDM_5_data HDM_5;
HDM_6_data HDM_6;
HDM_7_data HDM_7;
HDM_8_data HDM_8;
HDM_9_data HDM_9;
HDM_10_data HDM_10;
HDM_11_data HDM_11;
HDM_12_data HDM_12;
HDM_13_data HDM_13;
HDM_14_data HDM_14;
HDM_15_data HDM_15;
HDM_16_data HDM_16;
HDM_17_data HDM_17;
HDM_18_data HDM_18;
HDM_19_data HDM_19;
HDM_20_data HDM_20;

/* _____GLOBAL VARIABLES_____________________________________________________ */


/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This class is the application to manage the 
 */

class Object_HDMs_Data :public Object
{
public:
    static void   Object_Cont_Start();
    static void   Object_Cont_Execute();    
    static void   Object_Cont_End();
    
    uint8_t Get_Fault_State();
    Object_HDMs_Data(/* args */);
    ~Object_HDMs_Data();
    uint8_t HDM_number = 0;
protected: 
    
    
private:
    /* data */ 
} atObject_HDMs_Data;
/**
 * @brief This function code is executed one time when class is init
 * 
 */
Object_HDMs_Data::Object_HDMs_Data(/* args */)
{
     _Start_User      = *Object_Cont_Start;
     _Execute_User    = *Object_Cont_Execute;
     _End_User        = *Object_Cont_End;
}
/**
 * @brief This function code is executed one time when class is deinit
 * 
 */
Object_HDMs_Data::~Object_HDMs_Data()
{
}
/**
 * This start function will init some critical function 
 */
void  Object_HDMs_Data::Object_Cont_Start()
{
  
} 
/**
 * Execute fuction of HDM app
 */
void  Object_HDMs_Data:: Object_Cont_Execute()
{   

}    
void  Object_HDMs_Data:: Object_Cont_End(){}

#endif