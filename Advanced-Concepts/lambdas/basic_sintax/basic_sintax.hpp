#ifndef LAMBDAS_BASIC_SINTAX_HPP
#define LAMBDAS_BASIC_SINTAX_HPP

#include <iostream>

using namespace std;

class Foo {
public:
    auto member_function() {
        auto a = 0;
        auto b = 1.0f;
        // Capture all variables by copy
        auto lambda_0 = [=]() { cout << a << b << m_; };
        // Capture all variables by reference
        auto lambda_1 = [&]() { cout << a << b << m_; };
        // Capture member variables by reference
        auto lambda_2 = [this]() { cout << m_; };
        // Capture member variables by copy
        auto lambda_3 = [*this]() { cout << m_; };
    }
private:
    int m_{};
};

#endif //LAMBDAS_BASIC_SINTAX_HPP
