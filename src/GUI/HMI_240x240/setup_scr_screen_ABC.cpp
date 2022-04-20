/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"

void setup_scr_screen_ABC(lv_ui *ui){
    //Write codes screen
	ui->screen_ABC = lv_obj_create(NULL);
     //Write codes screen_btn_MENU
    ui->screen_ABC_button_Example = lv_btn_create(ui->screen_ABC);
    
}
