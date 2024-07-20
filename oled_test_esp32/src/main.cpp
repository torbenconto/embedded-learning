#include "oled.h"
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <string>

Adafruit_SSD1306* display;

void setup() {
    display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    display->begin(SSD1306_SWITCHCAPVCC, I2C_ADDR);
    reset_display(display);
}

void loop() {
    std::string text = "Hello, world!";
    for(char& c : text) {
        delay(DELAY_BETWEEN_CHAR);
        display->print(c);
        display->display();
    }
    delay(DELAY_BEFORE_ERASE);
    reset_display(display);
}