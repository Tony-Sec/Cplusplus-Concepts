#include <iostream>
#include <functional>
#include <algorithm>
#include <set>
#include <optional> //C++17


using namespace std;

bool find(string s, string aux){
    if(s.find(aux)==s.npos) return 0;
    else return 1;

}
set<string> set_word(string aux){
    set<string> o;
    o.insert(aux);
    return o;
}
optional<set<string>>
get_set(const string& s, const string& aux) {
    return find(s, aux) ?
           make_optional(set_word(aux)):
           optional<set<string>>{};
}

int main() {

    string s = "The optional variables are FUN!!!!";

    /*Optional return values*/

    try{
        auto conjunto=get_set(s, "FUN");
        cout<<conjunto.value().size()<<endl;
        for(auto elem : conjunto.value()) cout<<elem;
    }catch(exception e){
        cout<<e.what();
    }

    return 0;
}