#pragma once

#include <cstddef>

namespace Akagane {

template <size_t N>
constexpr uint64_t nbits_max() {
  static_assert(N > 0 && N <= 64, "invalid bits size. 0 < n <= 64");
  return ~0ULL >> (64 - N);
}

}; // namespace Akagane
