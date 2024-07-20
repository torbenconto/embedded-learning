#define red_led_pin 27
#define green_led_pin 26

void setup() {
  pinMode(red_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
}

void loop() {
  digitalWrite(red_led_pin, HIGH);
  delay(1000);
  digitalWrite(green_led_pin, HIGH);
  delay(1000);

  digitalWrite(red_led_pin, LOW);
  delay(1000);
  digitalWrite(green_led_pin, LOW);
  delay(1000);
}
