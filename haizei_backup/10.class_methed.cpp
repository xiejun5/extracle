/*************************************************************************
	> File Name: 10.class_methed.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月26日 星期日 19时44分24秒
 ************************************************************************/

#include<iostream>
using namespace std;


class Point {
public:
    Point() {
        Point::total_cnt += 1;
    };
    Point(int x, int y) : Point() {
        this->x = x;
        this->y = y;
    }
    static int T() {
        return Point::total_cnt;
    }

    ~Point() {
        Point::total_cnt -= 1;
    }
    
private:
    int x, y;
    static int total_cnt;
};

int Point::total_cnt = 0;

void test() {
    Point a;
    cout << Point::T() << endl;
    return ;
}


int main() {
    Point a;
    cout << a.T() << endl;
    test();
    Point b;
    cout << b.T() << endl;
    return 0;
}
