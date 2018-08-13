#ifndef CPP_UTILS_TEST_FILESYSTEM_MAKE_RENAME_H
#define CPP_UTILS_TEST_FILESYSTEM_MAKE_RENAME_H

#include <string>
#include <gtest/gtest.h>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Filesystem_MakeRemove, Basic) {
  EXPECT_TRUE(cpp_utils::makedir(CUR_DIR_STR + "/test_cpp_utils::makedir"));
  EXPECT_TRUE(cpp_utils::remove(CUR_DIR_STR + "/test_cpp_utils::makedir"));
}

TEST(Filesystem_MakeDir, ForceFlag) {
  EXPECT_TRUE(cpp_utils::makedir(CUR_DIR_STR + "/test_cpp_utils::makedir", true));
  EXPECT_FALSE(cpp_utils::makedir(CUR_DIR_STR + "/test_cpp_utils::makedir", false));
}

TEST(Filesystem_MakeRemove, MultiLevels) {
  EXPECT_TRUE(cpp_utils::makedir(CUR_DIR_STR + "/test_cpp_utils::makedir/cpp_utils::makedir", true));
  EXPECT_FALSE(cpp_utils::makedir(CUR_DIR_STR + "/test_cpp_utils::makedir/cpp_utils::makedir", false));

  EXPECT_TRUE(cpp_utils::remove(CUR_DIR_STR + "/test_cpp_utils::makedir/cpp_utils::makedir"));
  EXPECT_TRUE(cpp_utils::remove(CUR_DIR_STR + "/test_cpp_utils::makedir"));
}

#endif //CPP_UTILS_TEST_FILESYSTEM_MAKE_RENAME_H
