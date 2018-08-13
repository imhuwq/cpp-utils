#ifndef CPP_UTILS_TEST_FILESYSTEM_ABSOLUTE_PATH_H
#define CPP_UTILS_TEST_FILESYSTEM_ABSOLUTE_PATH_H

#include <string>
#include <iostream>
#include <gtest/gtest.h>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Filesystem_AbsPath, FromRelative) {
  EXPECT_EQ(cpp_utils::absolute_path("."), CUR_DIR_STR);
}

TEST(Filesystem_AbsPath, FromAbsolute) {
  EXPECT_EQ(cpp_utils::absolute_path(CUR_DIR_STR), CUR_DIR_STR);
}

TEST(Filesystem_AbsPath, FromNotExists) {
  EXPECT_NE(cpp_utils::absolute_path(CUR_DIR_STR + "/abc/def"), CUR_DIR_STR + "/abc/def");
  EXPECT_EQ(cpp_utils::absolute_path(CUR_DIR_STR + "/abc/def"), string(""));
}

TEST(Filesystem_AbsPath, FromEmpty) {
  EXPECT_EQ(cpp_utils::absolute_path(""), string(""));
}

#endif //CPP_UTILS_TEST_FILESYSTEM_ABSOLUTE_PATH_H
