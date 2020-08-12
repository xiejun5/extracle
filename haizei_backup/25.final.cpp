/*************************************************************************
	> File Name: 25.final.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月03日 星期一 03时48分57秒
 ************************************************************************/

#include<iostream>
#include <map>
using namespace std;

class A : public map<int, int>{
public :
    virtual void say(){
        cout << "Class A : hello world" << endl;
    }
};

class B final : public A{
public :
    void say () final override {
        cout << "Class B : hello world" << endl;
    }
};

/*class C : public B {
public :
    void say() override {
        cout << "Class C : hello world" << endl;
    }
};*/

int main() {

    return 0;
}
