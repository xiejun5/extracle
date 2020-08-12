/*************************************************************************
	> File Name: test_virtual.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月11日 星期二 05时32分12秒
 ************************************************************************/

#include<iostream>
using namespace std;


class A {
public :
    virtual void say() {
        cout << "A say I am father" << endl;
    }
private :
    int x;
};


class B : public A{
public :
    void say() override {
        A::say();
        cout << "B say I want fly" << endl;
    }
};

int main() {
    A a;
    a.say();
    B b;
    b.say();

    return 0;
}
