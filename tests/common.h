#ifndef CPP_UTILS_TEST_FILESYSTEM_COMMON_H
#define CPP_UTILS_TEST_FILESYSTEM_COMMON_H

#include <unistd.h>
#include <string>

using namespace std;

const char *CUR_DIR = get_current_dir_name();
const string CUR_DIR_STR = string(CUR_DIR);
const string CUR_EXE_STR = CUR_DIR_STR + "/run_test";
const char *CUR_EXE = CUR_DIR_STR.c_str();
const string SAMPLE_FILE_DIR = CUR_DIR_STR + "/../tests/sample/";
const string SAMPLE_TEST_IMG = SAMPLE_FILE_DIR + "ruby.png";
const string SAMPLE_TEST_CPP = SAMPLE_FILE_DIR + "test.cpp";
const string SAMPLE_TEST_CPP_MD5 = SAMPLE_FILE_DIR + "572909e2c9b5613fb96ce6f9b2e2f6d9.cpp";
const string SAMPLE_TEST_MKD = SAMPLE_FILE_DIR + "README.md";

#endif //CPP_UTILS_TEST_FILESYSTEM_COMMON_H
