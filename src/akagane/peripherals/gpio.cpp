#include "gpio.hpp"
#include "../utils/panic.hpp"
#include <cstdint>

namespace Akagane {

Pin::Pin(uint8_t pin_number) : pin_number(pin_number) {}

inline uint8_t Pin::get_pin_number() const {
  return this->pin_number;
}

}; // namespace Akagane

#ifdef ARDUINO

#include <Arduino.h>

namespace Akagane {

PushpullPin::PushpullPin(pin_number_t pin_number) : Pin(pin_number) {}

void PushpullPin::init(Digital initial_state) {
  this->is_initialized = true;
  pinMode(this->pin_number, OUTPUT);
  if (initial_state == Digital::High) {
    this->set_high();
  } else {
    this->set_low();
  }
}

void PushpullPin::set(Digital state) {
  this->check_initialized();
  this->state = state;
  digitalWrite(this->pin_number, state == Digital::High ? HIGH : LOW);
}

void PushpullPin::set_high() {
  this->check_initialized();
  this->state = Digital::High;
  digitalWrite(this->pin_number, HIGH);
}

void PushpullPin::set_low() {
  this->check_initialized();
  this->state = Digital::Low;
  digitalWrite(this->pin_number, LOW);
}

Digital PushpullPin::get_state() {
  this->check_initialized();
  return this->state;
}

void PushpullPin::toggle() {
  if (this->state == Digital::High) {
    this->set_low();
  } else if (this->state == Digital::Low) {
    this->set_high();
  }
}

void PushpullPin::check_initialized() {
  if (!this->is_initialized) {
    AKAGANE_PANIC("GPIO%d is not initialized.", this->pin_number);
  }
}

}; // namespace Akagane

#endif
