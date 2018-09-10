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

#ifndef STRONGINT_TYPE_H_INCLUDED_
#define STRONGINT_TYPE_H_INCLUDED_

#include <limits>
#include <type_traits>

namespace strongint {
template <class T, class Tag>
struct strongint {
    using base_type = T;
    base_type value;
};

// unary operators

template <class T, class Tag>
constexpr strongint<T, Tag> operator+(strongint<T, Tag> x) {
    return strongint<T, Tag>{
        static_cast<typename strongint<T, Tag>::base_type>(+x)};
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator~(strongint<T, Tag> x) {
    return strongint<T, Tag>{
        static_cast<typename strongint<T, Tag>::base_type>(~x)};
}

template <class T, class Tag>
constexpr
    typename std::enable_if<std::is_signed<T>::value, strongint<T, Tag> >::type
    operator-(strongint<T, Tag> x) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(-x.value)};
}

template <class T, class Tag>
constexpr strongint<T, Tag>& operator++(strongint<T, Tag>& x) {
    ++x.value;
    return x;
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator++(strongint<T, Tag>& x, int) {
    auto tmp = x;
    ++x;
    return tmp;
}

// binary operators

template <class T, class Tag>
constexpr strongint<T, Tag> operator+(strongint<T, Tag> x,
                                      strongint<T, Tag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x + y)};
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator-(strongint<T, Tag> x,
                                      strongint<T, Tag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x - y)};
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator*(strongint<T, Tag> x,
                                      strongint<T, Tag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x * y)};
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator/(strongint<T, Tag> x,
                                      strongint<T, Tag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x / y)};
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator%(strongint<T, Tag> x,
                                      strongint<T, Tag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x % y)};
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator|(strongint<T, Tag> x,
                                      strongint<T, Tag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x | y)};
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator&(strongint<T, Tag> x,
                                      strongint<T, Tag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x & y)};
}

template <class T, class Tag>
constexpr strongint<T, Tag> operator^(strongint<T, Tag> x,
                                      strongint<T, Tag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x ^ y)};
}

template <class T, class Tag, class U, class OtherTag>
constexpr strongint<T, Tag> operator<<(strongint<T, Tag> x,
                                       strongint<U, OtherTag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x.value << y.value)};
}

template <class T, class Tag, class U>
constexpr typename std::enable_if<std::is_integral<U>::value,
                                  strongint<T, Tag> >::type
operator<<(strongint<T, Tag> x, U y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x.value << y)};
}

template <class T, class Tag, class U, class OtherTag>
constexpr strongint<T, Tag> operator>>(strongint<T, Tag> x,
                                       strongint<U, OtherTag> y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x.value >> y.value)};
}

template <class T, class Tag, class U>
constexpr typename std::enable_if<std::is_integral<U>::value,
                                  strongint<T, Tag> >::type
operator>>(strongint<T, Tag> x, U y) {
    return strongint<T, Tag>{static_cast<typename strongint<T, Tag>::base_type>(x.value >> y)};
}

template <class T, class Tag>
constexpr bool operator<(strongint<T, Tag> x, strongint<T, Tag> y) {
    return x.value < y.value;
}

template <class T, class Tag>
constexpr bool operator<=(strongint<T, Tag> x, strongint<T, Tag> y) {
    return x.value <= y.value;
}

template <class T, class Tag>
constexpr bool operator==(strongint<T, Tag> x, strongint<T, Tag> y) {
    return x.value == y.value;
}

template <class T, class Tag>
constexpr bool operator!=(strongint<T, Tag> x, strongint<T, Tag> y) {
    return x.value != y.value;
}

template <class T, class Tag>
constexpr bool operator>=(strongint<T, Tag> x, strongint<T, Tag> y) {
    return x.value >= y.value;
}

template <class T, class Tag>
constexpr bool operator>(strongint<T, Tag> x, strongint<T, Tag> y) {
    return x.value > y.value;
}

}  // namespace strongint

#endif  // STRONGINT_TYPE_H_INCLUDED_
