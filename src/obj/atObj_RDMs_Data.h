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
#include "../apps/atApp_CP.h"
#include "../apps/atApp_Scan_Dev.h"

/* _____DEFINETIONS__________________________________________________________ */

struct RDM_1_data
{
    uint DID = 0;
    char Status_RDMs[100];
    float ID[4] = {0,0,0,0};
    bool In0;
    bool In1; 
    bool In2;
    bool In;
    bool In0;
};

struct RDM_2_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_3_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_4_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_5_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_6_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_7_data
{
        uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_8_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_9_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_10_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_11_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_12_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_13_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_14_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_15_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_16_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_17_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_18_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_19_data
{
    uint DID = 0;
    char Status_RDMs[100];
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

struct RDM_20_data
{
    uint DID = 0;
    char Status_RDMs[100];
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