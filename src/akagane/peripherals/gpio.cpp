#include "gpio.hpp"
#include "../types/numeric.hpp"
#include "../utils/panic.hpp"
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
  this->is_initialized = true;
  pinMode(this->pin_number, OUTPUT);
  if (initial_state == Digital::High) {
    this->set_high();
  } else {
    this->set_low();
  }
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
    AKAGANE_PANIC("PushpullPin GPIO%d is not initialized.", this->pin_number);
  }
}

OpendrainPin::OpendrainPin(pin_number_t pin_number) : Pin(pin_number) {}

void OpendrainPin::init(Digital initial_state) {
  this->is_initialized = true;
  pinMode(this->pin_number, OUTPUT_OPEN_DRAIN);
  if (initial_state == Digital::High) {
    this->set_high();
  } else {
    this->set_low();
  }
}

void OpendrainPin::set_high() {
  this->check_initialized();
  this->state = Digital::High;
  digitalWrite(this->pin_number, LOW);
}

void OpendrainPin::set_low() {
  this->check_initialized();
  this->state = Digital::Low;
  digitalWrite(this->pin_number, HIGH);
}

Digital OpendrainPin::get_state() {
  this->check_initialized();
  return this->state;
}

void OpendrainPin::toggle() {
  if (this->state == Digital::High) {
    this->set_low();
  } else if (this->state == Digital::Low) {
    this->set_high();
  }
}

void OpendrainPin::check_initialized() {
  if (!this->is_initialized) {
    AKAGANE_PANIC("OpendrainPin GPIO%d is not initialized.", this->pin_number);
  }
}

InputPin::InputPin(pin_number_t pin_number) : Pin(pin_number) {}

void InputPin::init(PullMode pull) {
  this->is_initialized = true;
  switch (pull) {
  case PullMode::None:
    pinMode(this->pin_number, INPUT);
    break;
  case PullMode::PullDown:
    pinMode(this->pin_number, INPUT_PULLDOWN);
    break;
  case PullMode::PullUp:
    pinMode(this->pin_number, INPUT_PULLUP);
    break;
  }
}

bool InputPin::is_high() {
  this->check_initialized();
  return digitalRead(this->pin_number) == HIGH;
}

bool InputPin::is_low() {
  this->check_initialized();
  return digitalRead(this->pin_number) == LOW;
}

void InputPin::check_initialized() {
  if (!this->is_initialized) {
    AKAGANE_PANIC("InputPin GPIO%d is not initialized.", this->pin_number);
  }
}

}; // namespace Akagane

#endif

#if defined(ARDUINO) && defined(ARDUINO_ARCH_ESP32)

#include <Arduino.h>

namespace Akagane {

PWMPin::PWMPin(pin_number_t pin_number) : Pin(pin_number) {}

void PWMPin::init(uint32_t _freq) {
  this->is_initialized = true;
  // NOTE: ESP32では16bitの分解能では1.2kHzほどが限界のため周波数の指定を無視する
  bool result = ledcAttach(this->pin_number, 1200, 16);
  if (!result) {
    AKAGANE_PANIC("PWMPin GPIO%d can not initialized.", this->pin_number);
  }
}

void PWMPin::set_duty(uint16_t duty) {
  this->check_initialized();
  ledcWrite(this->pin_number, duty);
}

void PWMPin::check_initialized() {
  if (!this->is_initialized) {
    AKAGANE_PANIC("PWMPin GPIO%d is not initialized.", this->pin_number);
  }
}

}; // namespace Akagane

#endif
