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

#ifndef STRONGINT_STDINT_H_INCLUDED_
#define STRONGINT_STDINT_H_INCLUDED_

#include "strongint_type.h"

#include <cstdint>

namespace strongint {
namespace detail {
struct u8_tag {};
struct i8_tag {};
struct u16_tag {};
struct i16_tag {};
struct u32_tag {};
struct i32_tag {};
struct u64_tag {};
struct i64_tag {};
struct usize_tag {};
struct isize_tag {};
}  // namespace detail

using u8 = strongint<std::uint8_t, detail::u8_tag>;
using i8 = strongint<std::int8_t, detail::i8_tag>;
using u16 = strongint<std::uint16_t, detail::u16_tag>;
using i16 = strongint<std::int16_t, detail::i16_tag>;
using u32 = strongint<std::uint32_t, detail::u32_tag>;
using i32 = strongint<std::int32_t, detail::i32_tag>;
using u64 = strongint<std::uint64_t, detail::u64_tag>;
using i64 = strongint<std::int64_t, detail::i64_tag>;
using usize = strongint<std::size_t, detail::usize_tag>;
using isize = strongint<std::ptrdiff_t, detail::isize_tag>;
}  // namespace strongint

#endif  // STRONGINT_STDINT_H_INCLUDED_
