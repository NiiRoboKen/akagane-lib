#include <Arduino.h>
#include <akagane.hpp>

using namespace Akagane;

auto sw = Switch::from_gpio(1, true);

void setup() {
  Serial.begin(115200);
  sw.init(PullMode::PullUp);
}

void loop() {
  if (sw.is_pushed()) {
    AKAGANE_INFO("pushed.");
  }
  delay(10);
}
