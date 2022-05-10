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
#ifndef _atScr_Menu_
#define _atScr_Menu_
/* _____PROJECT INCLUDES____________________________________________________ */

#include "Arduino.h"
#include "lvgl.h"
#include "../Menu_Screen.h"
// #include "../Sources.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____DEFINETIONS__________________________________________________________ */
enum ROLLER_OPTION
{
	Detail_1,
	Detail_2,
	Detail_3
};

/*____CLASS DEFINITION_____________________________________________________ */
/**
 * This Screen class is base class for implement another class by inheritance 
 */
class Scr_Menu: public Menu_Screen, public Sources
{
public:
    Scr_Menu();
    ~Scr_Menu();
	static void  Start();	
	static void  Execute();
	
protected:    
	void Update();
	char Option[100]="Detail_1\nDetail_2\nDetail_3";
	uint8_t hour;
	uint8_t minute;
	// static Roller Roller_1;
private:
    static void btn_Back_event_handler(lv_event_t *e);
    static void btn_OK_event_handler(lv_event_t *e);
	static void btn_UP_event_handler(lv_event_t *e);
	static void btn_DOWN_event_handler(lv_event_t *e);

    
}atScr_Menu;

Scr_Menu::Scr_Menu()
{
    _Start_User     = *Start;
    _Execute_User   = *Execute;
    ID_Screen = 2;
	screen_status = DEACTIVE;
    Name_Screen = (char*)"Menu Screen";

}
Scr_Menu::~Scr_Menu()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Scr_Menu::Start()
{
    //Write codes screen
	atScr_Menu.Object = lv_obj_create(NULL);
	//Create 4 button
	atScr_Menu.create_buttons(atScr_Menu.Object);
	// //Write codes screen_1_label_1
	// atScr_Menu.label_screen = lv_label_create(atScr_Menu.Object);
	// atScr_Menu.setup_label(atScr_Menu.label_screen,"Menu.title",31,30,100,32);
	//create notified bar
	atScr_Menu.create_notified_bar(atScr_Menu.Object);
	atScr_Menu.render_modbus_icon(atScr_Menu.Screen_label_modbus,atScr_Menu.Value_old_1.modbus_active,30,0);
	atScr_Menu.render_wifi_icon(atScr_Menu.Screen_label_wifi,atScr_Menu.Value_old_1.wifi_active,0,0);
	atScr_Menu.render_SD_Card_icon(atScr_Menu.Screen_label_SD,atScr_Menu.Value_old_1.SD_active,15,0);
	atScr_Menu.render_warning_icon(atScr_Menu.Screen_label_warning,atScr_Menu.Value_old_1.warning_active,45,0);
	sprintf(atScr_Menu.Value_old_1.time,"%d:%d",atScr_Menu.Value_old_1.hour,atScr_Menu.Value_old_1.minute);
	atScr_Menu.setup_label(atScr_Menu.Screen_label_time,atScr_Menu.Value_old_1.time,120,0,40,15);
	//Menu_Screen_roller = lv_roller_create(Menu_Screen);
	atScr_Menu.roller_1 = lv_roller_create(atScr_Menu.Object);
	atScr_Menu.setup_roller(atScr_Menu.roller_1,atScr_Menu.Option,2,LV_ALIGN_CENTER,100,0,5);
	// init every events
    lv_obj_add_event_cb(atScr_Menu.btn_BACK, atScr_Menu.btn_Back_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(atScr_Menu.btn_OK, atScr_Menu.btn_OK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(atScr_Menu.btn_UP, atScr_Menu.btn_UP_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(atScr_Menu.btn_DOWN, atScr_Menu.btn_DOWN_event_handler, LV_EVENT_ALL, NULL);
	atScr_Menu.screen_status = ACTIVE;

} 
/**
 * Execute fuction of SNM app
 */
void  Scr_Menu::Execute()
{
	atScr_Menu.Update();
}

void Scr_Menu::btn_Back_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*atScr_Menu.Backward_Screen))
        {
			(*atScr_Menu.setup_Backward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*atScr_Menu.Backward_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			atScr_Menu.screen_status = DEACTIVE;
        }
	}
		break;
	default:
		break;
	}
}
void Scr_Menu:: btn_OK_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*atScr_Menu.Forward_Screen))
        {
			(*atScr_Menu.setup_Forward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*atScr_Menu.Forward_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			atScr_Menu.screen_status = DEACTIVE;
        }
	}
		break;
	default:
		break;
	}
}
void Scr_Menu::btn_DOWN_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(atScr_Menu.roller_1);
		roller_selected++;
		lv_roller_set_selected(atScr_Menu.roller_1,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
void Scr_Menu::btn_UP_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(atScr_Menu.roller_1);
		roller_selected--;
		lv_roller_set_selected(atScr_Menu.roller_1,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
void Scr_Menu::Update()
{

	if((atScr_Menu.Value_old_1.hour != atScr_Menu.Notified_Bar_1.hour) || (atScr_Menu.Value_old_1.minute != atScr_Menu.Notified_Bar_1.minute))
	{

		sprintf(atScr_Menu.Value_old_1.time,"%d:%d",atScr_Menu.Value_old_1.hour,atScr_Menu.Value_old_1.minute);
		atScr_Menu.setup_label(atScr_Menu.Screen_label_time,atScr_Menu.Value_old_1.time);
	}
	//check active wifi
	if(atScr_Menu.Notified_Bar_1.wifi_active != atScr_Menu.Value_old_1.wifi_active)
	{
		atScr_Menu.Value_old_1.wifi_active = atScr_Menu.Notified_Bar_1.wifi_active;
		atScr_Menu.render_wifi_icon(atScr_Menu.Screen_label_wifi,atScr_Menu.Value_old_1.wifi_active);
	}
	//check active
	if (atScr_Menu.Notified_Bar_1.SD_active != atScr_Menu.Value_old_1.SD_active)
	{
		atScr_Menu.Value_old_1.SD_active = atScr_Menu.Notified_Bar_1.SD_active;
		atScr_Menu.render_SD_Card_icon(atScr_Menu.Screen_label_SD,atScr_Menu.Value_old_1.SD_active);
	}
	//check active
	if (atScr_Menu.Notified_Bar_1.modbus_active != atScr_Menu.Value_old_1.modbus_active)
	{
		atScr_Menu.Value_old_1.modbus_active = atScr_Menu.Notified_Bar_1.modbus_active;
		atScr_Menu.render_modbus_icon(atScr_Menu.Screen_label_modbus,atScr_Menu.Value_old_1.modbus_active);
	}	
	//check active
	if (atScr_Menu.Notified_Bar_1.warning_active != atScr_Menu.Value_old_1.warning_active)
	{
		atScr_Menu.Value_old_1.warning_active = atScr_Menu.Notified_Bar_1.warning_active;
		atScr_Menu.render_warning_icon(atScr_Menu.Screen_label_warning,atScr_Menu.Value_old_1.warning_active);
	}
}
#endif