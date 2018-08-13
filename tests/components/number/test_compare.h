#ifndef CPP_UTILS_TEST_NUMBER_COMPARE_H
#define CPP_UTILS_TEST_NUMBER_COMPARE_H

#include <gtest/gtest.h>

#include "utils.h"

TEST(Number_Compare, equal) {
  EXPECT_TRUE(cpp_utils::equal(1, 1));
  EXPECT_TRUE(cpp_utils::equal(1.0, 1.0));
  EXPECT_FALSE(cpp_utils::equal(1, 2));
  EXPECT_FALSE(cpp_utils::equal(2, 1));
  EXPECT_FALSE(cpp_utils::equal(1.351, 1.35));

  EXPECT_TRUE(cpp_utils::equal(1E-12, 1E-12));
  EXPECT_FALSE(cpp_utils::equal(1E-12, 1E-11));
  EXPECT_TRUE(cpp_utils::equal(1E-12, 1E-13));  // 超过　１E-12　后比较就失效了
  EXPECT_TRUE(cpp_utils::equal(1E-13, 1E-14));  // 超过　１E-12　后比较就失效了
}

TEST(Number_Compare_Tolerance, equal) {
  EXPECT_TRUE(cpp_utils::equal(1, 1, 0));
  EXPECT_TRUE(cpp_utils::equal(1.0, 1.0, 1));
  EXPECT_FALSE(cpp_utils::equal(1, 2, 0));
  EXPECT_FALSE(cpp_utils::equal(2, 1, 0));

  EXPECT_TRUE(cpp_utils::equal(1.351, 1.35, 2));
  EXPECT_FALSE(cpp_utils::equal(1.351, 1.35, 3));
}

TEST(Number_Compare, more) {
  EXPECT_FALSE(cpp_utils::more(1, 1));
  EXPECT_FALSE(cpp_utils::more(1.0, 1.0));
  EXPECT_FALSE(cpp_utils::more(1, 2));
  EXPECT_TRUE(cpp_utils::more(2, 1));
  EXPECT_TRUE(cpp_utils::more(1.351, 1.35));

  EXPECT_FALSE(cpp_utils::more(1E-12, 1E-12));
  EXPECT_FALSE(cpp_utils::more(1E-12, 1E-11));
  EXPECT_FALSE(cpp_utils::more(1E-12, 1E-13));  // 超过　１E-12　后比较就失效了
  EXPECT_FALSE(cpp_utils::more(1E-13, 1E-14));  // 超过　１E-12　后比较就失效了
}

TEST(Number_Compare, less) {
  EXPECT_FALSE(cpp_utils::less(1, 1));
  EXPECT_FALSE(cpp_utils::less(1.0, 1.0));
  EXPECT_TRUE(cpp_utils::less(1, 2));
  EXPECT_FALSE(cpp_utils::less(2, 1));
  EXPECT_FALSE(cpp_utils::less(1.351, 1.35));

  EXPECT_FALSE(cpp_utils::less(1E-12, 1E-12));
  EXPECT_TRUE(cpp_utils::less(1E-12, 1E-11));
  EXPECT_FALSE(cpp_utils::less(1E-12, 1E-13));  // 超过　１E-12　后比较就失效了
  EXPECT_FALSE(cpp_utils::less(1E-13, 1E-14));  // 超过　１E-12　后比较就失效了
}

#endif //CPP_UTILS_TEST_NUMBER_COMPARE_H
