#ifndef _MY_LV_PORTS_
#define _MY_LV_PORTS_
#include <TFT_eSPI.h>
#include <lvgl.h>

/*Change to your screen resolution*/
const uint16_t screenWidth = 80;
const uint16_t screenHeight = 160;

void my_disp_init(void);  // 挂载lvgl接口，设置buffer
#endif //_MY_LV_PORTS_
