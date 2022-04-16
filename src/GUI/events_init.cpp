/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

void events_init(lv_ui *ui)
{
}

static void screen_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_led_1, lv_color_make(255, 250, 0), LV_PART_MAIN);
		// lv_obj_set_style_bg_grad_color(guider_ui.screen_led_1, lv_color_make(0xff, 0x05, 0x05), LV_PART_MAIN);
	}
		break;
	default:
		break;
	}
}

static void screen_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_led_1, lv_color_make(225, 0x00, 255), LV_PART_MAIN);//pink
		// lv_obj_set_style_bg_grad_color(guider_ui.screen_led_1, lv_color_make(0xd5, 0xff, 0x05), LV_PART_MAIN);
	}
		break;
	default:
		break;
	}
}

static void screen_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_led_2, lv_color_make(181, 245, 9), LV_PART_MAIN);//blue
		// lv_obj_set_style_bg_grad_color(guider_ui.screen_led_2, lv_color_make(0xd5, 0xff, 0x05), LV_PART_MAIN);
	}
		break;
	default:
		break;
	}
}

static void screen_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_led_2, lv_color_make(249, 6, 6), LV_PART_MAIN); //red
		// lv_obj_set_style_bg_grad_color(guider_ui.screen_led_2, lv_color_make(0xff, 0x05, 0x05), LV_PART_MAIN);
	}
		break;
	default:
		break;
	}
}

static void screen_btn_1_event_handler(lv_event_t *e)
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
	lv_obj_add_event_cb(ui->screen_btn_2, screen_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_4, screen_btn_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_5, screen_btn_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_6, screen_btn_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_btn_1, screen_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void screen_1_btn_9_event_handler(lv_event_t *e)
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
	lv_obj_add_event_cb(ui->screen_1_btn_9, screen_1_btn_9_event_handler, LV_EVENT_ALL, NULL);
}
