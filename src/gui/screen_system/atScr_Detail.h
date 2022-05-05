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
#include "../Detail_Screen.h"
// #include "../Sources.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____DEFINETIONS__________________________________________________________ */

/*____CLASS DEFINITION_____________________________________________________ */
/**
 * This Screen class is base class for implement another class by inheritance 
 */
class Scr_Detail: public Detail_Screen, public Sources
{
public:
    Scr_Detail();
    ~Scr_Detail();
	static void  Start();	
	static void  Execute();
protected:    
	void Update();
private:
    static void btn_Back_event_handler(lv_event_t *e);
    
}atScr_Detail;

Scr_Detail::Scr_Detail()
{
    _Start_User     = *Start;
    _Execute_User   = *Execute;
    ID_Screen = 1;
    Name_Screen = (char*)"Detail Screen";
}
Scr_Detail::~Scr_Detail()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Scr_Detail::Start()
{
	atScr_Detail.screen_status = ACTIVE;
    //Write codes screen
	atScr_Detail.Object = lv_obj_create(NULL);
	//Create 4 button
	atScr_Detail.create_buttons(atScr_Detail.Object);
	//Write codes screen_1_label_1
	atScr_Detail.label_screen = lv_label_create(atScr_Detail.Object);
	atScr_Detail.setup_label(atScr_Detail.label_screen,"Detail.title",31,30,100,32);
	//create notified bar
	atScr_Detail.create_notified_bar(atScr_Detail.Object);
	atScr_Detail.render_modbus_icon(atScr_Detail.Screen_label_modbus,atScr_Detail.modbus_active_old,30,0);
	atScr_Detail.render_wifi_icon(atScr_Detail.Screen_label_wifi,atScr_Detail.wifi_active_old,0,0);
	atScr_Detail.render_SD_Card_icon(atScr_Detail.Screen_label_SD,atScr_Detail.SD_active_old,15,0);
	atScr_Detail.render_warning_icon(atScr_Detail.Screen_label_warning,atScr_Detail.warning_active_old,45,0);
	// init every events
    lv_obj_add_event_cb(atScr_Detail.btn_BACK, atScr_Detail.btn_Back_event_handler, LV_EVENT_ALL, NULL);
} 
/**
 * Execute fuction of SNM app
 */
void  Scr_Detail::Execute()
{
	atScr_Detail.Update();
}

void Scr_Detail::btn_Back_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		atScr_Detail.screen_status = DEACTIVE;
		if (!lv_obj_is_valid(*atScr_Detail.Backward_Screen))
        {
			(*atScr_Detail.setup_Backward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*atScr_Detail.Backward_Screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 100, true);
        }
	}
		break;
	default:
		break;
	}
}
void Scr_Detail::Update()
{

	if (atScr_Detail.Notified_Bar_1.minute < 60)
	{
		atScr_Detail.Notified_Bar_1.minute ++;
	}
	else 
	{
		atScr_Detail.Notified_Bar_1.minute = 0;
		if(atScr_Detail.Notified_Bar_1.hour < 22)
			atScr_Detail.Notified_Bar_1.hour ++;
		else atScr_Detail.Notified_Bar_1.hour = 0;
	}
	sprintf(atScr_Detail.Notified_Bar_1.time,"%d:%d",atScr_Detail.Notified_Bar_1.hour,atScr_Detail.Notified_Bar_1.minute);
	atScr_Detail.setup_label(atScr_Detail.Screen_label_time,atScr_Detail.Notified_Bar_1.time,120,0,40,15);
	//check active wifi
	if(atScr_Detail.wifi_active != atScr_Detail.wifi_active_old)
	{
		atScr_Detail.wifi_active_old = atScr_Detail.wifi_active;
		atScr_Detail.render_wifi_icon(atScr_Detail.Screen_label_wifi,atScr_Detail.wifi_active_old);
	}
	//check active
	if (atScr_Detail.SD_active != atScr_Detail.SD_active_old)
	{
		atScr_Detail.SD_active_old = atScr_Detail.SD_active;
		atScr_Detail.render_SD_Card_icon(atScr_Detail.Screen_label_SD,atScr_Detail.SD_active_old);
	}
	//check active
	if (atScr_Detail.modbus_active != atScr_Detail.modbus_active_old)
	{
		atScr_Detail.modbus_active_old = atScr_Detail.modbus_active;
		atScr_Detail.render_modbus_icon(atScr_Detail.Screen_label_modbus,atScr_Detail.modbus_active_old);
	}	
	//check active
	if (atScr_Detail.warning_active != atScr_Detail.warning_active_old)
	{
		atScr_Detail.warning_active_old = atScr_Detail.warning_active;
		atScr_Detail.render_warning_icon(atScr_Detail.Screen_label_warning,atScr_Detail.warning_active_old);
	}
}
#endif