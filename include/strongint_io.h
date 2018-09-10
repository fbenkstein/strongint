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

#ifndef STRONGINT_IO_H_INCLUDED_
#define STRONGINT_IO_H_INCLUDED_

#include "strongint_stdint.h"

#include <algorithm>
#include <istream>
#include <limits>
#include <ostream>

namespace strongint {
template <class T, class Tag>
std::ostream& operator<<(std::ostream& os, strongint<T, Tag> value) {
    return os << value.value;
}

template <class Tag>
std::ostream& operator<<(std::ostream& os, strongint<std::uint8_t, Tag> value) {
    return os << static_cast<unsigned>(value.value);
}

template <class Tag>
std::ostream& operator<<(std::ostream& os, strongint<std::int8_t, Tag> value) {
    return os << static_cast<int>(value.value);
}

template <class Tag>
std::ostream& operator<<(std::ostream& os, strongint<char, Tag> value) {
    return os << static_cast<int>(value.value);
}

template <class T, class Tag>
std::istream& operator>>(std::istream& is, strongint<T, Tag>& value) {
    return is >> value.value;
}

template <class Tag>
std::istream& operator<<(std::istream& is, strongint<std::uint8_t, Tag> value) {
    unsigned tmp;
    is >> tmp;
    value.value = std::min(
        static_cast<unsigned>(std::numeric_limits<std::uint8_t>::max()), tmp);
    return is;
}

template <class Tag>
std::istream& operator<<(std::istream& is, strongint<std::int8_t, Tag> value) {
    int tmp;
    is >> tmp;
    value.value = std::max(
        static_cast<int>(std::numeric_limits<std::int8_t>::min()),
        std::min(static_cast<int>(std::numeric_limits<std::int8_t>::max()),
                 tmp));
    return is;
}
}  // namespace strongint

#endif  // STRONGINT_IO_H_INCLUDED_
