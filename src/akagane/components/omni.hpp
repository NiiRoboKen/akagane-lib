#pragma once

#include "motor.hpp"
#include <array>
#include <utility>

namespace Akagane {

class OmniWheel {
public:
  OmniWheel(IMotor* motor, double radian);
  void init();
  void move(int16_t x, int16_t y);

private:
  IMotor* motor;
  double radian;
};

template <uint8_t N>
class OmniWheels {
public:
  template <typename... Wheels>
  explicit OmniWheels(Wheels&&... wheels)
      : wheels{{std::forward<Wheels>(wheels)...}} {
    static_assert(sizeof...(Wheels) == N, "Number of wheels must match N");
  }
  void move(int16_t x, int16_t y) {
    for (OmniWheel wheel : this->wheels) {
      wheel.move(x, y);
    }
  }

private:
  std::array<OmniWheel, N> wheels;
};

}; // namespace Akagane
