#include "motor.hpp"

namespace Akagane {

CytronMD::CytronMD(PWMPin* pwm, IOutputPin* dir, bool invert) : pwm(pwm), dir(dir), invert(invert) {}

void CytronMD::init(uint32_t pwm_freq) {
  this->dir->init(Digital::Low);
  this->pwm->init(pwm_freq);
}

void CytronMD::run(Dir dir, uint16_t duty) {
  if ((dir == Dir::CW) != this->invert) {
    this->dir->set_low();
  } else {
    this->dir->set_high();
  }
  this->pwm->set_duty(duty);
}

}; // namespace Akagane
