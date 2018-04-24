#include <iostream>
#include <string>

using namespace std;

void your_name(){
    string name;
    cout << "What is your name?"<<endl;
    cin>>name;
    cout << "Hello, " << name << "!\n";
}

void your_age(){
    int age;
    cout << "What is your age?"<<endl;
    cin>>age;
    cout << "Your age is, " << age << "\n";
}

void func(void (* mutablefunc)() ){
    //...

    if(mutablefunc==your_name){
        cout << "Your choice 1.Name "<<endl;
        //...
    }
    if(mutablefunc==your_age){
        cout << "Your choice 2.Age "<<endl;
        //...
    }
    mutablefunc();
}

int main()
{
    void (* fptr)();    // declaracion de puntero-a-funcion
    int op;
    cout << "What function do you want? 1.Name 2.Age"<<endl;
    cin>>op;
    switch(op){
        case 1:
            fptr=your_name;
            break;
        case 2:
            fptr=your_age;
            break;
    }
    func(fptr);
    return 0;
}
