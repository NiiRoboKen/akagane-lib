#pragma once

#include <cmath>

namespace Akagane {

inline constexpr double rad_to_deg(double value) {
  return value * 180. / M_PI;
}

inline constexpr double deg_to_rad(double value) {
  return value * M_PI / 180.;
}

class Angle {
public:
  static Angle from_deg(double value) { return Angle(value); }
  static Angle from_rad(double value) { return Angle(rad_to_deg(value)); }
  double radian() const { return deg_to_rad(this->value); }
  double degree() const { return this->value; }
  Angle normalized() const {
    double normalized = std::fmod(this->degree(), 360.);
    if (normalized >= 180.) {
      normalized -= 360.;
    } else if (normalized < -180.) {
      normalized += 360.;
    }
    return Angle::from_deg(normalized);
  }
  Angle operator+(const Angle& rhs) const {
    return Angle::from_deg(this->degree() + rhs.degree());
  }
  Angle operator-(const Angle& rhs) const {
    return Angle::from_deg(this->degree() - rhs.degree());
  }
  bool operator<(const Angle& rhs) const { return this->degree() < rhs.degree(); }
  bool operator>(const Angle& rhs) const { return rhs < *this; }
  // 正規化された最短方向への角度を返します
  Angle go_diff(const Angle& angle) const {
    return (angle - *this).normalized();
  }

private:
  Angle(double value) : value(value) {}
  const double value;
};

}; // namespace Akagane
