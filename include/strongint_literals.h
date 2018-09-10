// Copyright 2018 Frank Benkstein
//
// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <http://unlicense.org>

#ifndef STRONGINT_LITERALS_H_INCLUDED_
#define STRONGINT_LITERALS_H_INCLUDED_

#include "strongint_stdint.h"

namespace strongint {
namespace detail {
template <unsigned x, unsigned n>
struct power {
    static constexpr unsigned value = x * power<x, n - 1>::value;
};
template <unsigned x>
struct power<x, 0> {
    static constexpr unsigned value = 1;
};

template <class T, char... chars>
struct literal_parser;

template <class T, unsigned base, char... chars>
struct base_literal_parser;

template <class T, unsigned base, char first, char... rest>
struct base_literal_parser<T, base, first, rest...> {
    static constexpr T value =
        T{(base_literal_parser<T, base, first>::value.value *
           power<base, sizeof...(rest)>::value) +
          base_literal_parser<T, base, rest...>::value.value};
};

#define DEFINE_DIGIT(base, c, v)             \
    template <class T>                       \
    struct base_literal_parser<T, base, c> { \
        static constexpr T value = T{v};     \
    }

DEFINE_DIGIT(10, '0', 0);
DEFINE_DIGIT(10, '1', 1);
DEFINE_DIGIT(10, '2', 2);
DEFINE_DIGIT(10, '3', 3);
DEFINE_DIGIT(10, '4', 4);
DEFINE_DIGIT(10, '5', 5);
DEFINE_DIGIT(10, '6', 6);
DEFINE_DIGIT(10, '7', 7);
DEFINE_DIGIT(10, '8', 8);
DEFINE_DIGIT(10, '9', 9);

DEFINE_DIGIT(16, '0', 0);
DEFINE_DIGIT(16, '1', 1);
DEFINE_DIGIT(16, '2', 2);
DEFINE_DIGIT(16, '3', 3);
DEFINE_DIGIT(16, '4', 4);
DEFINE_DIGIT(16, '5', 5);
DEFINE_DIGIT(16, '6', 6);
DEFINE_DIGIT(16, '7', 7);
DEFINE_DIGIT(16, '8', 8);
DEFINE_DIGIT(16, '9', 9);
DEFINE_DIGIT(16, 'a', 10);
DEFINE_DIGIT(16, 'b', 11);
DEFINE_DIGIT(16, 'c', 12);
DEFINE_DIGIT(16, 'd', 13);
DEFINE_DIGIT(16, 'e', 14);
DEFINE_DIGIT(16, 'f', 15);
DEFINE_DIGIT(16, 'A', 10);
DEFINE_DIGIT(16, 'B', 11);
DEFINE_DIGIT(16, 'C', 12);
DEFINE_DIGIT(16, 'D', 13);
DEFINE_DIGIT(16, 'E', 14);
DEFINE_DIGIT(16, 'F', 15);

DEFINE_DIGIT(8, '0', 0);
DEFINE_DIGIT(8, '1', 1);
DEFINE_DIGIT(8, '2', 2);
DEFINE_DIGIT(8, '3', 3);
DEFINE_DIGIT(8, '4', 4);
DEFINE_DIGIT(8, '5', 5);
DEFINE_DIGIT(8, '6', 6);
DEFINE_DIGIT(8, '7', 7);

DEFINE_DIGIT(2, '0', 0);
DEFINE_DIGIT(2, '1', 1);

#undef DEFINE_DIGIT

#define BASE_10_START(first)                                            \
    template <class T, char second, char... chars>                      \
    struct literal_parser<T, first, second, chars...> {                 \
        static constexpr T value =                                      \
            base_literal_parser<T, 10, first, second, chars...>::value; \
    }

BASE_10_START('1');
BASE_10_START('2');
BASE_10_START('3');
BASE_10_START('4');
BASE_10_START('5');
BASE_10_START('6');
BASE_10_START('7');
BASE_10_START('8');
BASE_10_START('9');

#undef BASE_10_START

template <class T, char... chars>
struct literal_parser<T, '0', 'x', chars...> {
    static constexpr T value = base_literal_parser<T, 16, chars...>::value;
};

template <class T, char... chars>
struct literal_parser<T, '0', 'X', chars...> {
    static constexpr T value = base_literal_parser<T, 16, chars...>::value;
};

template <class T, char first, char... chars>
struct literal_parser<T, '0', first, chars...> {
    static constexpr T value =
        base_literal_parser<T, 8, first, chars...>::value;
};

template <class T, char... chars>
struct literal_parser<T, '0', 'b', chars...> {
    static constexpr T value = base_literal_parser<T, 2, chars...>::value;
};

template <class T, char c>
struct literal_parser<T, c> {
    static constexpr T value = T{base_literal_parser<T, 10, c>::value};
};
}  // namespace detail

namespace literals {
template <char... chars>
constexpr u8 operator""_u8() {
    return ::strongint::detail::literal_parser<u8, chars...>::value;
}
template <char... chars>
constexpr i8 operator""_i8() {
    return ::strongint::detail::literal_parser<i8, chars...>::value;
}
template <char... chars>
constexpr u16 operator""_u16() {
    return ::strongint::detail::literal_parser<u16, chars...>::value;
}
template <char... chars>
constexpr i16 operator""_i16() {
    return ::strongint::detail::literal_parser<i16, chars...>::value;
}
template <char... chars>
constexpr u32 operator""_u32() {
    return ::strongint::detail::literal_parser<u32, chars...>::value;
}
template <char... chars>
constexpr i32 operator""_i32() {
    return ::strongint::detail::literal_parser<i32, chars...>::value;
}
template <char... chars>
constexpr u64 operator""_u64() {
    return ::strongint::detail::literal_parser<u64, chars...>::value;
}
template <char... chars>
constexpr i64 operator""_i64() {
    return ::strongint::detail::literal_parser<i64, chars...>::value;
}
template <char... chars>
constexpr usize operator""_usize() {
    return ::strongint::detail::literal_parser<usize, chars...>::value;
}
template <char... chars>
constexpr isize operator""_isize() {
    return ::strongint::detail::literal_parser<isize, chars...>::value;
}
}  // namespace literals
}  // namespace strongint

#endif  // STRONGINT_LITERALS_H_INCLUDED_
