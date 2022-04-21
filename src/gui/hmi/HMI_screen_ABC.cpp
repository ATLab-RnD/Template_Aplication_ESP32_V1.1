/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "../general/gui_guider.h"

void setup_scr_HMI_screen_ABC(lv_ui *ui){
    //Write codes screen
	ui->screen_ABC = lv_obj_create(NULL);
    //Create 6 button
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
    
}
