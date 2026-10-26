#pragma once

#include "macro.hpp"

namespace Akagane {

void __log(char* color_esc_code, char* filename, char* line, char* level, char* message_format, ...);

}; // namespace Akagane

#define AKAGANE_LOG_LEVEL_DEBUG 0
#define AKAGANE_LOG_LEVEL_INFO 1
#define AKAGANE_LOG_LEVEL_WARN 2
#define AKAGANE_LOG_LEVEL_ERROR 3

#ifndef AKAGANE_LOG_LEVEL
#define AKAGANE_LOG_LEVEL AKAGANE_LOG_LEVEL_INFO
#endif

#if AKAGANE_LOG_LEVEL <= AKAGANE_LOG_LEVEL_DEBUG
#define AKAGANE_DEBUG(...) Akagane::__log("\033[1;37m", __FILE_NAME__, TOSTRING(__LINE__), "DEBUG", __VA_ARGS__)
#else
#define AKAGANE_DEBUG(...)
#endif

#if AKAGANE_LOG_LEVEL <= AKAGANE_LOG_LEVEL_INFO
#define AKAGANE_INFO(...) Akagane::__log("\033[1;32m", __FILE_NAME__, TOSTRING(__LINE__), "INFO", __VA_ARGS__)
#else
#define AKAGANE_INFO(...)
#endif

#if AKAGANE_LOG_LEVEL <= AKAGANE_LOG_LEVEL_WARN
#define AKAGANE_WARN(...) Akagane::__log("\033[1;33m", __FILE_NAME__, TOSTRING(__LINE__), "WARN", __VA_ARGS__)
#else
#define AKAGANE_WARN(...)
#endif

#if AKAGANE_LOG_LEVEL <= AKAGANE_LOG_LEVEL_ERROR
#define AKAGANE_ERROR(...) Akagane::__log("\033[1;31m", __FILE_NAME__, TOSTRING(__LINE__), "ERROR", __VA_ARGS__)
#else
#define AKAGANE_ERROR(...)
#endif
