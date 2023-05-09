#include "joystick.h"

#include <Arduino.h>

/**
 * @brief 初始化屏幕摇杆
 *
 */
void JoystickGPIOInit() {
    // LCD拓展版按键定义
    // 按键对应GPIO初始化-上拉输入
    pinMode(JOYSTICK_UP_PIN, INPUT_PULLUP);     // UPKEY
    pinMode(JOYSTICK_DOWN_PIN, INPUT_PULLUP);   // DWKEY
    pinMode(JOYSTICK_LEFT_PIN, INPUT_PULLUP);   // LKEY
    pinMode(JOYSTICK_RIGHT_PIN, INPUT_PULLUP);  // RKEY
    pinMode(JOYSTICK_ENTER_PIN, INPUT_PULLUP);  // CENTER
    // LED测试
    pinMode(12, OUTPUT);  // CENTER
}

JoystickDirection readJoystick() {
    if (digitalRead(JOYSTICK_UP_PIN) == LOW) {
        return JOYSTICK_UP;
    }
    if (digitalRead(JOYSTICK_DOWN_PIN) == LOW) {
        return JOYSTICK_DOWN;
    }
    if (digitalRead(JOYSTICK_LEFT_PIN) == LOW) {
        return JOYSTICK_LEFT;
    }
    if (digitalRead(JOYSTICK_RIGHT_PIN) == LOW) {
        return JOYSTICK_RIGHT;
    }
    if (digitalRead(JOYSTICK_ENTER_PIN) == LOW) {
        return JOYSTICK_ENTER;
    }
    return JOYSTICK_NONE;
}

