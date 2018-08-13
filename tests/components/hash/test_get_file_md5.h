#ifndef CPP_UTILS_TEST_HASH_GET_FILE_MD5_H
#define CPP_UTILS_TEST_HASH_GET_FILE_MD5_H

#include <gtest/gtest.h>
#include <string>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Hash_GetFileMD5, Basic) {
  string the_cpp_file = CUR_DIR_STR + "/../test.cpp";
  string the_md_file = CUR_DIR_STR + "/../README.md";

  EXPECT_NE("", cpp_utils::get_file_md5(the_cpp_file));
  EXPECT_NE("", cpp_utils::get_file_md5(the_md_file));

  EXPECT_NE(cpp_utils::get_file_md5(the_md_file), cpp_utils::get_file_md5(the_cpp_file));
}

#endif //CPP_UTILS_TEST_HASH_GET_FILE_MD5_H
