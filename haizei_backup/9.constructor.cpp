/*************************************************************************
	> File Name: 9.constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月26日 星期日 18时14分43秒
 ************************************************************************/

#include<iostream>
using namespace std;


class People {
public:
    People(string name) {
        cout << "param construct" << endl;
        this->name = name;
    }
    People(int x) {
        cout << "int param constructor" << endl;
        this->x = x;
    }

    People(const People &a) {
        this->name = a.name;
        this->x = a.x;
    }

    void operator=(const People &a) {
        cout << "operator=" << endl;
        this->name = a.name;
        this->x = a.x;
    }
    ~People() {
        cout << "destructor" << endl;
    }

    string name;
    int x;
};

int add(People a, People b) {
    return a.x + b.x;
}

void incr(int &s) {
    s += 1;
    return ;
}

int main() {
    People a = string("hello");
    cout << a.name << endl;
    cout << add(4, 6) << endl;
    People c(22);
    c = 34;
    cout << c.x << endl;
    int s = 7;
    incr(s);
    cout << s << endl;
    People b = a;
    c = a;
    return 0;
}
