#pragma once

#include "motor.hpp"

namespace Akagane {

class Omni {
public:
  Omni(IMotor* motor, double radian);
  void move(int16_t x, int16_t y);

private:
  IMotor* motor;
  double radian;
};

}; // namespace Akagane
