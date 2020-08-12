/*************************************************************************
	> File Name: 15.inherit_permission.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月28日 星期二 18时53分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public :
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << "my name is : " << __name << endl;
    }
protected :
    string __name;

private :
    int age;
};

class Cat : public Animal {
public :
    Cat() = delete;
    Cat(string name, int age) : Animal(name, age) {}
    
};

class Bat : protected Animal {
public :
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age) {}
    void say() {
        this->Animal::say();
        cout << "class Bat : " << __name << endl;
        //cout << Animal::age << endl;
    }
};

class dd : public Bat {};


int main() {
    string name = "miaomiao";
    Cat a(name, 20);
    Bat b("linux", 16384);
    b.say();
    return 0;
}
