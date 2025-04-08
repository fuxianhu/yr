#include <iostream>
#include <climits> // 或者 <limits.h>
#include <cstdint> // C++11及以后
#include <cfloat>  // 对于浮点数
 
int main() {
    // 整数类型
    std::cout << "int min: " << INT_MIN << ", int max: " << INT_MAX << std::endl;
    std::cout << "char min: " << CHAR_MIN << ", char max: " << CHAR_MAX << std::endl;
    std::cout << "short min: " << SHRT_MIN << ", short max: " << SHRT_MAX << std::endl;
    std::cout << "long min: " << LONG_MIN << ", long max: " << LONG_MAX << std::endl;
    std::cout << "long long min: " << LLONG_MIN << ", long long max: " << LLONG_MAX << std::endl;
 
    // 无符号整数类型
    std::cout << "unsigned int max: " << UINT_MAX << std::endl;
    std::cout << "unsigned char max: " << UCHAR_MAX << std::endl;
    std::cout << "unsigned short max: " << USHRT_MAX << std::endl;
    std::cout << "unsigned long max: " << ULONG_MAX << std::endl;
    std::cout << "unsigned long long max: " << ULLONG_MAX << std::endl;
 
    // 浮点类型
    std::cout << "float min: " << FLT_MIN << ", float max: " << FLT_MAX << std::endl;
    std::cout << "double min: " << DBL_MIN << ", double max: " << DBL_MAX << std::endl;
    std::cout << "long double min: " << LDBL_MIN << ", long double max: " << LDBL_MAX << std::endl;

    return 0;
}
