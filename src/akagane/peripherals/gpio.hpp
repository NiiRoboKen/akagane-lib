#pragma once

#include "../utils/macro.hpp"
#include <cstdint>

namespace Akagane {

using pin_number_t = uint8_t;

class Pin {
public:
  Pin(pin_number_t pin_number);
  inline uint8_t get_pin_number();

protected:
  pin_number_t pin_number;
};

enum class Digital {
  Low,
  High,
};

interface IOutputPin {
  virtual void init(Digital initial_state) = 0;
  virtual void set_high() = 0;
  virtual void set_low() = 0;
  virtual void toggle() = 0;
  void set_state(Digital state) {
    if (state == Digital::High) {
      this->set_high();
    } else {
      this->set_low();
    }
  }
};

class PushpullPin : public Pin, public IOutputPin {
public:
  PushpullPin(pin_number_t pin_number);
  void init(Digital initial_state);
  void set_high();
  void set_low();
  Digital get_state();
  void toggle();

private:
  void check_initialized();
  bool is_initialized;
  Digital state;
};

class OpendrainPin : public Pin, public IOutputPin {
public:
  OpendrainPin(pin_number_t pin_number);
  void init(Digital initial_state);
  void set_high();
  void set_low();
  Digital get_state();
  void toggle();

private:
  void check_initialized();
  bool is_initialized;
  Digital state;
};

enum class PullMode {
  None,
  PullDown,
  PullUp,
};

class InputPin : public Pin {
public:
  InputPin(pin_number_t pin_number);
  void init(PullMode pull);
  bool is_high();
  bool is_low();
  Digital get_state();

private:
  void check_initialized();
  bool is_initialized;
};

class PWMPin : public Pin {
public:
  PWMPin(pin_number_t pin_number);
  void init(uint32_t freq);
  void set_duty(uint16_t duty);

private:
  void check_initialized();
  bool is_initialized;
};

}; // namespace Akagane
