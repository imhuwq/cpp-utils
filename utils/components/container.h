#ifndef CPP_UTILS_CONTAINER_H
#define CPP_UTILS_CONTAINER_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace cpp_utils {
template<typename T>
struct has_iterator {
 private:
  template<typename C>
  static char test(typename C::iterator *);

 public:
  enum {
    value = sizeof(test<T>(0)) == sizeof(char)
  };
};

template<typename Container>
inline
typename enable_if<has_iterator<Container>::value, bool>::type
item_exists(typename Container::value_type const &item, const Container &container) {
    return find(container.begin(), container.end(), item) != container.end();
};
}

#endif //CPP_UTILS_CONTAINER_H
