#pragma once

namespace Akagane {

template <typename T>
inline constexpr T min(T a, T b) {
  return a < b ? a : b;
}

template <typename T>
inline constexpr T max(T a, T b) {
  return a > b ? a : b;
}

template <typename T>
inline constexpr T clamp(T value, T lower, T upper) {
  return min(max(lower, value), upper);
}

}; // namespace Akagane
