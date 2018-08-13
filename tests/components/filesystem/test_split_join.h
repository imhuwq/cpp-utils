#ifndef CPP_UTILS_TEST_FILESYSTEM_SPLIT_JOIN_H
#define CPP_UTILS_TEST_FILESYSTEM_SPLIT_JOIN_H

#include <string>
#include <gtest/gtest.h>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Filesystem_SplitPath, All) {
  pair<string, string> PathFile = cpp_utils::split_path(CUR_DIR_STR + "/abc");
  EXPECT_EQ(CUR_DIR_STR, PathFile.first);
  EXPECT_EQ("abc", PathFile.second);

  string test_path = "/path/to/file.ext";
  PathFile = cpp_utils::split_path(test_path);
  EXPECT_EQ("/path/to", PathFile.first);
  EXPECT_EQ("file.ext", PathFile.second);

  test_path = "/";
  PathFile = cpp_utils::split_path(test_path);
  EXPECT_EQ("", PathFile.first);
  EXPECT_EQ("", PathFile.second);

  test_path = ".";
  PathFile = cpp_utils::split_path(test_path);
  EXPECT_EQ(".", PathFile.first);
  EXPECT_EQ("", PathFile.second);

  test_path = "./test";
  PathFile = cpp_utils::split_path(test_path);
  EXPECT_EQ(".", PathFile.first);
  EXPECT_EQ("test", PathFile.second);

  test_path = "";
  PathFile = cpp_utils::split_path(test_path);
  EXPECT_EQ("", PathFile.first);
  EXPECT_EQ("", PathFile.second);
}

TEST(Filesystem_SplitExt, All) {
  pair<string, string> PathFile = cpp_utils::split_ext(CUR_DIR_STR + "/abc.o");
  EXPECT_EQ(CUR_DIR_STR + "/abc", PathFile.first);
  EXPECT_EQ(".o", PathFile.second);

  string test_path = "/path/to/file.ext";
  PathFile = cpp_utils::split_ext(test_path);
  EXPECT_EQ("/path/to/file", PathFile.first);
  EXPECT_EQ(".ext", PathFile.second);

  test_path = "/";
  PathFile = cpp_utils::split_ext(test_path);
  EXPECT_EQ("/", PathFile.first);
  EXPECT_EQ("", PathFile.second);

  test_path = ".";
  PathFile = cpp_utils::split_ext(test_path);
  EXPECT_EQ(".", PathFile.first);
  EXPECT_EQ("", PathFile.second);

  test_path = ".test";
  PathFile = cpp_utils::split_ext(test_path);
  EXPECT_EQ(".test", PathFile.first);
  EXPECT_EQ("", PathFile.second);

  test_path = "";
  PathFile = cpp_utils::split_ext(test_path);
  EXPECT_EQ("", PathFile.first);
  EXPECT_EQ("", PathFile.second);
}

TEST(Filesystem_Join, All) {
  EXPECT_EQ(cpp_utils::join_path("", ".ext"), ".ext");
  EXPECT_EQ(cpp_utils::join_path("", "/"), "/");
  EXPECT_EQ(cpp_utils::join_path("", "file.ext"), "file.ext");

  EXPECT_EQ(cpp_utils::join_path("/path/to/", "/file.ext"), "/path/to/file.ext");
  EXPECT_EQ(cpp_utils::join_path("/path/to/", "file.ext"), "/path/to/file.ext");
  EXPECT_EQ(cpp_utils::join_path("/", "/"), "/");

  EXPECT_EQ(cpp_utils::join_path("/path/to", "file.ext"), "/path/to/file.ext");
  EXPECT_EQ(cpp_utils::join_path("/path/to", ".ext"), "/path/to.ext");

}

#endif //CPP_UTILS_TEST_FILESYSTEM_SPLIT_JOIN_H
