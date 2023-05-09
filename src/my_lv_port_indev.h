#ifndef _LV_PORT_INDEV_H_
#define _LV_PORT_INDEV_H_

#include <lvgl.h>

void btn_event_cb(lv_event_t* e);
void keypad_read_cb(lv_indev_drv_t* indev_drv, lv_indev_data_t* data);
lv_indev_t* init_lv_indev(lv_indev_drv_t* indev_drv);

#endif  // _LV_PORT_INDEV_H_