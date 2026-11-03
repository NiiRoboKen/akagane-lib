#pragma once

#include "../types/numeric.hpp"

namespace Akagane {

template <typename T>
inline constexpr T min(T a, T b) {
  return a < b ? a : b;
}

template <typename T>
inline constexpr T max(T a, T b) {
  return a > b ? a : b;
}

template <typename T, typename U>
inline constexpr T clamp(U value) {
  return min(max((U)TypeInfo<T>::MIN, value), (U)TypeInfo<T>::MAX);
}

}; // namespace Akagane
