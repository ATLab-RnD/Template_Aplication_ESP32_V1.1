/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "Arduino.h"


static void screen_1_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.screen))
		{
			setup_scr_screen(&guider_ui);
			Serial.printf("setup screen done\n");
		}
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 100, 100, true);
			Serial.printf("vua an chuyen trang \n");
		}
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

	//Write style state: LV_STATE_DEFAULT for style_screen_1_main_main_default
	static lv_style_t style_screen_1_main_main_default;
	if (style_screen_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_main_main_default);
	else
		lv_style_init(&style_screen_1_main_main_default);
	lv_style_set_bg_color(&style_screen_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_1, &style_screen_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_btn_BACK
	ui->screen_1_btn_BACK = lv_btn_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_btn_BACK, 5, 85);
	lv_obj_set_size(ui->screen_1_btn_BACK, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_btn_BACK_main_main_default
	static lv_style_t style_screen_1_btn_BACK_main_main_default;
	if (style_screen_1_btn_BACK_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_btn_BACK_main_main_default);
	else
		lv_style_init(&style_screen_1_btn_BACK_main_main_default);
	lv_style_set_radius(&style_screen_1_btn_BACK_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_1_btn_BACK_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_1_btn_BACK_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_1_btn_BACK_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_1_btn_BACK_main_main_default, 255);
	lv_style_set_shadow_color(&style_screen_1_btn_BACK_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_1_btn_BACK_main_main_default, 255);
	lv_style_set_border_color(&style_screen_1_btn_BACK_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_1_btn_BACK_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_1_btn_BACK_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_btn_BACK, &style_screen_1_btn_BACK_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_1_btn_BACK_label = lv_label_create(ui->screen_1_btn_BACK);
	lv_label_set_text(ui->screen_1_btn_BACK_label, "Back");
	lv_obj_set_style_text_color(ui->screen_1_btn_BACK_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_btn_BACK_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_1_btn_BACK, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_1_btn_BACK_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_1_btn_UP
	ui->screen_1_btn_UP = lv_btn_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_btn_UP, 45, 85);
	lv_obj_set_size(ui->screen_1_btn_UP, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_btn_UP_main_main_default
	static lv_style_t style_screen_1_btn_UP_main_main_default;
	if (style_screen_1_btn_UP_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_btn_UP_main_main_default);
	else
		lv_style_init(&style_screen_1_btn_UP_main_main_default);
	lv_style_set_radius(&style_screen_1_btn_UP_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_1_btn_UP_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_1_btn_UP_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_1_btn_UP_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_1_btn_UP_main_main_default, 255);
	lv_style_set_shadow_color(&style_screen_1_btn_UP_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_1_btn_UP_main_main_default, 255);
	lv_style_set_border_color(&style_screen_1_btn_UP_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_1_btn_UP_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_1_btn_UP_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_btn_UP, &style_screen_1_btn_UP_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_1_btn_UP_label = lv_label_create(ui->screen_1_btn_UP);
	lv_label_set_text(ui->screen_1_btn_UP_label, "up");
	lv_obj_set_style_text_color(ui->screen_1_btn_UP_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_btn_UP_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_1_btn_UP, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_1_btn_UP_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_1_btn_DOWN
	ui->screen_1_btn_DOWN = lv_btn_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_btn_DOWN, 85, 85);
	lv_obj_set_size(ui->screen_1_btn_DOWN, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_btn_DOWN_main_main_default
	static lv_style_t style_screen_1_btn_DOWN_main_main_default;
	if (style_screen_1_btn_DOWN_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_btn_DOWN_main_main_default);
	else
		lv_style_init(&style_screen_1_btn_DOWN_main_main_default);
	lv_style_set_radius(&style_screen_1_btn_DOWN_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_1_btn_DOWN_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_1_btn_DOWN_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_1_btn_DOWN_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_1_btn_DOWN_main_main_default, 255);
	lv_style_set_shadow_color(&style_screen_1_btn_DOWN_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_1_btn_DOWN_main_main_default, 255);
	lv_style_set_border_color(&style_screen_1_btn_DOWN_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_1_btn_DOWN_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_1_btn_DOWN_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_btn_DOWN, &style_screen_1_btn_DOWN_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_1_btn_DOWN_label = lv_label_create(ui->screen_1_btn_DOWN);
	lv_label_set_text(ui->screen_1_btn_DOWN_label, "down");
	lv_obj_set_style_text_color(ui->screen_1_btn_DOWN_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_btn_DOWN_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_1_btn_DOWN, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_1_btn_DOWN_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_1_btn_OK
	ui->screen_1_btn_OK = lv_btn_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_btn_OK, 125, 85);
	lv_obj_set_size(ui->screen_1_btn_OK, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_btn_OK_main_main_default
	static lv_style_t style_screen_1_btn_OK_main_main_default;
	if (style_screen_1_btn_OK_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_btn_OK_main_main_default);
	else
		lv_style_init(&style_screen_1_btn_OK_main_main_default);
	lv_style_set_radius(&style_screen_1_btn_OK_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_1_btn_OK_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_1_btn_OK_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_1_btn_OK_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_1_btn_OK_main_main_default, 255);
	lv_style_set_shadow_color(&style_screen_1_btn_OK_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_1_btn_OK_main_main_default, 255);
	lv_style_set_border_color(&style_screen_1_btn_OK_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_1_btn_OK_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_1_btn_OK_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_btn_OK, &style_screen_1_btn_OK_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_1_btn_OK_label = lv_label_create(ui->screen_1_btn_OK);
	lv_label_set_text(ui->screen_1_btn_OK_label, "ok");
	lv_obj_set_style_text_color(ui->screen_1_btn_OK_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_btn_OK_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_1_btn_OK, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_1_btn_OK_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_1_label_1
	ui->screen_1_label_1 = lv_label_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_label_1, 31, 28);
	lv_obj_set_size(ui->screen_1_label_1, 100, 32);
	lv_label_set_text(ui->screen_1_label_1, "SCREEN 1");
	lv_label_set_long_mode(ui->screen_1_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_1_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_label_1_main_main_default
	static lv_style_t style_screen_1_label_1_main_main_default;
	if (style_screen_1_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_label_1_main_main_default);
	else
		lv_style_init(&style_screen_1_label_1_main_main_default);
	lv_style_set_radius(&style_screen_1_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_1_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_1_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_1_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_1_label_1_main_main_default, 133);
	lv_style_set_text_color(&style_screen_1_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_1_label_1_main_main_default, &lv_font_montserrat_12);
	lv_style_set_text_letter_space(&style_screen_1_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_1_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_1_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_1_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_1_label_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_1_label_1, &style_screen_1_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	Serial.printf("obj 1 created\n");	
	//Init events for screen
	events_init_screen_1(ui);
}