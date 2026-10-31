#include <Arduino.h>
#include <akagane.hpp>

using namespace Akagane;

auto led = PushpullPin(1);

void setup() {
  Serial.begin(115200);
  led.init(Digital::Low);
}

void loop() {
  led.toggle();
  delay(500);
}
