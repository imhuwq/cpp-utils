#ifndef CPP_UTILS_TEST_NUMBER_RANGE_H
#define CPP_UTILS_TEST_NUMBER_RANGE_H

#include <gtest/gtest.h>

#include "utils.h"

TEST(Number_Range, Increase) {
  vector<int> vec1 = {1, 2, 3};
  EXPECT_EQ(cpp_utils::to_string(vec1, ","), cpp_utils::to_string(cpp_utils::range(1, 3, 1), ","));

  vector<double> vec2 = {1.0, 1.1, 1.2};
  EXPECT_EQ(cpp_utils::to_string(vec2, ","), cpp_utils::to_string(cpp_utils::range(1.0, 1.2, 0.1), ","));

  vector<double> vec3 = {1.0, 1.01, 1.02, 1.025};
  EXPECT_EQ(cpp_utils::to_string(vec3, ","), cpp_utils::to_string(cpp_utils::range(1.00, 1.025, 0.01), ","));

  vector<double> vec4 = {};
  EXPECT_EQ(cpp_utils::to_string(vec4, ","), cpp_utils::to_string(cpp_utils::range(1.00, 1.025, 0.0), ","));

  vector<int> vec5 = {-3, -2, -1};
  EXPECT_EQ(cpp_utils::to_string(vec5, ","), cpp_utils::to_string(cpp_utils::range(-3, -1, 1), ","));

  vector<double> vec6 = {-1.2, -1.1, -1.0};
  EXPECT_EQ(cpp_utils::to_string(vec6, ","), cpp_utils::to_string(cpp_utils::range(-1.2, -1.0, 0.1), ","));

  vector<double> vec7 = {-1.25, -1.15, -1.05, -1.02};
  EXPECT_EQ(cpp_utils::to_string(vec7, ","), cpp_utils::to_string(cpp_utils::range(-1.25, -1.02, 0.1), ","));
}

TEST(Number_Range, Decrease) {
  vector<int> vec1 = {3, 2, 1};
  EXPECT_EQ(cpp_utils::to_string(vec1, ","), cpp_utils::to_string(cpp_utils::range(3, 1, -1), ","));

  vector<double> vec2 = {1.2, 1.1, 1.0};
  EXPECT_EQ(cpp_utils::to_string(vec2, ","), cpp_utils::to_string(cpp_utils::range(1.2, 1.0, -0.1), ","));

  vector<double> vec3 = {1.025, 1.015, 1.005, 1.0};
  EXPECT_EQ(cpp_utils::to_string(vec3, ","), cpp_utils::to_string(cpp_utils::range(1.025, 1.0, -0.01), ","));

  vector<double> vec4 = {};
  EXPECT_EQ(cpp_utils::to_string(vec4, ","), cpp_utils::to_string(cpp_utils::range(1.025, 1.00, 0.0), ","));

  vector<int> vec5 = {-1, -2, -3};
  EXPECT_EQ(cpp_utils::to_string(vec5, ","), cpp_utils::to_string(cpp_utils::range(-1, -3, -1), ","));

  vector<double> vec6 = {-1.0, -1.1, -1.2};
  EXPECT_EQ(cpp_utils::to_string(vec6, ","), cpp_utils::to_string(cpp_utils::range(-1.0, -1.2, -0.1), ","));

  vector<double> vec7 = {-1.02, -1.12, -1.22, -1.25};
  EXPECT_EQ(cpp_utils::to_string(vec7, ","), cpp_utils::to_string(cpp_utils::range(-1.02, -1.25, -0.1), ","));
}
#endif //CPP_UTILS_TEST_NUMBER_RANGE_H
