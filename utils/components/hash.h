#ifndef CPP_UTILS_HASH_H
#define CPP_UTILS_HASH_H

#include <string>
#include <fcntl.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <openssl/md5.h>

using namespace std;

namespace cpp_utils {
inline
unsigned long _get_file_size_from_fd(int fd) {
    struct stat statbuf;
    if (fstat(fd, &statbuf) < 0) return 0;
    else return statbuf.st_size;
}

inline
string hex_digest_md5(unsigned char *md) {
    char temp[3] = "";
    char Md5Hex[50] = "";
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(temp, "%02x", md[i]);
        strcat(Md5Hex, temp);
    }
    return string(Md5Hex);
}

inline
string get_chars_md5(unsigned char *data, unsigned long size) {
    unsigned char md5_result[MD5_DIGEST_LENGTH];
    MD5(data, size, md5_result);
    munmap(data, size);
    return hex_digest_md5(md5_result);
}

inline
string get_string_md5(string in_string) {
    return get_chars_md5((unsigned char *) in_string.c_str(), in_string.size());
}

inline
string get_file_md5(const string &file_path) {
    int fd;
    unsigned long file_size;
    char *file_buffer;

    fd = open(file_path.c_str(), O_RDONLY);
    if (fd < 0) {
        cerr << "Fail to open file: " << file_path << endl;
    }

    file_size = _get_file_size_from_fd(fd);

    file_buffer = static_cast<char *>(mmap((caddr_t) 0, file_size, PROT_READ, MAP_SHARED, fd, 0));

    return get_chars_md5((unsigned char *) file_buffer, file_size);
}
}

#endif //CPP_UTILS_HASH_H
