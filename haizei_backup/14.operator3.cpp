/*************************************************************************
	> File Name: 14.operator3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月28日 星期二 04时04分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() {
        arr = new int[10];
    }

    A(const A &a) : A() {
        for (int i = 0; i  < 10; i++) {
            this->arr[i] = a.arr[i];
        }
        this->x = a.x;
        this->y = a.y;
    }
    int x, y;
    int *arr;


};


class B {
public :
    B() : obj(nullptr) {
        arr = new int[10];
        arr[3] = 9999;
    }
    B(A *obj) : B() {
        this->obj = obj;
    }
    int operator()(int a, int b) {
        return a + b;
    }

    int &operator[](int ind) {
        return arr[ind];
    }

    void operator[](const char *msg) {
        cout << msg << endl;
        return ;
    }

    A *operator->() {
        return obj;
    }

    A &operator*() {
        return *obj;
    }
    ~B() {
        delete arr;
    }
private :
    int *arr;
    A *obj;

};

ostream &operator<<(ostream &out, const A &a) {
    out << "A(" << a.x << ", " << a.y << ")";
    return out;
}


int main() {
    B add;
    cout << add(3, 4) << endl;
    add[3];
    cout << add[3] << endl;
    add[3] = 8888;
    cout << add[3] << endl;
    add["hello world"];


    A a;
    a.x = 67, a.y = 99;
    B p = &a;
    cout << *p << endl;
    cout << p->x << " " << p->y << endl;
    return 0;

    A b, c(b);
    b.arr[3] = 9978;
    c.arr[3] = 6687;
    std::cout << b.arr[3] << endl;
    std::cout << c.arr[3] << endl;
    cout << sizeof(A) << endl;
}
