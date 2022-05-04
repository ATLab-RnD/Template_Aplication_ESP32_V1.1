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
#include"Sources.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____DEFINETIONS__________________________________________________________ */

/*____CLASS DEFINITION_____________________________________________________ */
/**
 * This Screen class is base class for implement another class by inheritance 
 */
class Scr_ABC: public Monitor_Screen , public Sources
{
public:
    Scr_ABC();
    ~Scr_ABC();
	static void  Screen_ABC_Start();	
	static void  Screen_ABC_Execute();

protected:
	void Update_Scr_ABC();

private:

    static void btn_OK_event_handler(lv_event_t *e);
    
}atScr_ABC;

Scr_ABC::Scr_ABC()
{
    _Start_User     = *Screen_ABC_Start;
    _Execute_User   = *Screen_ABC_Execute;
    ID_Screen = 1;
    Name_Screen = (char*)"Monitoring Screen";
}
Scr_ABC::~Scr_ABC()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Scr_ABC::Screen_ABC_Start()
{
    //Write codes screen
	atScr_ABC.Object = lv_obj_create(NULL);
	//Create 4 button
	atScr_ABC.create_button(atScr_ABC.Object);
	//Write codes screen_1_label_1
	atScr_ABC.label_screen = lv_label_create(atScr_ABC.Object);
	atScr_ABC.setup_label(atScr_ABC.label_screen,"abc.title",31,30,100,32);
	//create notified bar
	atScr_ABC.create_notified_bar(atScr_ABC.Object);
	atScr_ABC.setup_label(Screen_label_wifi,LV_SYMBOL_WIFI,0,0,15,15);
	// init every events
    lv_obj_add_event_cb(atScr_ABC.btn_OK, atScr_ABC.btn_OK_event_handler, LV_EVENT_ALL, NULL);
} 
/**
 * Execute fuction of SNM app
 */
void  Scr_ABC::Screen_ABC_Execute()
{
	atScr_ABC.Notified_Bar_1.minute++;
	sprintf(Notified_Bar_1.time, "%d:%d",Notified_Bar_1.hour,Notified_Bar_1.minute);
	atScr_ABC.setup_label(atScr_ABC.Screen_label_time,atScr_ABC.Notified_Bar_1.time,100,0,40,15);

void Scr_ABC :: btn_OK_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*atScr_ABC.Forward_Screen))
        {
			(*atScr_ABC.setup_Forward_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*atScr_ABC.Forward_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        }
	}
		break;
	default:
		break;
	}
}
void Scr_ABC::Update_Scr_ABC()
{
	if (atScr_ABC.Notified_Bar_1.minute < 60)
	{
		atScr_ABC.create_notified_bar(atScr_ABC.Object);
		atScr_ABC.Notified_Bar_1.minute ++;
	}
	else 
	{
		atScr_ABC.Notified_Bar_1.minute = 0;
		if(atScr_ABC.Notified_Bar_1.hour < 22)
			atScr_ABC.Notified_Bar_1.hour ++;
		else atScr_ABC.Notified_Bar_1.hour = 0;
		atScr_ABC.create_notified_bar(atScr_ABC.Object);
	}
}
#endif