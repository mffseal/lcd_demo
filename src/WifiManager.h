#ifndef _WIFIMANAGER_H_
#define _WIFIMANAGER_H_

struct wifi_siginal {
    char ssid[32];
};

class WifiManager {
   public:
    wifi_siginal wifi_list[10];
    WifiManager();
    wifi_siginal* scan_wifi_list();

   private:
}

#endif  // _WIFIMANAGER_H_