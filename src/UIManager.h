#ifndef _UIMANAGER_H_
#define _UIMANAGER_H_

#include <lvgl.h>

enum screen_type {
    UM_SRC_,
};

struct sc_data {
    uint8_t data1;
};

class UIManager {
   public:
    UIManager();
    void load_src(screen_type st);
    void update_ui(sc_data sc_data);
    void create_lv_menu(lv_event_cb_t btn_event_cb);
    lv_group_t* group;

   private:
};

#endif  // _UIMANAGER_H_