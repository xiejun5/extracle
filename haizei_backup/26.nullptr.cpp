/*************************************************************************
	> File Name: 26.nullptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月03日 星期一 04时06分20秒
 ************************************************************************/

#include<iostream>
using namespace std;


int f(int x) {
    cout << "output int value : ";
    cout << x << endl;
    return 0;
}

int f(int *x) {
    cout << "output address : ";
    cout << x << endl;
    return 0;
}

int main() {
    printf("%lld", (long long)nullptr);
    cout << NULL << endl;

    int n = 123, *p = &n;
    f(n);
    f(p);

    f(nullptr);

    return 0;
}
