#include "my_lv_port_indev.h"

#include <Arduino.h>
#include <lvgl.h>

#include "joystick.h"

void keypad_read_cb(lv_indev_drv_t* indev_drv, lv_indev_data_t* data) {
    // Serial.println("myKeypadRead called");
    static JoystickDirection last_key = JOYSTICK_NONE;
    JoystickDirection act_key = readJoystick();

    data->state = (act_key == JOYSTICK_NONE) ? LV_INDEV_STATE_REL : LV_INDEV_STATE_PR;

    if (act_key != 0) {
        data->state = LV_INDEV_STATE_PR;
        switch (act_key) {
            case JOYSTICK_UP:
                data->key = LV_KEY_UP;
                break;
            case JOYSTICK_DOWN:
                data->key = LV_KEY_DOWN;
                break;
            case JOYSTICK_LEFT:
                data->key = LV_KEY_LEFT;
                break;
            case JOYSTICK_RIGHT:
                data->key = LV_KEY_RIGHT;
                break;
            case JOYSTICK_ENTER:
                data->key = LV_KEY_ENTER;
                break;
            default:
                break;
        }
        last_key = act_key;

        // 输出调试信息
        Serial.print("Joystick direction: ");
        Serial.println(act_key);
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->key = last_key;
}

void btn_event_cb(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* btn = lv_event_get_target(e);
    lv_obj_t* label = lv_obj_get_child(btn, 0);

    if (code == LV_EVENT_KEY) {
        uint32_t key_code = *((uint32_t*)lv_event_get_param(e));
        Serial.print("key code:");
        Serial.println(key_code);

        switch (key_code) {
            case JOYSTICK_UP:
                lv_label_set_text(label, "UP");
                break;
            case JOYSTICK_DOWN:
                lv_label_set_text(label, "DOWN");
                break;
            case JOYSTICK_LEFT:
                lv_label_set_text(label, "LEFT");
                break;
            case JOYSTICK_RIGHT:
                lv_label_set_text(label, "RIGHT");
                break;
            case JOYSTICK_ENTER:
                lv_label_set_text(label, "ENTER");
            default:
                break;
        }
    }
}

lv_indev_t* init_lv_indev(lv_indev_drv_t* indev_drv) {
    lv_indev_drv_init(indev_drv);
    indev_drv->type = LV_INDEV_TYPE_KEYPAD;
    indev_drv->read_cb = keypad_read_cb;
    lv_indev_t* keypad_indev = lv_indev_drv_register(indev_drv);
    return keypad_indev;
}