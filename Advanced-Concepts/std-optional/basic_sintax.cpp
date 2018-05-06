#include <iostream>
#include <functional>
#include <vector>
#include <experimental/optional>
#include <algorithm>

using namespace std;

int main() {

    auto a = experimental::optional<int>{};
    auto b = experimental::optional<int>{2};
    auto vec1 = vector<experimental::optional<int>>{{3}, {0}, {1}, {0}, {2}};
    auto vec2 = vector<experimental::optional<int>>{{3}, {}, {1}, {}, {2}};
    sort(vec2.begin(), vec2.end()); //vec2 = {{},{},{1},{2},{3}}

    /*Optional values are pointers*/
    cout<<*a<<*b<<endl;     //Output: 0 2
    cout<<(*a<*b)<<endl;    //Output: 1(True)
    cout<<(a<b)<<endl;      //Output: 1(True)

    for(auto& elem : vec1) cout<<*elem<<" ";//Output: 0 0 1 2 3
    cout<<endl;
    for(auto& elem : vec2) cout<<*elem<<" ";//Output: 3 1 1 2 3
                                            // Logic Error!!! 0 and 1 positions are null pointers.


    return 0;
}