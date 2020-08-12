/*************************************************************************
	> File Name: 10.operatot.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月07日 星期五 22时41分24秒
 ************************************************************************/

#include<iostream>
using namespace std;


class Point {
public :
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point &obj) : x(obj.x), y(obj.y) {
        cout << "copy constructor" << endl;
    }
    Point operator-(const Point &a) {
        Point ret;
        ret.x = this->x - a.x;
        ret.y = this->y - a.y;
        return ret;
    }
    friend ostream &operator<<(ostream &out, const Point &a);
    friend Point operator+(const Point &a, const Point &b);
private :
    int x, y;
};

Point operator+(const Point &a, const Point &b) {
    Point ret;
    ret.x = a.x + b.y;
    ret.y = a.y + b.y;
    return ret;
}

ostream &operator<<(ostream &out, const Point &a) {
    out << "<class Point>" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    int t(5);
    Point a(2, 4), b(5, 3);
    Point c = a + b;
    Point d = a + b + c;
    Point e = d - b;
    cout << a << b << c << endl;
    return 0;
}
