/*************************************************************************
	> File Name: 10.virtual.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月09日 星期日 05时41分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public :
    virtual void say() {
        cout << "I don't know how to say" << endl;
    }

private :
    int x, y;
};

class Cat : public Animal {
    virtual void say() override {
        cout << "miao~ miao~ miao~" << endl;
    }
};

int main() {
    cout << sizeof(Animal) << endl;
    cout << sizeof(Cat) << endl;
    return 0;
}
