#ifndef CPP_UTILS_TEST_HASH_GET_STRING_MD5_H
#define CPP_UTILS_TEST_HASH_GET_STRING_MD5_H

#include <gtest/gtest.h>
#include <string>

#include "utils.h"

using namespace std;

TEST(Hash_GetStringMD5, Basic) {
  string the_string = "Hello and Bye";
  string md5_of_the_string = "7e473f079a34dfc9cb6dea00892100ea";
  EXPECT_EQ(md5_of_the_string, cpp_utils::get_string_md5(the_string));
}

#endif //CPP_UTILS_TEST_HASH_GET_STRING_MD5_H
