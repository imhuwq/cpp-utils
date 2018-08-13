#ifndef CPP_UTILS_STRING_H
#define CPP_UTILS_STRING_H

#include <string>
#include <sstream>
#include <type_traits>
#include <algorithm>

#include "container.h"
#include "../libs/utf8.h"

using namespace std;

namespace cpp_utils {
inline
string to_lower(const string &in_string) {
    string out_string = in_string;
    transform(out_string.begin(), out_string.end(), out_string.begin(), ::tolower);
    return out_string;
}

template<typename T>
inline
string to_string(const T &value) {
    ostringstream out_stream;
    out_stream << value;
    return out_stream.str();
}

template<typename Iter>
inline
string to_string(Iter it, Iter end, const string &delimiter) {
    if (it == end) return "";

    int tail = delimiter.empty() ? 1 : 2;
    ostringstream output;
    for (; it != end; it++) {
        output << *it << delimiter << " ";
    }

    return output.str().substr(0, output.tellp() - tail);
}

template<typename Container>
inline
typename enable_if<cpp_utils::has_iterator<Container>::value, string>::type
to_string(const Container &container, const string delimiter) {
    if (container.empty()) return "";

    int tail = delimiter.empty() ? 1 : 2;
    ostringstream output;
    auto it = container.begin(), end = container.end();
    for (; it != end; it++) {
        output << *it << delimiter << " ";
    }
    return output.str().substr(0, output.tellp() - tail);
};

inline
string fix_utf8_string(const string &in_string) {
    string out_string;
    utf8::replace_invalid(in_string.begin(), in_string.end(), back_inserter(out_string));
    return out_string;
}
}

#endif //CPP_UTILS_STRING_H
