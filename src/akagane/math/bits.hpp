#pragma once

#include <cstddef>

namespace Akagane {

template <size_t N>
constexpr uint64_t nbits_max() {
  static_assert(N > 0 && N <= 64, "invalid bits size. 0 < n <= 64");
  return ~0ULL >> (64 - N);
}

template <typename T>
class BitSet {
public:
  static bool get(T* value, uint8_t index) { return *value & (1 << index); }
  static void set(T* value, uint8_t index, bool state) {
    if (state) {
      *value |= 1 << index;
    } else {
      *value &= ~(1 << index);
    }
  }
};

}; // namespace Akagane
