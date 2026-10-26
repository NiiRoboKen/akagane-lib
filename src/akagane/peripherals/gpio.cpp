#include "gpio.hpp"
#include <cstdint>

namespace Akagane {

Pin::Pin(uint8_t pin_number) : pin_number(pin_number) {}

inline uint8_t Pin::get_pin_number() {
  return this->pin_number;
}

}; // namespace Akagane

#ifdef ARDUINO

#include <Arduino.h>

namespace Akagane {

PushpullPin::PushpullPin(pin_number_t pin_number) : Pin(pin_number) {}

void PushpullPin::init(Digital initial_state) {
  pinMode(this->pin_number, OUTPUT);
  if (initial_state == Digital::High) {
    this->set_high();
  } else {
    this->set_low();
  }
}

void PushpullPin::set_high() {
  this->state = Digital::High;
  digitalWrite(this->pin_number, HIGH);
}

void PushpullPin::set_low() {
  this->state = Digital::Low;
  digitalWrite(this->pin_number, LOW);
}

Digital PushpullPin::get_state() {
  return this->state;
}

void PushpullPin::toggle() {
  if (this->state == Digital::High) {
    this->set_low();
  } else if (this->state == Digital::Low) {
    this->set_high();
  }
}

}; // namespace Akagane

#endif
