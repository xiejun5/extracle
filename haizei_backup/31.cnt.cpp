/*************************************************************************
	> File Name: 31.cnt.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月08日 星期六 16时37分35秒
 ************************************************************************/

#include<iostream>
#include <functional>
using namespace std;


class cnt {
public : 
    cnt() : n(0) {}
    void operaor()(function<int(int, int)> s) {
        cout << s(3, 5) << endl;
        n += 1;
    }
private :
    int n;
};

int add(int a, int b) {
    return a + b;
}
int main() {
    cnt c;
    c(2, 3);

    return 0;
}
