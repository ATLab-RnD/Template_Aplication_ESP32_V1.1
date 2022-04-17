/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

lv_ui guider_ui;
void setup_ui(lv_ui *ui){
	setup_scr_screen(ui);
	lv_scr_load(ui->screen);
}

void create_button(lv_obj_t *button, int pos_x, int pos_y, lv_style_t style_button)
{
    lv_obj_set_pos(button, pos_x, pos_y);
	lv_obj_set_size(button, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn

	if (style_button.prop_cnt > 1)
		lv_style_reset(&style_button);
	else
	lv_style_init(&style_button);
	lv_style_set_radius(&style_button, 5);
	lv_style_set_bg_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_button, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_button, 255);
	lv_style_set_shadow_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_button, 255);
	lv_style_set_border_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_button, 0);
	lv_style_set_border_opa(&style_button, 255);
	lv_obj_add_style(button, &style_button, LV_PART_MAIN|LV_STATE_DEFAULT);
}

void create_label_button( lv_obj_t *screen_button_label, char * label_button, lv_style_t style_button_label)
{
	lv_label_set_text(screen_button_label, label_button);
	lv_obj_set_style_text_color(screen_button_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(screen_button_label, &lv_font_montserrat_12, LV_STATE_DEFAULT);
	// lv_obj_set_style_pad_all(ui->screen_1_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(screen_button_label, LV_ALIGN_CENTER, 0, 0);
}
