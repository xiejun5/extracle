/*************************************************************************
	> File Name: 7.dep_copy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月30日 星期四 23时13分45秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;

class A {
public :
    A() {
        this->arr = new int[100];
    }
    A(const A &obj) : x(obj.x), y(obj.y){
        this->arr = new int[100];
        memcpy(this->arr, obj.arr, sizeof(int) * 100);
    }
    int *arr;
    int x, y;
};


int main() {
    A a;
    a.x = 3, a.y = 6;
    A b = a;
    cout << b.x << " " << b.y << endl;
    b.x = 6;
    cout << a.x << " " << b.y << endl;
    cout << b.x << " " << b.y << endl;

    a.arr[0] = 123;
    b.arr[0] = 456;
    cout << a.arr[0] << " " << b.arr[0] << endl;
    return 0;
}
