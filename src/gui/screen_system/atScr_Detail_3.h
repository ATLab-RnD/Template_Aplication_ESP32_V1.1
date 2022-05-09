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
#ifndef _atScr_Detail_3_
#define _atScr_Detail_3_
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
class Scr_Detail_3: public Detail_Screen, public Sources
{
public:
    Scr_Detail_3();
    ~Scr_Detail_3();
	static void  Start();	
	static void  Execute();
protected:    
	void Update();
private:
    static void btn_Back_event_handler(lv_event_t *e);
    
}atScr_Detail_3;

Scr_Detail_3::Scr_Detail_3()
{
    _Start_User     = *Start;
    _Execute_User   = *Execute;
    ID_Screen = 1;
    Name_Screen = (char*)"Detail_3 Screen";
}
Scr_Detail_3::~Scr_Detail_3()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Scr_Detail_3::Start()
{
	atScr_Detail_3.screen_status = ACTIVE;
    //Write codes screen
	atScr_Detail_3.Object = lv_obj_create(NULL);
	//Create 4 button
	atScr_Detail_3.create_buttons(atScr_Detail_3.Object);
	//Write codes screen_1_label_1
	atScr_Detail_3.label_screen = lv_label_create(atScr_Detail_3.Object);
	atScr_Detail_3.setup_label(atScr_Detail_3.label_screen,"Detail_3.title",31,30,100,32);
	//create notified bar
	atScr_Detail_3.create_notified_bar(atScr_Detail_3.Object);
	atScr_Detail_3.render_modbus_icon(atScr_Detail_3.Screen_label_modbus,atScr_Detail_3.modbus_active_old,30,0);
	atScr_Detail_3.render_wifi_icon(atScr_Detail_3.Screen_label_wifi,atScr_Detail_3.wifi_active_old,0,0);
	atScr_Detail_3.render_SD_Card_icon(atScr_Detail_3.Screen_label_SD,atScr_Detail_3.SD_active_old,15,0);
	atScr_Detail_3.render_warning_icon(atScr_Detail_3.Screen_label_warning,atScr_Detail_3.warning_active_old,45,0);
	
	// init every events
    lv_obj_add_event_cb(atScr_Detail_3.btn_BACK, atScr_Detail_3.btn_Back_event_handler, LV_EVENT_ALL, NULL);
} 
/**
 * Execute fuction of SNM app
 */
void  Scr_Detail_3::Execute()
{
	atScr_Detail_3.Update();
}

void Scr_Detail_3::btn_Back_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		
		if (!lv_obj_is_valid(*atScr_Detail_3.Backward_Screen))
        {
			(*atScr_Detail_3.setup_Backward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*atScr_Detail_3.Backward_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			atScr_Detail_3.screen_status = DEACTIVE;
        }
	}
		break;
	default:
		break;
	}
}
void Scr_Detail_3::Update()
{

	if (atScr_Detail_3.Notified_Bar_1.minute < 60)
	{
		atScr_Detail_3.Notified_Bar_1.minute ++;
	}
	else 
	{
		atScr_Detail_3.Notified_Bar_1.minute = 0;
		if(atScr_Detail_3.Notified_Bar_1.hour < 22)
			atScr_Detail_3.Notified_Bar_1.hour ++;
		else atScr_Detail_3.Notified_Bar_1.hour = 0;
	}
	sprintf(atScr_Detail_3.Notified_Bar_1.time,"%d:%d",atScr_Detail_3.Notified_Bar_1.hour,atScr_Detail_3.Notified_Bar_1.minute);
	atScr_Detail_3.setup_label(atScr_Detail_3.Screen_label_time,atScr_Detail_3.Notified_Bar_1.time,120,0,40,15);
	//check active wifi
	if(atScr_Detail_3.wifi_active != atScr_Detail_3.wifi_active_old)
	{
		atScr_Detail_3.wifi_active_old = atScr_Detail_3.wifi_active;
		atScr_Detail_3.render_wifi_icon(atScr_Detail_3.Screen_label_wifi,atScr_Detail_3.wifi_active_old);
	}
	//check SD card active
	if (atScr_Detail_3.SD_active != atScr_Detail_3.SD_active_old)
	{
		atScr_Detail_3.SD_active_old = atScr_Detail_3.SD_active;
		atScr_Detail_3.render_SD_Card_icon(atScr_Detail_3.Screen_label_SD,atScr_Detail_3.SD_active_old);
	}
	//check modbus active
	if (atScr_Detail_3.modbus_active != atScr_Detail_3.modbus_active_old)
	{
		atScr_Detail_3.modbus_active_old = atScr_Detail_3.modbus_active;
		atScr_Detail_3.render_modbus_icon(atScr_Detail_3.Screen_label_modbus,atScr_Detail_3.modbus_active_old);
	}	
	//check warning active
	if (atScr_Detail_3.warning_active != atScr_Detail_3.warning_active_old)
	{
		atScr_Detail_3.warning_active_old = atScr_Detail_3.warning_active;
		atScr_Detail_3.render_warning_icon(atScr_Detail_3.Screen_label_warning,atScr_Detail_3.warning_active_old);
	}
}
#endif