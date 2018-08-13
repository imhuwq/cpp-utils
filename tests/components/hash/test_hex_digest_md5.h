#ifndef CPP_UTILS_TEST_HEX_DIGEST_MD5_H
#define CPP_UTILS_TEST_HEX_DIGEST_MD5_H
#include <gtest/gtest.h>
#include <string>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Hash_Hex_Digest_MD5, Basic) {
  unsigned char hash[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                            0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7};

  EXPECT_NE(cpp_utils::hex_digest_md5(hash), "");
}

TEST(Hash_Hex_Digest_MD5, LengthIs32) {
  unsigned char hash[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                            0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7};

  EXPECT_EQ(cpp_utils::hex_digest_md5(hash).size(), 32);
  EXPECT_EQ(cpp_utils::hex_digest_md5(hash), "0001020304050607f0f1f2f3f4f5f6f7");
}

#endif //CPP_UTILS_TEST_HEX_DIGEST_MD5_H
