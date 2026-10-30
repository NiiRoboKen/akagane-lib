#include "motor.hpp"
#include "../utils/logger.hpp"

namespace Akagane {

CytronMD::CytronMD(PWMPin& pwm, IOutputPin& dir, bool invert) : pwm(pwm), dir(dir), invert(invert) {}

void CytronMD::init(uint32_t pwm_freq) {
  this->dir.init(Digital::Low);
  this->pwm.init(pwm_freq);
}

void CytronMD::run(Dir dir, uint16_t duty) {
  if ((dir == Dir::CW) != this->invert) {
    this->dir.set_low();
  } else {
    this->dir.set_high();
  }
  this->pwm.set_duty(duty);
}

CytronMD CytronMD::from_gpio(pin_number_t pwm_pin, pin_number_t dir_pin, bool invert) {
  // このクラスのインスタンスはプログラム終了時まで生きるのでdeleteする必要はない
  PushpullPin& dir = *(new PushpullPin(dir_pin));
  PWMPin& pwm = *(new PWMPin(pwm_pin));
  return CytronMD(pwm, dir, invert);
}

MockMotor::MockMotor(const char* name) : name(name) {}

void MockMotor::run(Dir dir, uint16_t duty) {
  AKAGANE_DEBUG("%s: dir = %d, pwm = %d", this->name, dir == Dir::CW ? 0 : 1, duty);
}

}; // namespace Akagane
