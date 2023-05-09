#include <Arduino.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <lvgl.h>

#include "UIManager.h"
#include "joystick.h"
#include "my_lv_port_indev.h"
#include "my_lv_ports.h"

static lv_indev_drv_t indev_drv;
static UIManager* um;

void setup(void) {
    Serial.begin(115200);
    Serial.print("Hello! esp32c3 with air101lcd");

    JoystickGPIOInit();
    lv_init();
    my_disp_init();

    um = new UIManager();
    um->create_lv_menu(btn_event_cb);
    lv_indev_t* keypad_indev = init_lv_indev(&indev_drv);
    lv_indev_set_group(keypad_indev, um->group);

    Serial.println("Setup done");
}

void loop() {
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}