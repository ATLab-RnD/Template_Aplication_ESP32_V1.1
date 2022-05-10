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
#ifndef _atScr_Detail_2_
#define _atScr_Detail_2_
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
class Scr_Detail_2: public Detail_Screen, public Sources
{
public:
    Scr_Detail_2();
    ~Scr_Detail_2();
	static void  Start();	
	static void  Execute();
protected:    
	void Update();
private:
    static void btn_Back_event_handler(lv_event_t *e);
    
}atScr_Detail_2;

Scr_Detail_2::Scr_Detail_2()
{
    _Start_User     = *Start;
    _Execute_User   = *Execute;
    ID_Screen = 1;
	screen_status = DEACTIVE;
    Name_Screen = (char*)"Detail_2 Screen";
}
Scr_Detail_2::~Scr_Detail_2()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Scr_Detail_2::Start()
{
    //Write codes screen
	atScr_Detail_2.Object = lv_obj_create(NULL);
	//Create 4 button
	atScr_Detail_2.create_buttons(atScr_Detail_2.Object);
	//Write codes screen_1_label_1
	atScr_Detail_2.label_screen = lv_label_create(atScr_Detail_2.Object);
	atScr_Detail_2.setup_label(atScr_Detail_2.label_screen,"Detail_2.title",31,30,100,32);
	//create notified bar
	atScr_Detail_2.create_notified_bar(atScr_Detail_2.Object);
	atScr_Detail_2.render_modbus_icon(atScr_Detail_2.Screen_label_modbus,atScr_Detail_2.Notified_Bar_old_1.modbus_active,30,0);
	atScr_Detail_2.render_wifi_icon(atScr_Detail_2.Screen_label_wifi,atScr_Detail_2.Notified_Bar_old_1.wifi_active,0,0);
	atScr_Detail_2.render_SD_Card_icon(atScr_Detail_2.Screen_label_SD,atScr_Detail_2.Notified_Bar_old_1.SD_active,15,0);
	atScr_Detail_2.render_warning_icon(atScr_Detail_2.Screen_label_warning,atScr_Detail_2.Notified_Bar_old_1.warning_active,45,0);
	sprintf(atScr_Detail_2.char_time,"%d:%d",atScr_Detail_2.Notified_Bar_old_1.hour,atScr_Detail_2.Notified_Bar_old_1.minute);
	atScr_Detail_2.setup_label(atScr_Detail_2.Screen_label_time,atScr_Detail_2.char_time,120,0,40,15);
	// init every events
    lv_obj_add_event_cb(atScr_Detail_2.btn_BACK, atScr_Detail_2.btn_Back_event_handler, LV_EVENT_ALL, NULL);
	atScr_Detail_2.screen_status = ACTIVE;
} 
/**
 * Execute fuction of SNM app
 */
void  Scr_Detail_2::Execute()
{
	atScr_Detail_2.Update();
}

void Scr_Detail_2::btn_Back_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		
		if (!lv_obj_is_valid(*atScr_Detail_2.Backward_Screen))
        {
			(*atScr_Detail_2.setup_Backward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*atScr_Detail_2.Backward_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			atScr_Detail_2.screen_status = DEACTIVE;
        }
	}
		break;
	default:
		break;
	}
}
void Scr_Detail_2::Update()
{
	if((atScr_Detail_2.Notified_Bar_old_1.hour != atScr_Detail_2.Notified_Bar_1.hour) || (atScr_Detail_2.Notified_Bar_old_1.minute != atScr_Detail_2.Notified_Bar_1.minute))
	{
		atScr_Detail_2.Notified_Bar_old_1.hour = atScr_Detail_2.Notified_Bar_1.hour;
		atScr_Detail_2.Notified_Bar_old_1.minute = atScr_Detail_2.Notified_Bar_1.minute;
		sprintf(atScr_Detail_2.char_time,"%d:%d",atScr_Detail_2.Notified_Bar_old_1.hour,atScr_Detail_2.Notified_Bar_old_1.minute);
		atScr_Detail_2.setup_label(atScr_Detail_2.Screen_label_time,atScr_Detail_2.char_time);
	}
	//check active wifi
	if(atScr_Detail_2.Notified_Bar_1.wifi_active != atScr_Detail_2.Notified_Bar_old_1.wifi_active)
	{
		atScr_Detail_2.Notified_Bar_old_1.wifi_active = atScr_Detail_2.Notified_Bar_1.wifi_active;
		atScr_Detail_2.render_wifi_icon(atScr_Detail_2.Screen_label_wifi,atScr_Detail_2.Notified_Bar_old_1.wifi_active);
	}
	//check active
	if (atScr_Detail_2.Notified_Bar_1.SD_active != atScr_Detail_2.Notified_Bar_old_1.SD_active)
	{
		atScr_Detail_2.Notified_Bar_old_1.SD_active = atScr_Detail_2.Notified_Bar_1.SD_active;
		atScr_Detail_2.render_SD_Card_icon(atScr_Detail_2.Screen_label_SD,atScr_Detail_2.Notified_Bar_old_1.SD_active);
	}
	//check active
	if (atScr_Detail_2.Notified_Bar_1.modbus_active != atScr_Detail_2.Notified_Bar_old_1.modbus_active)
	{
		atScr_Detail_2.Notified_Bar_old_1.modbus_active = atScr_Detail_2.Notified_Bar_1.modbus_active;
		atScr_Detail_2.render_modbus_icon(atScr_Detail_2.Screen_label_modbus,atScr_Detail_2.Notified_Bar_old_1.modbus_active);
	}	
	//check active
	if (atScr_Detail_2.Notified_Bar_1.warning_active != atScr_Detail_2.Notified_Bar_old_1.warning_active)
	{
		atScr_Detail_2.Notified_Bar_old_1.warning_active = atScr_Detail_2.Notified_Bar_1.warning_active;
		atScr_Detail_2.render_warning_icon(atScr_Detail_2.Screen_label_warning,atScr_Detail_2.Notified_Bar_old_1.warning_active);
	}
}
#endif