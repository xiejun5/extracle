/*************************************************************************
	> File Name: 16.inherit_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月28日 星期二 19时55分28秒
 ************************************************************************/

#include<iostream>
using namespace std;


class D {
public :
    D() { cout << "D constructor" << endl;} 
    ~D() {
        cout << "D destructor" << endl;
    }
};
class A {
public :
    A() = delete;
    A(int x, int y) { cout << "A constructor" << endl;}
    ~A() {
        cout << "A destructor" << endl;
    }
};

class B {
public :
    B() { cout << "B constructor" << endl;}
    ~B() {
        cout << "B destructor" << endl;
    }
};


class C : public D{
public :
    C() : a(3, 4) { cout << "C constructor" << endl;}
    ~C() {
        cout << "C dector" << endl;
    }

private:
    B b;
    A a;
};

int main() {
    C c;
    return 0;
}
