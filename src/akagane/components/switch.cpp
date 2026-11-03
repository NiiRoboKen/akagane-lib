#include "switch.hpp"

namespace Akagane {

Switch::Switch(InputPin& pin, bool invert) : pin(pin), invert(invert) {}

Switch Switch::from_gpio(pin_number_t pin_number, bool invert) {
  InputPin* pin = new InputPin(pin_number);
  return Switch(*pin, invert);
}
void Switch::init(PullMode mode) {
  this->pin.init(mode);
  this->before_state = this->is_on();
}
bool Switch::is_on() {
  return this->pin.is_high() != this->invert;
}

}; // namespace Akagane
