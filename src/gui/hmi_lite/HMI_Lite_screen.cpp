/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "../general/gui_guider.h"

int temperature = 23, humidity = 75;
int hour = 14, minute = 10;
char Option[100]="Connection\nMeasure\nLog Data\nFault & Alarm\nOthers\nDebug\nAbout";
char time[10], information[100];


static void screen_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.screen_1))
			setup_scr_screen_1(&guider_ui);
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.screen_1, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 100, true);
	}
		break;
	default:
		break;
	}
}
static void screen_btn_UP_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(guider_ui.screen_roller);
		roller_selected++;
		lv_roller_set_selected(guider_ui.screen_roller,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
static void screen_btn_DOWN_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(guider_ui.screen_roller);
		roller_selected--;
		lv_roller_set_selected(guider_ui.screen_roller,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_btn_OK, screen_btn_OK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_UP, screen_btn_UP_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_DOWN, screen_btn_DOWN_event_handler, LV_EVENT_ALL, NULL);
}

void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	//Create 4 button
		//Write codes screen_btn_BACK
		ui->screen_btn_BACK= lv_btn_create(ui->screen);
		setup_button(ui->screen_btn_BACK,5,85,"BACK");
		//Write codes screen_btn_UP
		ui->screen_btn_UP = lv_btn_create(ui->screen);
		setup_button(ui->screen_btn_UP,45,85,"UP");
		//Write codes screen_btn_DOWN
		ui->screen_btn_DOWN = lv_btn_create(ui->screen);
		setup_button(ui->screen_btn_DOWN,85,85,"DOWN");
		//Write codes screen_btn_OK
		ui->screen_btn_OK = lv_btn_create(ui->screen);
		setup_button(ui->screen_btn_OK,125,85,"OK");

	//create notified obj
		ui->screen_notified_obj = lv_obj_create(ui->screen);
		lv_obj_set_pos(ui->screen_notified_obj, 0, 0);
		lv_obj_set_size(ui->screen_notified_obj, 160, 20);
		//create font wifi
		ui->screen_label_wifi = lv_label_create(ui->screen_notified_obj);
		setup_label(ui->screen_label_wifi,"wifi",-10,-15,15,15);
		lv_label_set_text(ui->screen_label_wifi,LV_SYMBOL_WIFI);
		//create font bluetooth
		ui->screen_label_bluetooth = lv_label_create(ui->screen_notified_obj);
		setup_label(ui->screen_label_bluetooth,"bluetooth",5,-15,15,15);
		lv_label_set_text(ui->screen_label_bluetooth,LV_SYMBOL_BLUETOOTH);
		//create font warning
		ui->screen_label_warning = lv_label_create(ui->screen_notified_obj);
		setup_label(ui->screen_label_warning,"warning",20,-15,15,15);
		lv_label_set_text(ui->screen_label_warning,LV_SYMBOL_WARNING);
		//create font modbus_active
		ui->screen_label_modbus_active = lv_label_create(ui->screen_notified_obj);
		setup_label(ui->screen_label_modbus_active,"modbus_active",50,-15,15,15);
		lv_label_set_text(ui->screen_label_modbus_active,LV_SYMBOL_REFRESH);
		//create font SD
		ui->screen_label_SD = lv_label_create(ui->screen_notified_obj);
		setup_label(ui->screen_label_SD,"SD Card",37,-15,10,15);
		lv_label_set_text(ui->screen_label_SD,LV_SYMBOL_SD_CARD);
		//create label time
		ui->screen_label_time = lv_label_create(ui->screen_notified_obj);
		sprintf(time, "%d:%d",hour,minute);
		setup_label(ui->screen_label_time, time,90,-15,40,15); 
	//create roller home
	ui->screen_roller = lv_roller_create(ui->screen);
	setup_roller(ui->screen_roller,Option,2,LV_ALIGN_CENTER,100,0,5);
	events_init_screen(ui);
}