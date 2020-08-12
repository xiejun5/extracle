/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月08日 星期六 00时18分24秒
 ************************************************************************/

#include<iostream>
using namespace std;


class A {
public : 
    int arr;
static int b;
};

class B : public A {
public : 
    B() {
        cout << this << endl;
    }
};

int main() {
    B b;
    cout << &b << endl;
    A *a = &b;
    cout << a << endl;

    return 0;
}
