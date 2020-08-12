/*************************************************************************
	> File Name: 19.interface.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月01日 星期六 23时13分13秒
 ************************************************************************/

#include<iostream>
using namespace std;


struct A {
    int x;
};
struct B : virtual A{
    void set(int x) {
        this->x = x;
        cout << &this->x << endl;
    }
};
struct C : virtual A{
    int get() {
        cout << &this->x << endl;
        return this->x;
    }
};
struct D : public B, public C{
    
};
int main() {
    A a;
    D d;
    B b;
    C c;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(d) << endl;
    d.set(9973);
    cout << d.get() << endl;
    return 0;
}
