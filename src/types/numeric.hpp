#pragma once

#include "traits.hpp"

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short;
using u16 = unsigned short;
using i32 = signed int;
using u32 = unsigned int;
using i64 = signed long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = double;

template <typename T>
constexpr bool is_int_t = is_type_eq<T, i8> || is_type_eq<T, i16> || is_type_eq<T, i32> || is_type_eq<T, i64>;

template <typename T>
constexpr bool is_uint_t = is_type_eq<T, u8> || is_type_eq<T, u16> || is_type_eq<T, u32> || is_type_eq<T, u64>;

template <typename T>
constexpr bool is_real_t = is_type_eq<T, f32> || is_type_eq<T, f64>;

template <typename T>
using int_t = require_t<is_int_t<T>, T>;

template <typename T>
using uint_t = require_t<is_uint_t<T>, T>;

template <typename T>
using real_t = require_t<is_real_t<T>, T>;

template <>
struct TypeInfo<i8> {
    static constexpr uint8_t BITS = 8;
    static constexpr uint8_t BYTES = 1;
    static constexpr int8_t MAX = 127;
    static constexpr int8_t MIN = -128;
};

template <>
struct TypeInfo<u8> {
    static constexpr uint8_t BITS = 8;
    static constexpr uint8_t BYTES = 1;
    static constexpr uint8_t MAX = 255;
    static constexpr uint8_t MIN = 0;
};

template <>
struct TypeInfo<i16> {
    static constexpr uint8_t BITS = 16;
    static constexpr uint8_t BYTES = 2;
    static constexpr int16_t MAX = 32767;
    static constexpr int16_t MIN = -32768;
};

template <>
struct TypeInfo<u16> {
    static constexpr uint8_t BITS = 16;
    static constexpr uint8_t BYTES = 2;
    static constexpr uint16_t MAX = 65535;
    static constexpr uint16_t MIN = 0;
};

template <>
struct TypeInfo<i32> {
    static constexpr uint8_t BITS = 32;
    static constexpr uint8_t BYTES = 4;
    static constexpr int32_t MAX = 2147483647;
    static constexpr int32_t MIN = -2147483648;
};

template <>
struct TypeInfo<u32> {
    static constexpr uint8_t BITS = 32;
    static constexpr uint8_t BYTES = 4;
    static constexpr uint32_t MAX = 4294967295;
    static constexpr uint32_t MIN = 0;
};

template <>
struct TypeInfo<i64> {
    static constexpr uint8_t BITS = 64;
    static constexpr uint8_t BYTES = 8;
    static constexpr int64_t MAX = 9223372036854775807LL;
    // https://stackoverflow.com/questions/60323203/c-warningclang-compiler-integer-literal-is-too-large-to-be-represented-in-a-s
    static constexpr int64_t MIN = -9223372036854775807LL - 1LL;
};

template <>
struct TypeInfo<u64> {
    static constexpr uint8_t BITS = 64;
    static constexpr uint8_t BYTES = 8;
    static constexpr uint64_t MAX = 18446744073709551615ULL;
    static constexpr uint64_t MIN = 0;
};

void assert_numeric_type_size() {
  static_assert(sizeof(i8) == 1, "i8 is not 1byte in this environment");
  static_assert(sizeof(i16) == 2, "i16 is not 2byte in this environment");
  static_assert(sizeof(i32) == 4, "i32 is not 4byte in this environment");
  static_assert(sizeof(i64) == 8, "i64 is not 8byte in this environment");

  static_assert(sizeof(u8) == 1, "u8 is not 1byte in this environment");
  static_assert(sizeof(u16) == 2, "u16 is not 2byte in this environment");
  static_assert(sizeof(u32) == 4, "u32 is not 4byte in this environment");
  static_assert(sizeof(u64) == 8, "u64 is not 8byte in this environment");

  static_assert(sizeof(f32) == 4, "f32 is not 4byte in this environment");
  static_assert(sizeof(f64) == 8, "f64 is not 8byte in this environment");
}