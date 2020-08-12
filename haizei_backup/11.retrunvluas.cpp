/*************************************************************************
	> File Name: 11.retrunvluas.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月26日 星期日 21时10分55秒
 ************************************************************************/

#include<iostream>
using namespace std;



class People {
public:
    People(string name) {
        cout << "test" << endl;
        this->name = name;
    }

    People(const People &a) {
        cout << "copy" << endl;
        this->name = a.name;
    }
private:
    string name;
};

People funcc() {
    People temp_a("wu");
    return temp_a;
}

int main() {
    People a("hh");

    
    return 0;
}
