#pragma once

#include "traits.hpp"
#include <cstdint>

namespace Akagane {

template <>
struct TypeInfo<int8_t> {
    static constexpr uint8_t BITS = 8;
    static constexpr uint8_t BYTES = 1;
    static constexpr int8_t MAX = 127;
    static constexpr int8_t MIN = -128;
};

template <>
struct TypeInfo<uint8_t> {
    static constexpr uint8_t BITS = 8;
    static constexpr uint8_t BYTES = 1;
    static constexpr uint8_t MAX = 255;
    static constexpr uint8_t MIN = 0;
};

template <>
struct TypeInfo<int16_t> {
    static constexpr uint8_t BITS = 16;
    static constexpr uint8_t BYTES = 2;
    static constexpr int16_t MAX = 32767;
    static constexpr int16_t MIN = -32768;
};

template <>
struct TypeInfo<uint16_t> {
    static constexpr uint8_t BITS = 16;
    static constexpr uint8_t BYTES = 2;
    static constexpr uint16_t MAX = 65535;
    static constexpr uint16_t MIN = 0;
};

template <>
struct TypeInfo<int32_t> {
    static constexpr uint8_t BITS = 32;
    static constexpr uint8_t BYTES = 4;
    static constexpr int32_t MAX = 2147483647;
    static constexpr int32_t MIN = -2147483648;
};

template <>
struct TypeInfo<uint32_t> {
    static constexpr uint8_t BITS = 32;
    static constexpr uint8_t BYTES = 4;
    static constexpr uint32_t MAX = 4294967295;
    static constexpr uint32_t MIN = 0;
};

template <>
struct TypeInfo<int64_t> {
    static constexpr uint8_t BITS = 64;
    static constexpr uint8_t BYTES = 8;
    static constexpr int64_t MAX = 9223372036854775807LL;
    // https://stackoverflow.com/questions/60323203/c-warningclang-compiler-integer-literal-is-too-large-to-be-represented-in-a-s
    static constexpr int64_t MIN = -9223372036854775807LL - 1LL;
};

template <>
struct TypeInfo<uint64_t> {
    static constexpr uint8_t BITS = 64;
    static constexpr uint8_t BYTES = 8;
    static constexpr uint64_t MAX = 18446744073709551615ULL;
    static constexpr uint64_t MIN = 0;
};

}; // namespace Akagane
