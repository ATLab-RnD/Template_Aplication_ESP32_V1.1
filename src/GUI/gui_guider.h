/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_btn_3;
	lv_obj_t *screen_btn_3_label;
	lv_obj_t *screen_btn_2;
	lv_obj_t *screen_btn_2_label;
	lv_obj_t *screen_btn_4;
	lv_obj_t *screen_btn_4_label;
	lv_obj_t *screen_btn_5;
	lv_obj_t *screen_btn_5_label;
	lv_obj_t *screen_btn_6;
	lv_obj_t *screen_btn_6_label;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_led_1;
	lv_obj_t *screen_led_2;
	lv_obj_t *screen_btn_1;
	lv_obj_t *screen_btn_1_label;
	lv_obj_t *screen_1;
	lv_obj_t *screen_1_btn_7;
	lv_obj_t *screen_1_btn_7_label;
	lv_obj_t *screen_1_btn_8;
	lv_obj_t *screen_1_btn_8_label;
	lv_obj_t *screen_1_btn_9;
	lv_obj_t *screen_1_btn_9_label;
	lv_obj_t *screen_1_btn10;
	lv_obj_t *screen_1_btn10_label;
	lv_obj_t *screen_1_btn_11;
	lv_obj_t *screen_1_btn_11_label;
	lv_obj_t *screen_1_btn_12;
	lv_obj_t *screen_1_btn_12_label;
	lv_obj_t *screen_1_label_2;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif