#include "UIManager.h"

void UIManager::create_lv_menu(lv_event_cb_t btn_event_cb) {
    // lv_obj_t* container = lv_obj_create(lv_scr_act());

    lv_obj_t* button = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(button, 20, 20);
    lv_obj_t* label = lv_label_create(button);
    lv_label_set_text(label, "Button 1");
    lv_obj_add_event_cb(button, btn_event_cb, LV_EVENT_ALL, NULL);
    lv_group_add_obj(group, button);
}

UIManager::UIManager() {
    group = lv_group_create();
}