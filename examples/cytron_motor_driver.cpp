#include <Arduino.h>
#include <akagane.hpp>

using namespace Akagane;

const uint16_t RESOLUTION = 100;
constexpr uint16_t STEP = nbits_max<16>() / RESOLUTION;
const uint32_t DELAY_MS = 50;

auto motor = CytronMD::from_gpio(1, 2, false);
auto dir = Dir::CW;

void setup() {
  motor.init(20000);
}

void loop() {
  dir = !dir;
  for (uint8_t i = 0; i < RESOLUTION; i++) {
    motor.run(dir, STEP * i);
    delay(DELAY_MS);
  }
  for (uint8_t i = 100; i > 0; i--) {
    motor.run(dir, STEP * i);
    delay(DELAY_MS);
  }
}
