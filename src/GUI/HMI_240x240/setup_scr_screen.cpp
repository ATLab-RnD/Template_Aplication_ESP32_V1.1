/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


static void screen_btn_UP_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_led_1, lv_color_make(255, 250, 0), LV_PART_MAIN);
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
		lv_obj_set_style_bg_color(guider_ui.screen_led_1, lv_color_make(225, 0x00, 255), LV_PART_MAIN);//pink
	}
		break;
	default:
		break;
	}
}

static void screen_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_led_2, lv_color_make(181, 245, 9), LV_PART_MAIN);//blue
	}
		break;
	default:
		break;
	}
}

static void screen_btn_ALARM_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_led_2, lv_color_make(249, 6, 6), LV_PART_MAIN); //red
	}
		break;
	default:
		break;
	}
}

static void screen_btn_MENU_event_handler(lv_event_t *e)
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

void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_btn_UP, screen_btn_UP_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_DOWN, screen_btn_DOWN_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_OK, screen_btn_OK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_ALARM, screen_btn_ALARM_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_MENU, screen_btn_MENU_event_handler, LV_EVENT_ALL, NULL);
}
void setup_scr_screen(lv_ui *ui){

	//Write codes screen
    ui->screen = lv_obj_create(NULL);

    //Write codes screen_btn_MENU
    ui->screen_btn_MENU = lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_MENU,5,245,"MENU");
    //Write codes screen_btn_UP
    ui->screen_btn_UP = lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_UP,85,245,"UP");
    //Write codes screen_btn_BACK
    ui->screen_btn_BACK= lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_BACK,45,245,"BACK");
    //Write codes screen_btn_DOWN
    ui->screen_btn_DOWN= lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_DOWN,125,245,"DOWN");
    //Write codes screen_btn_OK
    ui->screen_btn_OK = lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_OK,165,245,"OK");
    //Write codes screen_btn_ALARM
    ui->screen_btn_ALARM = lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_ALARM,205,245,"ALARM");

    //Write codes screen_label_2
    ui->screen_label_1 = lv_label_create(ui->screen);
    setup_label(ui->screen_label_1,"SCREEN",66,139,100,32);

	//Write codes screen_led_1
	ui->screen_led_1 = lv_led_create(ui->screen);
	lv_obj_set_pos(ui->screen_led_1, 50, 48);
	lv_obj_set_size(ui->screen_led_1, 40, 40);
	lv_led_set_brightness(ui->screen_led_1, 255);
	lv_led_on(ui->screen_led_1);
	lv_led_set_color(ui->screen_led_1, lv_color_make(225, 255, 0x00));

	//Write codes screen_led_2
	ui->screen_led_2 = lv_led_create(ui->screen);
	lv_obj_set_pos(ui->screen_led_2, 134, 47);
	lv_obj_set_size(ui->screen_led_2, 40, 40);
	lv_led_set_brightness(ui->screen_led_2, 255);
	lv_led_on(ui->screen_led_2);
	lv_led_set_color(ui->screen_led_2, lv_color_make(255, 0, 0));


	//Init events for screen
	events_init_screen(ui);
}
