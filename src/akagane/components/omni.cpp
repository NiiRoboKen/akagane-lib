#include "omni.hpp"
#include "../math/bits.hpp"
#include "../math/math.hpp"
#include "motor.hpp"
#include <array>
#include <math.h>

namespace Akagane {

OmniWheel::OmniWheel(IMotor& motor, double radian) : motor(motor), radian(radian) {}

void OmniWheel::move(int16_t x, int16_t y) {
  double power = (cos(this->radian) * x + sin(this->radian) * y) * sqrt(2);
  Dir dir = power >= 0 ? Dir::CW : Dir::CCW;
  uint16_t duty = clamp(abs(power), 0., (double)nbits_max<16>());
  this->motor.run(dir, duty);
}

}; // namespace Akagane
