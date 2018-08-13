#ifndef CPP_UTILS_FILESYSTEM_H
#define CPP_UTILS_FILESYSTEM_H

#include <map>
#include <climits>
#include <string>
#include <boost/filesystem.hpp>

#include "hash.h"

using namespace std;

namespace cpp_utils {
inline
bool file_exists(const string &file_path) {
    return boost::filesystem::exists(file_path);
}

inline
string absolute_path(const string &file_path) {
    if (!file_exists(file_path)) return string("");

    char resolved_path[PATH_MAX];
    realpath(file_path.c_str(), resolved_path);
    return string(resolved_path);
}

inline
pair<string, string> split_path(const string &file_path) {
    if (file_path == ".") return {".", ""};

    char sep = '/';
    size_t i = file_path.rfind(sep, file_path.length());
    if (i != string::npos) {
        string path = file_path.substr(0, i);
        string name = file_path.substr(i + 1, file_path.length() - i);
        return {path, name};
    } else {
        return {"", file_path};
    }
}

inline
pair<string, string> split_ext(string file_path) {
    char sep = '.';

    string start;
    if (file_path.front() == '.') {
        file_path = string(file_path.begin() + 1, file_path.end());
        start = ".";
    } else {
        file_path = file_path;
        start = "";
    }

    size_t i = file_path.rfind(sep, file_path.length());
    if (i != string::npos) {
        string name = file_path.substr(0, i);
        name = start + name;
        string ext = file_path.substr(i, file_path.length() - i);
        return {name, ext};
    } else {
        string name = start + file_path;
        string ext = "";
        return {name, ext};
    }
}

/**
 * 以 "/" 合并路径
 *  当 base 为空, 直接返回 append
 *  当 base 不为空, 且以 "/" 结尾, 则 base 被当做文件夹, base 和 append 以一个 "/" (只有一个) 拼接在一起
 *  当 base 不为空, 且不以 "/" 结尾, 则 base 是文件夹还是文件由 append 决定:
 *    append 以 "." 开头, 则 base 是文件, base 和 append 直接拼接在一起
 *    append 不以 "." 开头, 则 base 是文件夹, base 和 append 以一个 "/" (只有一个) 拼接在一起
 */
inline
string join_path(string base, string append) {
    string joiner = "/";

    if (base.empty()) {
        base = "";
        joiner = "";
    } else {
        if (base.back() == '/' and append.front() == '/') {
            joiner = "";
            base = string(base.begin(), base.end() - 1);
            append = string(append.begin() + 1, append.end());
        }
        if (base.back() == '/' and append.front() != '/') joiner = "";
        if (base.back() != '/' and append.front() == '.') joiner = "";
        if (base.back() != '/' and append.front() != '.') joiner = "/";
    }

    return base + joiner + append;
}

inline
bool makedir(const string &path, bool force = true) {
    namespace fs = boost::filesystem;
    if (file_exists(path)) return force;
    return fs::create_directories(path);
}

inline
bool remove(const string &path) {
    namespace fs = boost::filesystem;
    if (!file_exists(path)) return true;
    fs::remove_all(path);
    return true;
}

inline
bool rename(const string &src, const string &dst, bool force = false) {
    namespace fs = boost::filesystem;
    if (!fs::exists(src)) return false;
    if (fs::exists(dst)) {
        if (force) remove(dst);
        else return false;
    }

    if (fs::is_directory(dst)) fs::create_directories(dst);
    else fs::create_directories(fs::path(dst).parent_path());
    fs::rename(src, dst);
    return true;
}

/**
 * 把文件的名字改为其内容的 MD5, 不指定 new_ext 的话文件后缀保持不变
 */
inline
string rename_file_to_md5(const string &file_path, string new_ext = "") {
    namespace fs = boost::filesystem;

    if (!file_exists(file_path)) return "";
    if (fs::is_directory(file_path)) return "";

    string file_content_md5 = cpp_utils::get_file_md5(file_path);
    pair<string, string> path_and_name = split_path(file_path);
    string new_path = join_path(path_and_name.first, file_content_md5);

    if (new_ext.empty()) new_path += fs::extension(file_path);
    else new_path += new_ext;

    if (!file_exists(new_path)) fs::rename(file_path, new_path);
    return new_path;
}

/**
 * 遍历目标文件路径(及其子孙路径), 获取每一个文件夹及其中的文件
 * @param file_path                         被遍历的文件夹路径
 * @return                                  一个 map, key 是一个文件夹路径, value 是该文件夹下所有的文件
 */
inline
map<string, vector<string>> walk_dir(const string &file_path) {
    namespace fs = boost::filesystem;

    map<string, vector<string>> dirs_and_files;
    if (!fs::is_directory(file_path)) return dirs_and_files;

    for (fs::recursive_directory_iterator it(file_path), eit; it != eit; ++it) {
        if (fs::is_directory(it->path())) {
            dirs_and_files[it->path().string()] = {};
        } else {
            dirs_and_files[it->path().parent_path().string()].push_back(it->path().filename().string());
        }
    }
    return dirs_and_files;
}

inline
int get_file_size(const string &file_path) {
    namespace fs = boost::filesystem;
    if (!file_exists(file_path)) return 0;
    if (fs::is_directory(file_path)) return 0;
    return (int) fs::file_size(file_path);
}
};

#endif //CPP_UTILS_FILESYSTEM_H
