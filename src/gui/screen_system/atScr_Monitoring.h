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
#ifndef _atScr_Monitoring_
#define _atScr_Monitoring_
/* _____PROJECT INCLUDES____________________________________________________ */

#include "Arduino.h"
#include "lvgl.h"
#include "../Monitor_Screen.h"
// #include "../Sources.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____DEFINETIONS__________________________________________________________ */

/*____CLASS DEFINITION_____________________________________________________ */
/**
 * This Screen class is base class for implement another class by inheritance 
 */
class Scr_Monitoring: public Monitor_Screen , public Sources
{
public:
    Scr_Monitoring();
    ~Scr_Monitoring();
	static void  Start();	
	static void  Execute();

protected:
	void Update();

private:

    static void btn_OK_event_handler(lv_event_t *e);
    
}atScr_Monitoring;

Scr_Monitoring::Scr_Monitoring()
{
    _Start_User     = *Start;
    _Execute_User   = *Execute;
    ID_Screen = 1;
	screen_status = ACTIVE;
    Name_Screen = (char*)"Monitoring Screen";
}
Scr_Monitoring::~Scr_Monitoring()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Scr_Monitoring::Start()
{
    //Write codes screen
	atScr_Monitoring.Object = lv_obj_create(NULL);
	//Create 4 button
	atScr_Monitoring.create_buttons(atScr_Monitoring.Object);
	//Write codes screen_1_label_1
	atScr_Monitoring.label_screen = lv_label_create(atScr_Monitoring.Object);
	atScr_Monitoring.setup_label(atScr_Monitoring.label_screen,"Monitoring.title",31,30,100,32);

	//create notified bar
	atScr_Monitoring.create_notified_bar(atScr_Monitoring.Object);

	atScr_Monitoring.render_modbus_icon(atScr_Monitoring.Screen_label_modbus,atScr_Monitoring.Notified_Bar_old_1.modbus_active,30,0);
	atScr_Monitoring.render_wifi_icon(atScr_Monitoring.Screen_label_wifi,atScr_Monitoring.Notified_Bar_old_1.wifi_active,0,0);
	atScr_Monitoring.render_SD_Card_icon(atScr_Monitoring.Screen_label_SD,atScr_Monitoring.Notified_Bar_old_1.SD_active,15,0);
	atScr_Monitoring.render_warning_icon(atScr_Monitoring.Screen_label_warning,atScr_Monitoring.Notified_Bar_old_1.warning_active,45,0);
	sprintf(atScr_Monitoring.char_time,"%d:%d",atScr_Monitoring.Notified_Bar_old_1.hour,atScr_Monitoring.Notified_Bar_old_1.minute);
	atScr_Monitoring.setup_label(atScr_Monitoring.Screen_label_time,atScr_Monitoring.char_time,120,0,40,15);
	
	// init every events
    lv_obj_add_event_cb(atScr_Monitoring.btn_OK, atScr_Monitoring.btn_OK_event_handler, LV_EVENT_ALL, NULL);
	atScr_Monitoring.screen_status = ACTIVE;
} 
/**
 * Execute fuction of SNM app
 */
void  Scr_Monitoring::Execute()
{
	atScr_Monitoring.Update();
}
void Scr_Monitoring :: btn_OK_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*atScr_Monitoring.Forward_Screen))
        {
			(*atScr_Monitoring.setup_Forward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*atScr_Monitoring.Forward_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			atScr_Monitoring.screen_status = DEACTIVE;
        }
	}
		break;
	default:
		break;
	}
}
void Scr_Monitoring::Update()
{
	if((atScr_Monitoring.Notified_Bar_old_1.hour != atScr_Monitoring.Notified_Bar_1.hour) || (atScr_Monitoring.Notified_Bar_old_1.minute != atScr_Monitoring.Notified_Bar_1.minute))
	{
		atScr_Monitoring.Notified_Bar_old_1.hour = atScr_Monitoring.Notified_Bar_1.hour;
		atScr_Monitoring.Notified_Bar_old_1.minute = atScr_Monitoring.Notified_Bar_1.minute;
		sprintf(atScr_Monitoring.char_time,"%d:%d",atScr_Monitoring.Notified_Bar_old_1.hour,atScr_Monitoring.Notified_Bar_old_1.minute);
		atScr_Monitoring.setup_label(atScr_Monitoring.Screen_label_time,atScr_Monitoring.char_time);
	}
	//check active wifi
	if(atScr_Monitoring.Notified_Bar_1.wifi_active != atScr_Monitoring.Notified_Bar_old_1.wifi_active)
	{
		atScr_Monitoring.Notified_Bar_old_1.wifi_active = atScr_Monitoring.Notified_Bar_1.wifi_active;
		atScr_Monitoring.render_wifi_icon(atScr_Monitoring.Screen_label_wifi,atScr_Monitoring.Notified_Bar_old_1.wifi_active);
	}
	//check active
	if (atScr_Monitoring.Notified_Bar_1.SD_active != atScr_Monitoring.Notified_Bar_old_1.SD_active)
	{
		atScr_Monitoring.Notified_Bar_old_1.SD_active = atScr_Monitoring.Notified_Bar_1.SD_active;
		atScr_Monitoring.render_SD_Card_icon(atScr_Monitoring.Screen_label_SD,atScr_Monitoring.Notified_Bar_old_1.SD_active);
	}
	//check active
	if (atScr_Monitoring.Notified_Bar_1.modbus_active != atScr_Monitoring.Notified_Bar_old_1.modbus_active)
	{
		atScr_Monitoring.Notified_Bar_old_1.modbus_active = atScr_Monitoring.Notified_Bar_1.modbus_active;
		atScr_Monitoring.render_modbus_icon(atScr_Monitoring.Screen_label_modbus,atScr_Monitoring.Notified_Bar_old_1.modbus_active);
	}	
	//check active
	if (atScr_Monitoring.Notified_Bar_1.warning_active != atScr_Monitoring.Notified_Bar_old_1.warning_active)
	{
		atScr_Monitoring.Notified_Bar_old_1.warning_active = atScr_Monitoring.Notified_Bar_1.warning_active;
		atScr_Monitoring.render_warning_icon(atScr_Monitoring.Screen_label_warning,atScr_Monitoring.Notified_Bar_old_1.warning_active);
	}
}
#endif