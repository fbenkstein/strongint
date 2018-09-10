#include <iostream>
#include <string>

#include <strongint.h>

#include <gtest/gtest.h>

using namespace strongint::literals;

template <class T, T x, T y>
struct is_same {};

template <class T, T x>
struct is_same<T, x, x> {
    static constexpr bool value = true;
};

#define LITERAL_TEST(__strongint_type, __base_type_macro, __value) \
    static_assert(is_same<strongint::__strongint_type::base_type,  \
                          (__value##_##__strongint_type).value,    \
                          __base_type_macro(__value)>::value,      \
                  "literal \"" #__value "_" #__strongint_type      \
                  "\" not correctly parsed")

#define U8_LITERAL_TEST(__value) LITERAL_TEST(u8, UINT8_C, __value)
#define I8_LITERAL_TEST(__value) LITERAL_TEST(i8, INT8_C, __value)
#define U16_LITERAL_TEST(__value) LITERAL_TEST(u16, UINT16_C, __value)
#define I16_LITERAL_TEST(__value) LITERAL_TEST(i16, INT16_C, __value)
#define U32_LITERAL_TEST(__value) LITERAL_TEST(u32, UINT32_C, __value)
#define I32_LITERAL_TEST(__value) LITERAL_TEST(i32, INT32_C, __value)
#define U64_LITERAL_TEST(__value) LITERAL_TEST(u64, UINT64_C, __value)
#define I64_LITERAL_TEST(__value) LITERAL_TEST(i64, INT64_C, __value)

U8_LITERAL_TEST(0);
U8_LITERAL_TEST(1);
U8_LITERAL_TEST(7);
U8_LITERAL_TEST(11);
U8_LITERAL_TEST(100);
U8_LITERAL_TEST(255);
U8_LITERAL_TEST(0xAb);
U8_LITERAL_TEST(0xff);
U8_LITERAL_TEST(0100);
U8_LITERAL_TEST(0377);
U8_LITERAL_TEST(0b10110);

I8_LITERAL_TEST(0);
I8_LITERAL_TEST(1);
I8_LITERAL_TEST(7);
I8_LITERAL_TEST(11);
I8_LITERAL_TEST(100);
I8_LITERAL_TEST(127);
I8_LITERAL_TEST(-127);
// XXX: Can this be made to work?
// I8_LITERAL_TEST(-128);

U32_LITERAL_TEST(0);
U32_LITERAL_TEST(1);
U32_LITERAL_TEST(7);
U32_LITERAL_TEST(11);
U32_LITERAL_TEST(100);
U32_LITERAL_TEST(1000);
U32_LITERAL_TEST(1234);
U32_LITERAL_TEST(0xDEADbeef);
U32_LITERAL_TEST(0xffffffff);
U32_LITERAL_TEST(07654321);
U32_LITERAL_TEST(0b10110);

I32_LITERAL_TEST(0);
I32_LITERAL_TEST(-0);
I32_LITERAL_TEST(1);
I32_LITERAL_TEST(-1);
I32_LITERAL_TEST(7);
I32_LITERAL_TEST(11);
I32_LITERAL_TEST(100);
I32_LITERAL_TEST(1000);
I32_LITERAL_TEST(1234);
I32_LITERAL_TEST(0xbadF00D);
I32_LITERAL_TEST(-0xbadF00D);
I32_LITERAL_TEST(0x7FFFFFF);
I32_LITERAL_TEST(0x8000000);  // Should this fail?
I32_LITERAL_TEST(2147483647);
// XXX: This should work:
// I32_LITERAL_TEST(2'147'483'647);
I32_LITERAL_TEST(07654321);
I32_LITERAL_TEST(-07654321);
I32_LITERAL_TEST(0b10110);

TEST(StrongIntU32Test, increment) {
    auto i = 10_u32;
    EXPECT_EQ(10u, (i++).value);
    EXPECT_EQ(11u, i.value);
    EXPECT_EQ(12u, (++i).value);
    EXPECT_EQ(12u, i.value);
}

TEST(StrongIntU32Test, shift) {
    auto i = 10_u32;
    EXPECT_EQ(40u, (i << 2_u32).value);
    EXPECT_EQ(40u, (i << 2_usize).value);
    EXPECT_EQ(40u, (i << 2).value);
    EXPECT_EQ(5u, (i >> 1).value);
}
