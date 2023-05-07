#include <Arduino.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include <demos/lv_demos.h>
#include "my_lv_ports.h"

/**
 * @brief 初始化屏幕摇杆
 *
 */
void keyGPIOInit() {
    // LCD拓展版按键定义
#define UPKEY 8
#define DWKEY 13
#define LKEY 5
#define RKEY 9
#define CENTER 4
    // 按键对应GPIO初始化-上拉输入
    pinMode(UPKEY, INPUT_PULLUP);   // UPKEY
    pinMode(DWKEY, INPUT_PULLUP);   // DWKEY
    pinMode(LKEY, INPUT_PULLUP);    // LKEY
    pinMode(RKEY, INPUT_PULLUP);    // RKEY
    pinMode(CENTER, INPUT_PULLUP);  // CENTER
    // LED测试
    pinMode(12, OUTPUT);  // CENTER
}

/**
 * @brief 该函数用于按键扫描，上下左右中分别返回12345，若无按键则返回 0
 *
 * @return int
 */
int KEYScan() {
    if (digitalRead(UPKEY) == 0) {
        return 1;
    } else if (digitalRead(DWKEY) == 0) {
        return 2;
    } else if (digitalRead(LKEY) == 0) {
        return 3;
    } else if (digitalRead(RKEY) == 0) {
        return 4;
    } else if (digitalRead(CENTER) == 0) {
        return 5;
    } else {
        return 0;
    }
}

void setup(void) {
    Serial.begin(115200);
    Serial.print("Hello! esp32c3 with air101lcd");

    keyGPIOInit();
    lv_init();
    my_disp_init();

    lv_demo_benchmark();
    Serial.println("Setup done");
}

void loop() {
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}