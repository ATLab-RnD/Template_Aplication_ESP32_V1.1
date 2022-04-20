/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
// #include "events_init.h"



static void screen_1_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.screen))
			setup_scr_screen(&guider_ui);
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 100, 100, true);
	}
		break;
	default:
		break;
	}
}

void events_init_screen_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_1_btn_BACK, screen_1_btn_BACK_event_handler, LV_EVENT_ALL, NULL);
}
void setup_scr_screen_1(lv_ui *ui){

	//Write codes screen_1
	ui->screen_1 = lv_obj_create(NULL);

	//Write codes screen_1_btn_MENU
    ui->screen_1_btn_MENU = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_MENU,5,245,"MENU");
    //Write codes screen_1_btn_UP
    ui->screen_1_btn_UP = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_UP,85,245,"UP");
    //Write codes screen_1_btn_BACK
    ui->screen_1_btn_BACK= lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_BACK,45,245,"BACK");
    //Write codes screen_1_btn_DOWN
    ui->screen_1_btn_DOWN= lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_DOWN,125,245,"DOWN");
    //Write codes screen_1_btn_OK
    ui->screen_1_btn_OK = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_OK,165,245,"OK");
    //Write codes screen_btn_ALARM
    ui->screen_1_btn_ALARM = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_ALARM,205,245,"ALARM");

	//Write codes screen_1_label_2
	ui->screen_1_label_2 = lv_label_create(ui->screen_1);
	setup_label(ui->screen_1_label_2,"SCREEN 1",66,139,100,32);
	

	//Init events for screen
	events_init_screen_1(ui);
}