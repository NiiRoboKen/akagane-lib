#include "logger.hpp"

#ifdef ARDUINO

#include <Arduino.h>

namespace Akagane {

const size_t LOGGER_BUFFER_SIZE = 1024;

void __log(char* color_esc_code, char* filename, char* line, char* level, char* message_format, ...) {
  va_list args;
  va_start(args, message_format);
  char buffer[LOGGER_BUFFER_SIZE];
  vsnprintf(buffer, sizeof(buffer), message_format, args);
  va_end(args);
  Serial.printf("%s%s:%s [%s] %s \033[0m\r\n", color_esc_code, filename, line, level, buffer);
  Serial.flush();
};

}; // namespace Akagane

#endif
