#include <Arduino.h>

#define R_PIN 12
#define G_PIN 14
#define B_PIN 27

#define PETENTIOMETER_PIN 26

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
    pinMode(R_PIN, OUTPUT);
    pinMode(G_PIN, OUTPUT);
    pinMode(B_PIN, OUTPUT);
}
int analog = 0;

void loop() {
    int analogValue = analogRead(PETENTIOMETER_PIN);
    if (analog == analogValue) {
        return;
    }
    analog = analogValue;

    float voltage = floatMap(analogValue, 0, 4095, 0, 3.3);

    int brightness = floatMap(voltage, 0, 3.3, 0, 255); // Map the voltage to the range 0-255

    analogWrite(R_PIN, brightness);
    analogWrite(G_PIN, brightness);
    analogWrite(B_PIN, brightness);

    delay(50); //stability
}