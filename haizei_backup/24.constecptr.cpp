/*************************************************************************
	> File Name: 24.constecptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月03日 星期一 02时56分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

constexpr int f(int x) {
    return x;
}

class A {
public :
    constexpr A(int x, int y) : x(x), y(y) {}
    int x, y;
};

int main() {
    const int n = 123;
    cout << 123 << endl;
    constexpr int m = f(23);
    cout << m << endl;

    constexpr A a(2, 3);
    return 0;
}
