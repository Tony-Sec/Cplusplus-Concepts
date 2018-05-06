#ifndef PROPERTIES_PROPIERTIES_HPP
#define PROPERTIES_PROPIERTIES_HPP

using namespace std;

class variables_in_capture {
public:
    variables_in_capture() : c{4, 2} {}
    auto operator()()const->void{
        for(auto v : c)
            cout << v;
    }
private:
    list<int> c;
};


#endif //PROPERTIES_PROPIERTIES_HPP
