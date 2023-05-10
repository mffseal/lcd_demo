#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#define JOYSTICK_UP_PIN 13
#define JOYSTICK_DOWN_PIN 8
#define JOYSTICK_LEFT_PIN 9
#define JOYSTICK_RIGHT_PIN 5
#define JOYSTICK_ENTER_PIN 4

enum JoystickDirection {
    JOYSTICK_NONE,
    JOYSTICK_UP,
    JOYSTICK_DOWN,
    JOYSTICK_LEFT,
    JOYSTICK_RIGHT,
    JOYSTICK_ENTER
};

void JoystickGPIOInit();
JoystickDirection readJoystick();

#endif  // _JOYSTICK_H_