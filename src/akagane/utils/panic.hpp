#pragma once

#include "logger.hpp"
#include "macro.hpp"

namespace Akagane {

void endless();

} // namespace Akagane

#define AKAGANE_PANIC(...)                                                                 \
  Akagane::__log("\033[1;4;91m", __FILE_NAME__, TOSTRING(__LINE__), "PANIC", __VA_ARGS__); \
  Akagane::endless()
