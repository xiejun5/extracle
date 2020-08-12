/*************************************************************************
	> File Name: vir.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月11日 星期二 10时15分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

class B {
public :
    void say() {
        cout << this << endl;
    }
};



int main() {
   cout << sizeof(B) << endl; 
    B b, c;
    cout << sizeof(b) << sizeof(c) << endl;
    b.say();
    c.say();
    return 0;
}
