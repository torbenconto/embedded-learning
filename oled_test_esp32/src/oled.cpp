//
// Created by tconto on 7/19/24.
//
#include "oled.h"
#include <Adafruit_SSD1306.h>

void reset_display(Adafruit_SSD1306* display) {
    display->clearDisplay();
    display->setTextColor(TEXT_COLOR);
    display->setTextSize(TEXT_SIZE);
    display->setCursor(CURSOR_POS);
}