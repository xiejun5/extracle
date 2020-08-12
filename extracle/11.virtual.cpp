/*************************************************************************
	> File Name: 11.virtual.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月11日 星期二 14时20分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public :
    virtual void say(int x) {
        cout << "I don't know how to say" << endl;
    }
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }

private :
    int x, y;
};


class Cat : public Animal {
    void say(int x) override {
        cout << "miao~ miao~ miao~" << endl;
    }
    void run() override {
        cout << "I want run" << endl;
    }
};


typedef void (* func)(void *, int x);

void output_raw_data(void *q, int n) {
    unsigned char *p = (unsigned char *)q;
    for (int i = 0; i < 16; i++) {
        printf("%02X ", p[i]);
    }
    printf("\n");
    return ;
}

int main() {
    Cat a, b;
    output_raw_data(&a, sizeof(a));
    output_raw_data(&b, sizeof(b));
    ((func **)(&a))[0][0](&a, 23);
    return 0;
}
