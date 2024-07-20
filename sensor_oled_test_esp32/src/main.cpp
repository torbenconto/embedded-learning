#include <Arduino.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <string>
#include<bits/stdc++.h>

#define DHT_PIN 26
#define OLED_RESET_PIN 4

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define I2C_ADDR 0x3C

Adafruit_SSD1306* display;
DHT* dht;

void setup() {
    Wire.begin();

    //Setup DHT
    dht = new DHT(DHT_PIN, DHT11);
    dht->begin();
    //Setup OLED
    display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);
    display->begin(SSD1306_SWITCHCAPVCC, I2C_ADDR);
    display->clearDisplay();
    display->setTextColor(SSD1306_WHITE);
    display->setTextSize(1);
}

void loop() {
    float temp = dht->readTemperature();
    float humidity = dht->readHumidity();

    // fahrenheit
    temp = (temp * 9/5) + 32;

    // Set 2 digits of precision
    std::stringstream tempStream;
    tempStream << std::fixed << std::setprecision(2) << temp;
    std::string tempString = tempStream.str();

    std::stringstream humidityStream;
    humidityStream << std::fixed << std::setprecision(2) << humidity;
    std::string humidityString = humidityStream.str();

    int16_t x1, y1;
    uint16_t w, h;
    display->getTextBounds(tempString.c_str(), 0, 0, &x1, &y1, &w, &h);

    int16_t x = (SCREEN_WIDTH - w) / 2;
    int16_t y = (SCREEN_HEIGHT - h) / 2;

    // Print 1 text height up so everything is centered
    display->setCursor(x - 5,y-h);
    display->print((tempString + " F").c_str());

    // Calculate height at which humidity is to be printed, 5px buffer
    int16_t humidityY = y + 5;

    display->setCursor(x - 5, humidityY);
    display->print((humidityString + " %").c_str());

    display->display();

    delay(5000);

    display->clearDisplay();
    display->setCursor(x,y);
}

