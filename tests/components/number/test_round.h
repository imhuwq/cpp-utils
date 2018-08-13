#ifndef CPP_UTILS_TEST_NUMBER_ROUND_H
#define CPP_UTILS_TEST_NUMBER_ROUND_H

#include <gtest/gtest.h>

#include "utils.h"

TEST(Number_RoundTo, All) {
  EXPECT_EQ(1, cpp_utils::round_to(1, 0));
  EXPECT_EQ(1, cpp_utils::round_to(1, 2));

  EXPECT_EQ(1.0, cpp_utils::round_to(1.4, 0));
  EXPECT_EQ(2.0, cpp_utils::round_to(1.5, 0));

  EXPECT_EQ(1.1, cpp_utils::round_to(1.14, 1));
  EXPECT_EQ(1.2, cpp_utils::round_to(1.15, 1));

  EXPECT_TRUE(cpp_utils::equal(1.14, cpp_utils::round_to(1.14, 10)));
  EXPECT_TRUE(cpp_utils::equal(1.15, cpp_utils::round_to(1.15, 10)));
}

#endif //CPP_UTILS_TEST_NUMBER_ROUND_H
