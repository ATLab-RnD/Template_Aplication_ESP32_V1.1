/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"


static lv_style_t style_screen_ABC;
static lv_style_t style_screen_ABC_button_Example;
static lv_style_t style_screen_ABC_button_Example_label;

void setup_scr_screen_ABC(lv_ui *ui){
    //Write codes screen
	ui->screen_ABC = lv_obj_create(NULL);

    //cwrite codes screen_ABC_btn_Example
    ui->screen_ABC_button_Example = lv_btn_create(ui->screen_ABC);
    setup_button(ui->screen_ABC_button_Example,0,0,"Example");


    //Write codes screen_1_btn_BACK
	ui->screen_1_btn_BACK= lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_BACK,5,85,"BACK");
	//Write codes screen_1_btn_UP
	ui->screen_1_btn_UP = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_UP,45,85,"UP");
	//Write codes screen_1_btn_DOWN
	ui->screen_1_btn_DOWN = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_DOWN,85,85,"DOWN");
	//Write codes screen_1_btn_OK
	ui->screen_1_btn_OK = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_OK,125,85,"OK");

	//Write codes screen_1_label_1
	ui->screen_1_label_1 = lv_label_create(ui->screen_1);
	setup_label(ui->screen_1_label_1,"SCREEN 1",31,30,100,32);
}
