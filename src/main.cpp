#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void drawTest(int x, int y, char *text, uint16_t color) {
    x = min(x, 159);
    y = min(y, 59);
    tft.setCursor(x, y);
    tft.setTextColor(color);
    tft.setTextSize(1);
    tft.setTextWrap(true);
    tft.print(text);
}

void drawTest(char *text, uint16_t color) {
    drawTest(20, 20, text, color);
}

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
 * @brief 清空屏幕
 *
 */
void allClean() {
    tft.fillScreen(TFT_BLACK);
}

/**
 * @brief 该函数用于按键扫描，上下左右中分别返回12345，若无按键则返回 0
 *
 * @return int
 */
int KEYScan() {
    if (digitalRead(UPKEY) == 0) {
        drawTest("UPKEY", TFT_BLUE);
        return 1;
    } else if (digitalRead(DWKEY) == 0) {
        drawTest("DWKEY", TFT_BLUE);
        return 2;
    } else if (digitalRead(LKEY) == 0) {
        drawTest("LKEY", TFT_BLUE);
        return 3;
    } else if (digitalRead(RKEY) == 0) {
        drawTest("RKEY", TFT_BLUE);
        return 4;
    } else if (digitalRead(CENTER) == 0) {
        drawTest("CENTER", TFT_BLUE);
        return 5;
    } else {
        allClean();  // 全清
        return 0;
    }
}

void setup(void) {
    Serial.begin(115200);
    Serial.print("Hello! esp32c3 with air101lcd");

    keyGPIOInit();
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

void loop() {
    KEYScan();
}