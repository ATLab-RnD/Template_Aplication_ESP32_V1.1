/**
@file
Screen Template.
*/
/*
  Screen

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef _atScr_ABC_
#define _atScr_ABC_
/* _____PROJECT INCLUDES____________________________________________________ */

#include "Arduino.h"
#include "lvgl.h"
#include "Monitor_Screen.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____DEFINETIONS__________________________________________________________ */
/*____CLASS DEFINITION_____________________________________________________ */
/**
 * This Screen class is base class for implement another class by inheritance 
 */
class Scr_ABC: public Monitor_Screen
{
public:
    Scr_ABC();
    ~Scr_ABC();
	static void  Screen_ABC_Start();	
	static void  Screen_ABC_Execute();
private:
    lv_obj_t *btn_UP;
    lv_obj_t *btn_DOWN;
    lv_obj_t *btn_BACK;
    lv_obj_t *btn_OK;
    lv_obj_t *label_1;

    static void btn_OK_event_handler();
}atScr_ABC;

Scr_ABC::Scr_ABC()
{
    _Start_User     = *Screen_ABC_Start;
    _Execute_User   = *Screen_ABC_Execute;
    ID_Screen = 1;
    Name_Screen = (char*)"Monitoring Screen"
}
Scr_ABC::~Scr_ABC()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Scr_ABC::Screen_ABC_Start()
{
	// init every events
    lv_obj_add_event_cb(btn_OK, btn_OK_event_handler, LV_EVENT_ALL, NULL);

    //Write codes screen
	Monitoring_Screen_Lite = lv_obj_create(NULL);
	//Create 4 button
	//Write codes screen_btn_BACK
	btn_BACK= lv_btn_create(Monitoring_Screen_Lite);
	lite_setup_button(btn_BACK,5,85,"BACK");
	//Write codes screen_btn_UP
	btn_UP = lv_btn_create(Monitoring_Screen_Lite);
	lite_setup_button(btn_UP,45,85,"UP");
	//Write codes screen_btn_DOWN
	btn_DOWN = lv_btn_create(Monitoring_Screen_Lite);
	lite_setup_button(btn_DOWN,85,85,"DOWN");
	//Write codes screen_btn_OK
	btn_OK = lv_btn_create(Monitoring_Screen_Lite);
	lite_setup_button(btn_OK,125,85,"OK");
	//Write codes screen_1_label_1
	label_1 = lv_label_create(Monitoring_Screen_Lite);
	lite_setup_label(label_1,"Monitoring_Screen_Lite.title",31,30,100,32);
	//create notified bar
	lite_create_notified_bar(Monitoring_Screen_Lite);
	
} 
/**
 * Execute fuction of SNM app
 */
void  Scr_ABC::Screen_ABC_Execute()
{

}

void Scr_ABC:btn_OK_event_handler()
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Forward_Screen))
        {
			(*setup_Forward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*Forward_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        }
	}
		break;
	default:
		break;
	}
}
#endif