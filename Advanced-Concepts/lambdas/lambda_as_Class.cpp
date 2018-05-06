#include <iostream>
#include "lambda_as_Class.hpp"

using namespace std;

int main() {
    auto x = 3;//Local Variable

    /**************************** Lambda by value ****************************/
    /*Lambda function*/

    auto by_value = [x](int y) {
        return y > x;
    };
    auto lambda_function_by_value = by_value(5);

    /*Lambda function by value as class*/
    auto obj = byValue{x};
    auto lambda_as_Class_by_value = obj(5);


    cout<<lambda_function_by_value<<endl; // test equals true
    cout<<lambda_as_Class_by_value<<endl; // test equals true



    /**************************** Lambda by reference ****************************/
    /*Lambda function*/
    auto by_reference = [&x](int y) {
        return y > x;
    };
    auto lambda_function_by_reference = by_reference(5);

    /*Lambda function by reference as class*/

    auto obj2 = byReference{x};
    auto lambda_as_Class_by_reference = obj2(5);


    cout<<lambda_function_by_reference<<endl; // test equals true
    cout<<lambda_as_Class_by_reference<<endl; // test equals true

    return 0;
}
