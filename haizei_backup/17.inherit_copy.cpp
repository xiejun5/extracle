/*************************************************************************
	> File Name: 17.inherit_copy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月28日 星期二 20时44分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() {
        cout << "class A copy constructor" << endl;
        this->x = 0x01020304;
    }
    A(const A &a) {
        cout << "class A copy constructor" << this << endl;
    }    
    int x, y;
};

class B : public A {
public :
    B() {
        this->y = 0x05060708;
        cout << "class B constructor" << endl;
    }
    B(const B &b) : A(b) {
        cout << "class B copy constructor" << this << endl;
    }

};

int main() {
    B b1;
    B b2(b1);

    const char *msg = (const char *)(&b1);
    for (int i = 0; i < sizeof(B); i++) {
        printf("%X", msg[i]);
    }
    cout << endl;
    return 0;
}
