#include <iostream>
#include <list>
#include <cassert>
#include "propierties.hpp"

using namespace std;

int main() {

    /*Initializing variables in capture*/


    auto mylambda = [c=list<int>{4,2}](){   //lambda
        for(auto v : c) cout << v ;
    };
    mylambda(); // Output: 42


    auto obj = variables_in_capture{};      //lambda as class
    obj();     // Output: 42



    /*Mutating lambda member variables*/

    auto by_value=[]() {
        auto v = 7;
        auto lambda = [v]() mutable {
            cout << v << " ";
            ++v;
        };
        lambda();   //Output: 7  local v=8
        lambda();   //Output: 8  local v=9
        cout << v;  //v=7
    };

    auto by_reference=[]() {
        auto v = 7;
        auto lambda = [&v]() {
            cout << v << " ";
            ++v;
        };
        lambda();   //Output: 7 v:8
        lambda();   //Output: 8 v:9
        cout << v;  //v:9
    };

    by_value();     //Output: 7,8,7
    by_reference(); //Output: 7,8,9


    return 0;
}
