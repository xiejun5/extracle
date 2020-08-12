/*************************************************************************
	> File Name: 8.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月25日 星期六 16时19分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

class People {
    friend int main();
    int x, y;
public : 
    void set(int x, int y); 
    void say(); 
};


void People::set(int x, int y) {
    cout << "set function : " << this << endl;
    this->x = x;
    this->y = y;
    return ;
}

void People::say() {
    cout << x << " " << y << endl;
    return ;
}


int main() {
    People a;
    cout << "a object : " << &a << endl;
    a.set(2, 3); 

    a.say();
    return 0;
}
