/*************************************************************************
	> File Name: 33.test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月06日 星期四 15时04分12秒
 ************************************************************************/

#include "33.test.h"

int add(int a, int b) {
    return a + b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int a = 2, b = 5;
    cout << add(a, b) << endl;
    cout << max(a, b) << endl;
    
    return 0;
}
