#ifndef CPP_UTILS_NUMBER_H
#define CPP_UTILS_NUMBER_H

#include <cmath>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <iostream>

using namespace std;

namespace cpp_utils {
const double TOLERANCE = 1E-12;  // 比较数字时默认的精度

/**
 * 请注意, 当\pNumber 为浮点数时, 即使 \precision 为 0, 返回的数也会有一个小数, 即 round_to(3.1, 0) 返回 3.0
 *       小数点的位数不会增加, 即 round_to(10, 1) 返回 10
 */
template<typename T>
inline
typename enable_if<is_arithmetic<T>::value, T>::type
round_to(const T &num, const unsigned int precision) {
    const double powered = pow(10, precision);
    return round(num * powered) / powered;
}

inline
int nearest_pow_of_2(int number) {
    if (number < 0) return 0;
    if (number == 0) return 1;
    if (number >= 0x7fffffff) return 0x7fffffff;
    return (int) exp2(round(log2(number)));
}

template<typename T>
inline
typename enable_if<is_arithmetic<T>::value, bool>::type
equal(const T &num1, const T &num2) {
    return abs(num1 - num2) < TOLERANCE;
}

template<typename T>
inline
typename enable_if<is_arithmetic<T>::value, bool>::type
equal(const T &num1, const T &num2, const unsigned int &precision) {
    return round_to(abs(num1 - num2), precision) < TOLERANCE;
}

template<typename T>
inline
typename enable_if<is_arithmetic<T>::value, bool>::type
less(const T &num1, const T &num2) {
    return num1 + TOLERANCE <= num2;
}

template<typename T>
inline
typename enable_if<is_arithmetic<T>::value, bool>::type
more(const T &num1, const T &num2) {
    return num1 >= num2 + TOLERANCE;
}

template<typename T>
inline
vector<typename enable_if<is_arithmetic<T>::value, T>::type>
range(const T &start_num, const T &end_num, const T &step) {
    vector<T> numbers;
    if (step == 0) return numbers;

    T number = start_num;
    if (step < 0 and start_num >= end_num) {
        while (more(number, end_num)) {
            numbers.emplace_back(number);
            number += step;
        }
        numbers.emplace_back(end_num);
        return numbers;

    } else if (step > 0 and start_num <= end_num) {
        while (less(number, end_num)) {
            numbers.emplace_back(number);
            number += step;
        }
        numbers.emplace_back(end_num);
        return numbers;
    }

    return numbers;
}

}

#endif //CPP_UTILS_NUMBER_H
