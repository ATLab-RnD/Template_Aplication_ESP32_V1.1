/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


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

	//Write codes screen_1_btn_7
	ui->screen_1_btn_7 = lv_btn_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_btn_7, 5, 245);
	lv_obj_set_size(ui->screen_1_btn_7, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_btn_7_main_main_default
	static lv_style_t style_screen_1_btn_7_main_main_default;
	if (style_screen_1_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_btn_7_main_main_default);
	else
		lv_style_init(&style_screen_1_btn_7_main_main_default);
	lv_style_set_radius(&style_screen_1_btn_7_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_1_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_1_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_1_btn_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_1_btn_7_main_main_default, 255);
	lv_style_set_shadow_color(&style_screen_1_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_1_btn_7_main_main_default, 255);
	lv_style_set_border_color(&style_screen_1_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_1_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_1_btn_7_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_btn_7, &style_screen_1_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_1_btn_7_label = lv_label_create(ui->screen_1_btn_7);
	lv_label_set_text(ui->screen_1_btn_7_label, "manu");
	lv_obj_set_style_text_color(ui->screen_1_btn_7_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_btn_7_label, &lv_font_montserrat_12, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_1_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_1_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	// //Write codes screen_1_btn_8
	// ui->screen_1_btn_8 = lv_btn_create(ui->screen_1);
	// lv_obj_set_pos(ui->screen_1_btn_8, 85, 245);
	// lv_obj_set_size(ui->screen_1_btn_8, 30, 15);

	// //Write style state: LV_STATE_DEFAULT for style_screen_1_btn_8_main_main_default
	// static lv_style_t style_screen_1_btn_8_main_main_default;
	// if (style_screen_1_btn_8_main_main_default.prop_cnt > 1)
	// 	lv_style_reset(&style_screen_1_btn_8_main_main_default);
	// else
	// 	lv_style_init(&style_screen_1_btn_8_main_main_default);
	// lv_style_set_radius(&style_screen_1_btn_8_main_main_default, 5);
	// lv_style_set_bg_color(&style_screen_1_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_color(&style_screen_1_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_dir(&style_screen_1_btn_8_main_main_default, LV_GRAD_DIR_VER);
	// lv_style_set_bg_opa(&style_screen_1_btn_8_main_main_default, 255);
	// lv_style_set_shadow_color(&style_screen_1_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_shadow_opa(&style_screen_1_btn_8_main_main_default, 255);
	// lv_style_set_border_color(&style_screen_1_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_border_width(&style_screen_1_btn_8_main_main_default, 0);
	// lv_style_set_border_opa(&style_screen_1_btn_8_main_main_default, 255);
	// lv_obj_add_style(ui->screen_1_btn_8, &style_screen_1_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	// ui->screen_1_btn_8_label = lv_label_create(ui->screen_1_btn_8);
	// lv_label_set_text(ui->screen_1_btn_8_label, "up");
	// lv_obj_set_style_text_color(ui->screen_1_btn_8_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	// lv_obj_set_style_text_font(ui->screen_1_btn_8_label, &lv_font_montserrat_12, LV_STATE_DEFAULT);
	// lv_obj_set_style_pad_all(ui->screen_1_btn_8, 0, LV_STATE_DEFAULT);
	// lv_obj_align(ui->screen_1_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	// //Write codes screen_1_btn_9
	// ui->screen_1_btn_9 = lv_btn_create(ui->screen_1);
	// lv_obj_set_pos(ui->screen_1_btn_9, 45, 245);
	// lv_obj_set_size(ui->screen_1_btn_9, 30, 15);

	// //Write style state: LV_STATE_DEFAULT for style_screen_1_btn_9_main_main_default
	// static lv_style_t style_screen_1_btn_9_main_main_default;
	// if (style_screen_1_btn_9_main_main_default.prop_cnt > 1)
	// 	lv_style_reset(&style_screen_1_btn_9_main_main_default);
	// else
	// 	lv_style_init(&style_screen_1_btn_9_main_main_default);
	// lv_style_set_radius(&style_screen_1_btn_9_main_main_default, 5);
	// lv_style_set_bg_color(&style_screen_1_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_color(&style_screen_1_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_dir(&style_screen_1_btn_9_main_main_default, LV_GRAD_DIR_VER);
	// lv_style_set_bg_opa(&style_screen_1_btn_9_main_main_default, 255);
	// lv_style_set_shadow_color(&style_screen_1_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_shadow_opa(&style_screen_1_btn_9_main_main_default, 255);
	// lv_style_set_border_color(&style_screen_1_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_border_width(&style_screen_1_btn_9_main_main_default, 0);
	// lv_style_set_border_opa(&style_screen_1_btn_9_main_main_default, 255);
	// lv_obj_add_style(ui->screen_1_btn_9, &style_screen_1_btn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	// ui->screen_1_btn_9_label = lv_label_create(ui->screen_1_btn_9);
	// lv_label_set_text(ui->screen_1_btn_9_label, "back");
	// lv_obj_set_style_text_color(ui->screen_1_btn_9_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	// lv_obj_set_style_text_font(ui->screen_1_btn_9_label, &lv_font_montserrat_12, LV_STATE_DEFAULT);
	// lv_obj_set_style_pad_all(ui->screen_1_btn_9, 0, LV_STATE_DEFAULT);
	// lv_obj_align(ui->screen_1_btn_9_label, LV_ALIGN_CENTER, 0, 0);

	// //Write codes screen_1_btn10
	// ui->screen_1_btn10 = lv_btn_create(ui->screen_1);
	// lv_obj_set_pos(ui->screen_1_btn10, 125, 245);
	// lv_obj_set_size(ui->screen_1_btn10, 30, 15);

	// //Write style state: LV_STATE_DEFAULT for style_screen_1_btn10_main_main_default
	// static lv_style_t style_screen_1_btn10_main_main_default;
	// if (style_screen_1_btn10_main_main_default.prop_cnt > 1)
	// 	lv_style_reset(&style_screen_1_btn10_main_main_default);
	// else
	// 	lv_style_init(&style_screen_1_btn10_main_main_default);
	// lv_style_set_radius(&style_screen_1_btn10_main_main_default, 5);
	// lv_style_set_bg_color(&style_screen_1_btn10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_color(&style_screen_1_btn10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_dir(&style_screen_1_btn10_main_main_default, LV_GRAD_DIR_VER);
	// lv_style_set_bg_opa(&style_screen_1_btn10_main_main_default, 255);
	// lv_style_set_shadow_color(&style_screen_1_btn10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_shadow_opa(&style_screen_1_btn10_main_main_default, 255);
	// lv_style_set_border_color(&style_screen_1_btn10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_border_width(&style_screen_1_btn10_main_main_default, 0);
	// lv_style_set_border_opa(&style_screen_1_btn10_main_main_default, 255);
	// lv_obj_add_style(ui->screen_1_btn10, &style_screen_1_btn10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	// ui->screen_1_btn10_label = lv_label_create(ui->screen_1_btn10);
	// lv_label_set_text(ui->screen_1_btn10_label, "down");
	// lv_obj_set_style_text_color(ui->screen_1_btn10_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	// lv_obj_set_style_text_font(ui->screen_1_btn10_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
	// lv_obj_set_style_pad_all(ui->screen_1_btn10, 0, LV_STATE_DEFAULT);
	// lv_obj_align(ui->screen_1_btn10_label, LV_ALIGN_CENTER, 0, 0);

	// //Write codes screen_1_btn_11
	// ui->screen_1_btn_11 = lv_btn_create(ui->screen_1);
	// lv_obj_set_pos(ui->screen_1_btn_11, 165, 245);
	// lv_obj_set_size(ui->screen_1_btn_11, 30, 15);

	// //Write style state: LV_STATE_DEFAULT for style_screen_1_btn_11_main_main_default
	// static lv_style_t style_screen_1_btn_11_main_main_default;
	// if (style_screen_1_btn_11_main_main_default.prop_cnt > 1)
	// 	lv_style_reset(&style_screen_1_btn_11_main_main_default);
	// else
	// 	lv_style_init(&style_screen_1_btn_11_main_main_default);
	// lv_style_set_radius(&style_screen_1_btn_11_main_main_default, 5);
	// lv_style_set_bg_color(&style_screen_1_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_color(&style_screen_1_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_dir(&style_screen_1_btn_11_main_main_default, LV_GRAD_DIR_VER);
	// lv_style_set_bg_opa(&style_screen_1_btn_11_main_main_default, 255);
	// lv_style_set_shadow_color(&style_screen_1_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_shadow_opa(&style_screen_1_btn_11_main_main_default, 255);
	// lv_style_set_border_color(&style_screen_1_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_border_width(&style_screen_1_btn_11_main_main_default, 0);
	// lv_style_set_border_opa(&style_screen_1_btn_11_main_main_default, 255);
	// lv_obj_add_style(ui->screen_1_btn_11, &style_screen_1_btn_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	// ui->screen_1_btn_11_label = lv_label_create(ui->screen_1_btn_11);
	// lv_label_set_text(ui->screen_1_btn_11_label, "ok");
	// lv_obj_set_style_text_color(ui->screen_1_btn_11_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	// lv_obj_set_style_text_font(ui->screen_1_btn_11_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
	// lv_obj_set_style_pad_all(ui->screen_1_btn_11, 0, LV_STATE_DEFAULT);
	// lv_obj_align(ui->screen_1_btn_11_label, LV_ALIGN_CENTER, 0, 0);

	// //Write codes screen_1_btn_12
	// ui->screen_1_btn_12 = lv_btn_create(ui->screen_1);
	// lv_obj_set_pos(ui->screen_1_btn_12, 205, 245);
	// lv_obj_set_size(ui->screen_1_btn_12, 30, 15);

	// //Write style state: LV_STATE_DEFAULT for style_screen_1_btn_12_main_main_default
	// static lv_style_t style_screen_1_btn_12_main_main_default;
	// if (style_screen_1_btn_12_main_main_default.prop_cnt > 1)
	// 	lv_style_reset(&style_screen_1_btn_12_main_main_default);
	// else
	// 	lv_style_init(&style_screen_1_btn_12_main_main_default);
	// lv_style_set_radius(&style_screen_1_btn_12_main_main_default, 5);
	// lv_style_set_bg_color(&style_screen_1_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_color(&style_screen_1_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_dir(&style_screen_1_btn_12_main_main_default, LV_GRAD_DIR_VER);
	// lv_style_set_bg_opa(&style_screen_1_btn_12_main_main_default, 255);
	// lv_style_set_shadow_color(&style_screen_1_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_shadow_opa(&style_screen_1_btn_12_main_main_default, 255);
	// lv_style_set_border_color(&style_screen_1_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_border_width(&style_screen_1_btn_12_main_main_default, 0);
	// lv_style_set_border_opa(&style_screen_1_btn_12_main_main_default, 255);
	// lv_obj_add_style(ui->screen_1_btn_12, &style_screen_1_btn_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	// ui->screen_1_btn_12_label = lv_label_create(ui->screen_1_btn_12);
	// lv_label_set_text(ui->screen_1_btn_12_label, "alarm");
	// lv_obj_set_style_text_color(ui->screen_1_btn_12_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	// lv_obj_set_style_text_font(ui->screen_1_btn_12_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
	// lv_obj_set_style_pad_all(ui->screen_1_btn_12, 0, LV_STATE_DEFAULT);
	// lv_obj_align(ui->screen_1_btn_12_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_1_label_2
	ui->screen_1_label_2 = lv_label_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_label_2, 66, 139);
	lv_obj_set_size(ui->screen_1_label_2, 100, 32);
	lv_label_set_text(ui->screen_1_label_2, "screen 1");
	lv_label_set_long_mode(ui->screen_1_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_1_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_label_2_main_main_default
	static lv_style_t style_screen_1_label_2_main_main_default;
	if (style_screen_1_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_label_2_main_main_default);
	else
		lv_style_init(&style_screen_1_label_2_main_main_default);
	lv_style_set_radius(&style_screen_1_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_1_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_1_label_2_main_main_default, lv_color_make(0x9b, 0xff, 0x05));
	lv_style_set_bg_grad_dir(&style_screen_1_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_1_label_2_main_main_default, 190);
	lv_style_set_text_color(&style_screen_1_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_1_label_2_main_main_default, &lv_font_montserrat_12);
	lv_style_set_text_letter_space(&style_screen_1_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_1_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_1_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_1_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_1_label_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_1_label_2, &style_screen_1_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_screen_1(ui);
}