#ifndef CPP_UTILS_TEST_NUMBER_NEAREST_POW_OF_2_H
#define CPP_UTILS_TEST_NUMBER_NEAREST_POW_OF_2_H

#include <gtest/gtest.h>

#include "utils.h"

TEST(Number_NearestPowof2, Basic) {
  EXPECT_EQ(1, cpp_utils::nearest_pow_of_2(0));
  EXPECT_EQ(1, cpp_utils::nearest_pow_of_2(1));
  EXPECT_EQ(4, cpp_utils::nearest_pow_of_2(5));
  EXPECT_EQ(8, cpp_utils::nearest_pow_of_2(6));
}

TEST(Number_NearestPowof2, Limitation) {
  EXPECT_EQ(0x7fffffff, cpp_utils::nearest_pow_of_2(0x7fffffff));
}

TEST(Number_NearestPowof2, Negative) {
  EXPECT_EQ(0, cpp_utils::nearest_pow_of_2(-1));
  EXPECT_EQ(0, cpp_utils::nearest_pow_of_2(-5));
  EXPECT_EQ(0, cpp_utils::nearest_pow_of_2(-6));
}

#endif //CPP_UTILS_TEST_NUMBER_NEAREST_POW_OF_2_H
