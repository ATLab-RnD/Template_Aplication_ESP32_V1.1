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
#ifndef _atScr_Detail_
#define _atScr_Detail_
/* _____PROJECT INCLUDES____________________________________________________ */

#include "Arduino.h"
#include "lvgl.h"
#include "Monitor_Screen.h"
#include "hmi_lite/HMI_Lite_Sources.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____DEFINETIONS__________________________________________________________ */

/*____CLASS DEFINITION_____________________________________________________ */
/**
 * This Screen class is base class for implement another class by inheritance 
 */
class Scr_Detail: public Monitor_Screen
{
public:
    Scr_Detail();
    ~Scr_Detail();
	static void  Screen_Detail_Start();	
	static void  Screen_Detail_Execute();
	lv_obj_t *btn_UP;
    lv_obj_t *btn_DOWN;
    lv_obj_t *btn_BACK;
    lv_obj_t *btn_OK;
    lv_obj_t *label_1;
    
    static void btn_Back_event_handler(lv_event_t *e);

private:
    
}atScr_Detail;

Scr_Detail::Scr_Detail()
{
    _Start_User     = *Screen_Detail_Start;
    _Execute_User   = *Screen_Detail_Execute;
    ID_Screen = 1;
    Name_Screen = (char*)"Monitoring Screen";
}
Scr_Detail::~Scr_Detail()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Scr_Detail::Screen_Detail_Start()
{
	
    //Write codes screen
	atScr_Detail.Object = lv_obj_create(NULL);
	//Create 4 button
	//Write codes screen_btn_BACK
	atScr_Detail.btn_BACK= lv_btn_create(atScr_Detail.Object);
	lite_setup_button(atScr_Detail.btn_BACK,5,60,"BACK");
	//Write codes screen_btn_UP
	atScr_Detail.btn_UP = lv_btn_create(atScr_Detail.Object);
	lite_setup_button(atScr_Detail.btn_UP,45,60,"UP");
	//Write codes screen_btn_DOWN
	atScr_Detail.btn_DOWN = lv_btn_create(atScr_Detail.Object);
	lite_setup_button(atScr_Detail.btn_DOWN,85,60,"DOWN");
	//Write codes screen_btn_OK
	atScr_Detail.btn_OK = lv_btn_create(atScr_Detail.Object);
	lite_setup_button(atScr_Detail.btn_OK,125,60,"OK");
	//Write codes screen_1_label_1
	atScr_Detail.label_1 = lv_label_create(atScr_Detail.Object);
	lite_setup_label(atScr_Detail.label_1,"Detail.title",31,30,100,32);
	//create notified bar
	lite_create_notified_bar(atScr_Detail.Object);

	// init every events
	
	lv_scr_load(atScr_Detail.Object);
    lv_obj_add_event_cb(atScr_Detail.Object, atScr_Detail.btn_Back_event_handler, LV_EVENT_ALL, NULL);
} 
/**
 * Execute fuction of SNM app
 */
void  Scr_Detail::Screen_Detail_Execute()
{

}

void Scr_Detail :: btn_Back_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*atScr_Detail.Backward_Screen))
        {
			(*atScr_Detail.setup_Backward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*atScr_Detail.Backward_Screen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 100, 100, true);
        }
	}
		break;
	default:
		break;
	}
}
#endif