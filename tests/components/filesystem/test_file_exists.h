#ifndef CPP_UTILS_TEST_FILESYSTEM_FILE_EXISTS_H
#define CPP_UTILS_TEST_FILESYSTEM_FILE_EXISTS_H

#include <string>
#include <gtest/gtest.h>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Filesystem_FileExists, Directory) {
  EXPECT_TRUE(cpp_utils::file_exists(CUR_DIR));
  EXPECT_TRUE(cpp_utils::file_exists(CUR_DIR_STR));
  EXPECT_FALSE(cpp_utils::file_exists(CUR_DIR_STR + "/abc"));
}

TEST(Filesystem_FileExists, File) {
  EXPECT_TRUE(cpp_utils::file_exists(CUR_EXE));
  EXPECT_TRUE(cpp_utils::file_exists(CUR_EXE_STR));
  EXPECT_FALSE(cpp_utils::file_exists(CUR_EXE_STR + ".exe"));
}

TEST(Filesystem_FileExists, RelativePath) {
  EXPECT_TRUE(cpp_utils::file_exists(CUR_DIR_STR));
  EXPECT_TRUE(cpp_utils::file_exists(CUR_DIR_STR + "/../"));
  EXPECT_TRUE(cpp_utils::file_exists(CUR_DIR_STR + "/../"));
}

#endif //CPP_UTILS_TEST_FILESYSTEM_FILE_EXISTS_H
