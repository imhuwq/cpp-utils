#ifndef CPP_UTILS_TEST_FILESYSTEM_GET_FILESIZE_H
#define CPP_UTILS_TEST_FILESYSTEM_GET_FILESIZE_H

#include <string>
#include <gtest/gtest.h>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Filesystem_GetFileSize, Basic) {
  EXPECT_EQ(cpp_utils::get_file_size(SAMPLE_TEST_CPP), 24);
}

TEST(Filesystem_GetFileSize, Directory) {
  EXPECT_EQ(cpp_utils::get_file_size(SAMPLE_FILE_DIR), 0);
}

TEST(Filesystem_GetFileSize, NotExists) {
  EXPECT_EQ(cpp_utils::get_file_size(SAMPLE_FILE_DIR + "/balabala.foobar"), 0);
}

#endif //CPP_UTILS_TEST_FILESYSTEM_GET_FILESIZE_H
