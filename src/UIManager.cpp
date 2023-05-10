#include "UIManager.h"

void UIManager::create_lv_menu(lv_event_cb_t btn_event_cb) {
    lv_obj_t* button1 = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(button1, 20, 20);
    lv_obj_t* label1 = lv_label_create(button1);
    lv_label_set_text(label1, "Button 1");

    lv_obj_t* button2 = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(button2, 20, 60);
    lv_obj_t* label2 = lv_label_create(button2);
    lv_label_set_text(label2, "Button 2");

    lv_obj_t* button3 = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(button3, 20, 100);
    lv_obj_t* label3 = lv_label_create(button3);
    lv_label_set_text(label3, "Button 3");

    lv_group_add_obj(group, button1);
    lv_group_add_obj(group, button2);
    lv_group_add_obj(group, button3);

    lv_obj_add_event_cb(button1, btn_event_cb, LV_EVENT_ALL, this);
    lv_obj_add_event_cb(button2, btn_event_cb, LV_EVENT_ALL, this);
    lv_obj_add_event_cb(button3, btn_event_cb, LV_EVENT_ALL, this);
    lv_group_focus_cb_t focus_cb = lv_group_get_focus_cb(group);
    lv_group_focus_obj(button1);
    lv_obj_add_state(button1, LV_STATE_FOCUS_KEY);  // 控件当前由输入设备（例如键盘）控制，并且处于焦点状态。用于启用初始聚焦框
}

UIManager::UIManager() {
    group = lv_group_create();
}