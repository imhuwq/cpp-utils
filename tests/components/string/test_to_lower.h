#ifndef CPP_UTILS_TEST_STRING_TO_LOWER_H
#define CPP_UTILS_TEST_STRING_TO_LOWER_H

#include <gtest/gtest.h>
#include <string>

#include "utils.h"

TEST(String_ToLower, Basic) {
  EXPECT_EQ("abcdefg", cpp_utils::to_lower("ABCDEFG"));
}

#endif //CPP_UTILS_TEST_STRING_TO_LOWER_H
