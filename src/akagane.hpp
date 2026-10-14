#pragma once

#define USING_AKAGANE_LIB

#include "./types/numeric.hpp"
#include "./types/traits.hpp"

void akagane_init() {
  assert_numeric_type_size();
}
