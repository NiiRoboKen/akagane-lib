#pragma once

#include "../peripherals/gpio.hpp"
#include "../utils/macro.hpp"
#include <cstdint>

namespace Akagane {

enum class Dir {
  CW,
  CCW,
};

constexpr Dir operator!(Dir dir) {
  return dir == Dir::CW ? Dir::CCW : Dir::CW;
}

interface IMotor {
  virtual void run(Dir dir, uint16_t value) = 0;
};

class CytronMD : public IMotor {
public:
  CytronMD(PWMPin* pwm, IOutputPin* dir, bool invert);
  void init(uint32_t pwm_freq);
  void run(Dir dir, uint16_t value);

private:
  PWMPin* pwm;
  IOutputPin* dir;
  bool invert;
};

}; // namespace Akagane
