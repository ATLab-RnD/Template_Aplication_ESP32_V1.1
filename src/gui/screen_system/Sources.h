#ifndef SOURCES_H
#define SOURCES_H
#include "lvgl.h"
#include "Arduino.h"

// #ifndef HMI_Lite
// #define HMI_Lite
// #endif
enum ICON_ACTIVE
{
    
    ON = 1
};
typedef struct Notified_Bar
{
    int hour = 14, minute = 10;
    bool wifi_active        = ON;
    bool warning_active     = ON;
    bool SD_active          = ON;
    bool modbus_active      = ON;
};
typedef struct Notified_Bar_old
{
    bool wifi_active        = OFF;
    bool warning_active     = OFF;
    bool SD_active          = OFF;
    bool modbus_active      = OFF;
    int minute = 14;
    int hour = 10;
};

class Sources
{
public:
    
	int    get_roller_selected(lv_obj_t *roller);

    Notified_Bar Notified_Bar_1;
	lv_obj_t *roller_1;

protected:
    void   setup_button(lv_obj_t *button, int pos_x, int pos_y, char * button_label_str);
    char   char_time[10];

    lv_obj_t *Screen;
    
    lv_obj_t *Screen_label_wifi;
    lv_obj_t *Screen_label_warning;
    lv_obj_t *Screen_label_SD;
    lv_obj_t *Screen_label_modbus;
    lv_obj_t *Screen_label_time;

    lv_obj_t *btn_UP;
    lv_obj_t *btn_DOWN;
    lv_obj_t *btn_BACK;
    lv_obj_t *btn_OK;

    #ifdef HMI
    lv_obj_t *btn_MENU;
    lv_obj_t *btn_ALARM;
    #endif
    lv_obj_t *label_screen;

    Notified_Bar_old   Notified_Bar_old_1;
    
    

    void   setup_label(lv_obj_t *label, char* label_text,int pos_x, int pos_y, int width,int height);
    void   setup_label(lv_obj_t *label, char* label_text);
    void   setup_roller(lv_obj_t *roller, char* option,int row_count, int align,int width, int pos_x, int pos_y);
    void   setup_roller(lv_obj_t *roller, char* option);
    void   create_notified_bar  (lv_obj_t *screen);

    void   render_modbus_icon(lv_obj_t *icon_label, bool icon_active, int pos_x,int pos_y);
    void   render_modbus_icon(lv_obj_t *icon_label, bool icon_active);

    void   render_SD_Card_icon(lv_obj_t *icon_label, bool icon_active, int pos_x,int pos_y);
    void   render_SD_Card_icon(lv_obj_t *icon_label, bool icon_active);

    void   render_wifi_icon(lv_obj_t *icon_label, bool icon_active, int pos_x,int pos_y);
    void   render_wifi_icon(lv_obj_t *icon_label, bool icon_active);

    void   render_warning_icon(lv_obj_t *icon_label, bool icon_active, int pos_x,int pos_y);
    void   render_warning_icon(lv_obj_t *icon_label, bool icon_active);

    void   render_time(lv_obj_t *icon_label, char* label, int pos_x,int pos_y);
    void   render_time(lv_obj_t *icon_label, char* label);

