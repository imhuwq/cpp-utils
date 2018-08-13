#ifndef CPP_UTILS_IMAGE_H
#define CPP_UTILS_IMAGE_H

#include <vector>

#include <opencv2/opencv.hpp>
#include <boost/filesystem.hpp>

using namespace std;

namespace cpp_utils {
inline
vector<int> get_image_info(const string &image_path) {
    namespace fs = boost::filesystem;

    int file_size = fs::file_size(image_path);
    cv::Mat mat = cv::imread(image_path);
    int width = mat.cols;
    int height = mat.rows;

    return {file_size, width, height};
}
}

#endif //FBX_UTILS_IMAGE_H
