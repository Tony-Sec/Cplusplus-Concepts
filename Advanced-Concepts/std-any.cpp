/**Dynamic values with -any-:
 * -any- is like a type ,any type can be contained,
 * making the corresponding casting to the type you want.
 *
 * Note: -any- can store any type at RUNTIME,
 * It is used for small objects because it requires more time than std :: variant,
 * which is in Compile-Time
 */

#include <iostream>
#include <any>

using namespace std;

int main() {
    // Initialize an empty any variable
    auto a = any{};
    a = string{"something"};
    cout<<"Variable a: "<< any_cast<string>(a)<<endl;

    //Cast for other variables types
    auto& str_ref = any_cast<string&>(a);
    auto str_copy = any_cast<string>(a);
    cout<<"Variable str_ref: "<<&str_ref<<endl;
    cout<<"Variable str_copy: "<<str_copy<<endl;

    a = 135.246f;
    auto flt = any_cast<float>(a);
    cout<<"Variable a: "<< any_cast<float>(a)<<endl;

    auto b = a;
    auto is_same =
            (a.type() == b.type()) &&
            (any_cast<float>(a) == any_cast<float>(b));
    // a equals b as they contain the same type and value
    cout<<"Variable b: "<< any_cast<float>(b)<<endl;
    cout<<"Variable a & b is_same?: "<< is_same <<endl;

    return 0;
}