    void   create_buttons(lv_obj_t *object);


    

private:
    /* data */

};
void Sources::setup_button( lv_obj_t *button,int pos_x, int pos_y, char * button_label_str)
{
    lv_obj_set_pos(button, pos_x, pos_y);
	lv_obj_set_size(button, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn
	static lv_style_t style_button ;
	if (style_button.prop_cnt > 1)
		lv_style_reset(&style_button);
	else
		lv_style_init(&style_button);
    // lv_style_set_radius(&style_button, 5);
    // lv_style_set_bg_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
    // lv_style_set_bg_grad_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
    // lv_style_set_bg_grad_dir(&style_button, LV_GRAD_DIR_VER);
    // lv_style_set_bg_opa(&style_button, 255);
    // lv_style_set_shadow_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
    // lv_style_set_shadow_opa(&style_button, 255);
    // lv_style_set_border_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
    // lv_style_set_border_width(&style_button, 0);
    // lv_style_set_border_opa(&style_button, 255);
    // lv_obj_add_style(button, &style_button, LV_PART_MAIN|LV_STATE_DEFAULT);

	lv_obj_t *btn_label;
	btn_label = lv_label_create(button);
    lv_label_set_text(btn_label, button_label_str);
    // lv_obj_set_style_text_color(btn_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_all(button, 0, LV_STATE_DEFAULT);
    lv_obj_align(btn_label, LV_ALIGN_CENTER, 0, 0);
}

void Sources::setup_label(lv_obj_t *label, char* label_text,int pos_x, int pos_y, int width,int height)
{
	lv_obj_set_pos(label, pos_x, pos_y);
	lv_obj_set_size(label, width, height);
	lv_label_set_text(label, label_text);
	lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
}
void Sources::setup_label(lv_obj_t *label, char* label_text)
{
	lv_label_set_text(label, label_text);
	lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
}
void Sources::setup_roller(lv_obj_t *roller, char* option,int row_count, int align,int width, int pos_x, int pos_y)
{
	lv_roller_set_options(roller, option, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller, row_count);
    lv_obj_set_width(roller, width);
	lv_obj_align(roller, align, pos_x, pos_y);
}
void Sources::setup_roller(lv_obj_t *roller, char* option)
{
	lv_roller_set_options(roller, option, LV_ROLLER_MODE_NORMAL);
}

/*
Create notified bar for screen: icon wifi, bluetooth, warning, modbus active, SD Card, time
*/
void   Sources::create_notified_bar(lv_obj_t *screen)
{

	//create font wifi
	Screen_label_wifi = lv_label_create(screen);
	//create font warning
	Screen_label_warning = lv_label_create(screen);
	//create font modbus
	Screen_label_modbus = lv_label_create(screen);
	//create font SD
	Screen_label_SD = lv_label_create(screen);
	//create label time
	Screen_label_time = lv_label_create(screen);  
	// setup_label(Screen_label_modbus,".",45,0,15,15);
	// setup_label(Screen_label_warning,".",60,0,15,15);
	// setup_label(Screen_label_SD,".",30,0,15,15);
	// setup_label(Screen_label_bluetooth,".",15,0,15,15);
	// setup_label(Screen_label_wifi,".",0,0,15,15);

}
void   Sources::render_modbus_icon(lv_obj_t *icon_label, bool icon_active, int pos_x,int pos_y)
{
    if(icon_active == ON)
	{
		setup_label(icon_label,LV_SYMBOL_REFRESH, pos_x,pos_y,15,15);
	}
	else setup_label(icon_label,"  ",pos_x,pos_y,15,15);
}
void   Sources::render_modbus_icon(lv_obj_t *icon_label, bool icon_active)
{
    if(icon_active == ON)
	{
		setup_label(icon_label,LV_SYMBOL_REFRESH);
	}
	else setup_label(icon_label,"  ");
}
void   Sources::render_SD_Card_icon(lv_obj_t *icon_label, bool icon_active, int pos_x,int pos_y)
{
    if(icon_active == ON)
	{
		setup_label(icon_label,LV_SYMBOL_SD_CARD, pos_x,pos_y,15,15);
	}
	else setup_label(icon_label,"  ",pos_x,pos_y,15,15);
}
void   Sources::render_SD_Card_icon(lv_obj_t *icon_label, bool icon_active)
{
    if(icon_active == ON)
	{
		setup_label(icon_label,LV_SYMBOL_SD_CARD);
	}
	else setup_label(icon_label,"  ");
}
void   Sources::render_wifi_icon(lv_obj_t *icon_label, bool icon_active, int pos_x,int pos_y)
{
    if(icon_active == ON)
	{
		setup_label(icon_label,LV_SYMBOL_WIFI, pos_x,pos_y,15,15);
	}
	else setup_label(icon_label,"  ",pos_x,pos_y,15,15);
}
void   Sources::render_wifi_icon(lv_obj_t *icon_label, bool icon_active)
{
    if(icon_active == ON)
	{
		setup_label(icon_label,LV_SYMBOL_WIFI);
	}
	else setup_label(icon_label,"  ");
}
void   Sources::render_warning_icon(lv_obj_t *icon_label, bool icon_active, int pos_x,int pos_y)
{
    if(icon_active == ON)
	{
		setup_label(icon_label,LV_SYMBOL_WARNING, pos_x,pos_y,15,15);
	}
	else setup_label(icon_label,"  ",pos_x,pos_y,15,15);
}
void   Sources::render_warning_icon(lv_obj_t *icon_label, bool icon_active)
{
    if(icon_active == ON)
	{
		setup_label(icon_label,LV_SYMBOL_WARNING);
	}
	else setup_label(icon_label,"  ");
}
void   Sources::render_time(lv_obj_t *icon_label, char* label, int pos_x,int pos_y)
{
    setup_label(icon_label,label,pos_x,pos_y,40,15);
}
void   Sources::render_time(lv_obj_t *icon_label, char* label)
{
    setup_label(icon_label,label);
}
int    Sources::get_roller_selected(lv_obj_t *roller)
{
    return lv_roller_get_selected(roller);
}
void   Sources::create_buttons(lv_obj_t *Object)
{
#ifdef HMI_Lite
    btn_BACK= lv_btn_create(Object);
    setup_button(btn_BACK,5,85,"BACK");
	//Write codes screen_btn_UP
	btn_UP = lv_btn_create(Object);
	setup_button(btn_UP,45,85,"UP");
	//Write codes screen_btn_DOWN
	btn_DOWN = lv_btn_create(Object);
	setup_button(btn_DOWN,85,85,"DOWN");
	//Write codes screen_btn_OK
	btn_OK = lv_btn_create(Object);
	setup_button(btn_OK,125,85,"OK");
#endif
#ifdef HMI
    btn_MENU = lv_btn_create(Object);
    setup_button(btn_MENU,5,245,"MENU");
    //Write codesbtn_UP
    btn_UP = lv_btn_create(Object);
    setup_button(btn_UP,85,245,"UP");
    //Write codesbtn_BACK
    btn_BACK= lv_btn_create(Object);
    setup_button(btn_BACK,45,245,"BACK");
    //Write codesbtn_DOWN
    btn_DOWN= lv_btn_create(Object);
    setup_button(btn_DOWN,125,245,"DOWN");
    //Write codesbtn_OK
    btn_OK = lv_btn_create(Object);
    setup_button(btn_OK,165,245,"OK");
    //Write codesbtn_ALARM
    btn_ALARM = lv_btn_create(Object);
    setup_button(btn_ALARM,205,245,"ALARM");
#endif
}
#endif
