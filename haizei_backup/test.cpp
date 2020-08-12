/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月08日 星期六 06时04分39秒
 ************************************************************************/

#include<iostream>
using namespace std;


class A {
public : 
    A() {
        cout << "A constructor" << this<< endl;
    }
    virtual void run() {
        cout << "A run" << endl;
    }
};

class B : public A{
public :
    B() {
        cout << "B constructor" << this<< endl;
    }
    void run() override {
        A::run();
        cout << " B run " << endl;
    }
};

int main() {
    B b;
    A &s = b;
    A *c = &b;
    b.run();
    s.run();
    c->run();
    cout << endl;

    b.run();
    return 0;
}
