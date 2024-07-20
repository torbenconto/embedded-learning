//
// Created by tconto on 7/19/24.
//

#ifndef OLED_H
#define OLED_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define I2C_ADDR 0x3C

#define OLED_RESET 4

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define TEXT_SIZE 1
#define TEXT_COLOR WHITE
#define CURSOR_POS 0,0

#define DELAY_BETWEEN_CHAR 50
#define DELAY_BEFORE_ERASE 5000

void reset_display(Adafruit_SSD1306* display);

#endif //OLED_H