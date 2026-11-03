#pragma once

#include "../peripherals/gpio.hpp"
#include "../utils/macro.hpp"

namespace Akagane {

interface ISwitch {
  virtual bool is_on() = 0;
  bool is_off() { return !this->is_on(); }
  bool is_pushed() {
    bool state = this->is_on();
    bool result = state && !this->before_state;
    this->before_state = state;
    return result;
  }

protected:
  bool before_state;
};

class Switch : public ISwitch {
public:
  Switch(InputPin& pin, bool invert);
  static Switch from_gpio(pin_number_t pin_number, bool invert);
  void init(PullMode mode);
  bool is_on();

private:
  InputPin& pin;
  bool invert;
};

}; // namespace Akagane
