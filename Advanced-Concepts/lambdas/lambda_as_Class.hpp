#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto x = 3; //Local Variable

class byValue {
    public:
        byValue(int x_) : x{x_} {}
        auto operator()(int v)const{
            return v > x;
        }
    private:
        int x{};
};

class byReference{
    public:
        byReference(int& x_) : x{x_} {}
        auto operator()(int v)const{
            return v > x;
        }
    private:
        int& x;
};

/*note: a lambda function is const by default.*/