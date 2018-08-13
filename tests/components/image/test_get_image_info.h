#ifndef CPP_UTILS_TEST_IMAGE_GET_IMAGE_INFO_H
#define CPP_UTILS_TEST_IMAGE_GET_IMAGE_INFO_H

#include <gtest/gtest.h>
#include <string>

#include "../../common.h"
#include "utils.h"

using namespace std;

TEST(Image_GetImageInfo, Basic) {
  EXPECT_TRUE(cpp_utils::file_exists(SAMPLE_TEST_IMG));

  int file_size = 121514;
  int width = 512;
  int height = 512;
  vector<int> image_info = {file_size, width, height};
  EXPECT_EQ(image_info, cpp_utils::get_image_info(SAMPLE_TEST_IMG));
}

#endif //CPP_UTILS_TEST_IMAGE_GET_IMAGE_INFO_H
