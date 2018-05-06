#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main() {

    auto v = vector<int>{9,5,3,4,7,6,3,8,9};

    /*Auto-Initializing variable with lambda*/

    auto mylambda=[&](){
        return v.size();
    }();

    cout<<mylambda<<endl;

    /*Lambda as parameter*/

    for_each(v.begin(),v.end(),[](int elem){cout<<elem<<" ";});
    cout<<endl;

    /************************The capture block*****************************
    [=] all captured by value**********************************************
    [&] all captured by reference******************************************
    [&variable1,variable2] one captured by value,one captured by reference*
    the parameters can be initialized in the capture block ****************/

    int x=3,y=2,res;
    auto mylambda1 =[&x,y](int &res){
        x=x+y;
        //y=y+y; Error!!! assignment of read-only variable 'y'
                // because lambda is const by default if you want change this parameter made lambda mutable
        res=x+y;
    };

    cout<<"x: "<<x<<endl;
    mylambda1(res);
    cout<<"x: "<<x<<endl;
    cout<<"res: "<<res<<endl;

    /*Initializing variables in capture*/

    auto mylambda2 = [c=list<int>{4,2}](){
        for(auto v : c)
            cout << v <<endl;
    };
    mylambda2();

    return 0;
}