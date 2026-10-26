#pragma once

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

class PushpullPin : public Pin {
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

}; // namespace Akagane
