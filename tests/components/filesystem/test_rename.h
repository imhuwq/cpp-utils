#ifndef CPP_UTILS_TEST_FILESYSTEM_RENAME_H
#define CPP_UTILS_TEST_FILESYSTEM_RENAME_H

#include <string>
#include <gtest/gtest.h>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Filesystem_RenameDir, Basic) {
  string src_dir = CUR_DIR_STR + "/before_cpp_utils::rename";
  string dst_dir = CUR_DIR_STR + "/after_cpp_utils::rename";

  EXPECT_TRUE(cpp_utils::makedir(src_dir));
  EXPECT_TRUE(cpp_utils::rename(src_dir, dst_dir));
  EXPECT_TRUE(cpp_utils::remove(dst_dir));
}

TEST(Filesystem_RenameDir, SrcNotExists) {
  string src_dir = CUR_DIR_STR + "/before_cpp_utils::rename";
  string dst_dir = CUR_DIR_STR + "/after_cpp_utils::rename";

  EXPECT_FALSE(cpp_utils::rename(src_dir, dst_dir));
}

TEST(Filesystem_RenameDir, DstExists) {
  string src_dir = CUR_DIR_STR + "/before_cpp_utils::rename";
  string dst_dir = CUR_DIR_STR + "/after_cpp_utils::rename";

  EXPECT_TRUE(cpp_utils::makedir(dst_dir));
  EXPECT_FALSE(cpp_utils::rename(src_dir, dst_dir));
  EXPECT_TRUE(cpp_utils::remove(dst_dir));
}

TEST(Filesystem_RenameFile, Basic) {
  string src_file = CUR_EXE_STR;
  string dst_file = CUR_DIR_STR + "/runrun_test";

  EXPECT_TRUE(cpp_utils::rename(src_file, dst_file));
  EXPECT_TRUE(cpp_utils::rename(dst_file, src_file));
}

TEST(Filesystem_RenameFile, SrcNotExists) {
  string src_file = CUR_EXE_STR + "runrun";
  string dst_file = CUR_DIR_STR + "/runrun_test";

  EXPECT_FALSE(cpp_utils::rename(src_file, dst_file));
}

TEST(Filesystem_RenameFile, DstDirNotExists) {
  string src_file = CUR_EXE_STR;

  string dst_dir = CUR_DIR_STR + "/tttt";
  EXPECT_TRUE(cpp_utils::makedir(dst_dir, true));

  string dst_file = dst_dir + "/run/run_test";

  EXPECT_TRUE(cpp_utils::rename(src_file, dst_file));
  EXPECT_TRUE(cpp_utils::rename(dst_file, src_file));
  EXPECT_TRUE(cpp_utils::remove(dst_dir));
}

TEST(Filesystem_RenameFile2MD5, Basic) {
  string tgt_md5 = cpp_utils::rename_file_to_md5(SAMPLE_TEST_MKD);

  EXPECT_NE("", tgt_md5);
  EXPECT_EQ("", cpp_utils::rename_file_to_md5("/path/to/not/exists/file.ext"));
  EXPECT_EQ("", cpp_utils::rename_file_to_md5(CUR_DIR_STR));

  EXPECT_TRUE(cpp_utils::rename(tgt_md5, SAMPLE_TEST_MKD));
}

TEST(Filesystem_RenameFile2MD5, Unique) {
  string img_md5 = cpp_utils::rename_file_to_md5(SAMPLE_TEST_IMG);

  string mkd_md5 = cpp_utils::rename_file_to_md5(SAMPLE_TEST_MKD);

  EXPECT_NE(mkd_md5, img_md5);

  EXPECT_TRUE(cpp_utils::rename(img_md5, SAMPLE_TEST_IMG));
  EXPECT_TRUE(cpp_utils::rename(mkd_md5, SAMPLE_TEST_MKD));
}

TEST(Filesystem_RenameFile2MD5, NewExt) {
  string cpp_md5 = cpp_utils::rename_file_to_md5(SAMPLE_TEST_CPP, ".exe");
  EXPECT_TRUE(cpp_utils::file_exists(cpp_md5));
  EXPECT_EQ(".exe", cpp_utils::split_ext(cpp_md5).second);
  EXPECT_TRUE(cpp_utils::rename(cpp_md5, SAMPLE_TEST_CPP));
}

TEST(Filesystem_RenameFile2MD5, MD5IsSelf) {
  string cpp_md5 = cpp_utils::rename_file_to_md5(SAMPLE_TEST_CPP_MD5);
  EXPECT_EQ(cpp_md5, SAMPLE_TEST_CPP_MD5);
}

#endif //CPP_UTILS_TEST_FILESYSTEM_RENAME_H
