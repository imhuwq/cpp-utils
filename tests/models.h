#ifndef CPP_UTILS_TEST_CONTAINER_DATA_TYPE_H
#define CPP_UTILS_TEST_CONTAINER_DATA_TYPE_H

#include <string>
#include <iostream>

using namespace std;

class KeyValue {
  friend bool operator==(const KeyValue &lhs, const KeyValue &rhs);

  friend ostream &operator<<(ostream &os, const KeyValue &rhs);

 private:
  string mKey;
  double mValue;
 public:
  KeyValue(const string pKey, const double pValue) : mValue(pValue) {
    mKey = std::move(pKey);
  }

};

bool operator==(const KeyValue &lhs, const KeyValue &rhs) {
  return lhs.mKey == rhs.mKey and lhs.mValue == rhs.mValue;
}

ostream &operator<<(ostream &os, const KeyValue &rhs) {
  os << "(\"" << rhs.mKey << "\": " << rhs.mValue << ")";
  return os;
}

#endif //CPP_UTILS_TEST_CONTAINER_DATA_TYPE_H
