/**
@file
Objective for control with Esp32 Wrover.
*/
/*
  at_Cont.h - Arduino library for control with ESP32
  Library:: at_Cont
  This version is
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef at_Cont_h
#define at_Cont_h


/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
#include "Object.h"
/* _____DEFINETIONS__________________________________________________________ */

enum Example
{
    default_1,
    default2,
    default3
};

/* _____GLOBAL VARIABLES_____________________________________________________ */


/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINETION_____________________________________________________ */
/**
 * This class is the application to manage the 
 */

class at_Cont :public Object
{
public:
    static void   Object_Cont_Start();
    static void   Object_Cont_Execute();    
    static void   Object_Cont_End();
    
    uint8_t Get_Fault_State();
    at_Cont(/* args */);
    ~at_Cont();
protected: 
    
    
private:
    /* data */ 
};
/**
 * @brief This function code is executed one time when class is init
 * 
 */
at_Cont::at_Cont(/* args */)
{
     _Start_User      = *Object_Cont_Start;
     _Execute_User    = *Object_Cont_Execute;
     _End_User        = *Object_Cont_End;
}
/**
 * @brief This function code is executed one time when class is deinit
 * 
 */
at_Cont::~at_Cont()
{
}
/**
 * This start function will init some critical function 
 */
void  at_Cont::Object_Cont_Start()
{
  
} 
/**
 * Execute fuction of SNM app
 */
void  at_Cont:: Object_Cont_Execute()
{   

}    
void  at_Cont:: Object_Cont_End(){}

#endif