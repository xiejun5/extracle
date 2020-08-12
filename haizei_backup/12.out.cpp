/*************************************************************************
	> File Name: 12.out.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月28日 星期二 02时29分08秒
 ************************************************************************/

#include<iostream>
using namespace std;

namespace haizei {
    
class istream {
public:
    istream &operator>>(int &n) {
        std::cin >> n;
        return *this;
    } 
private:

};

class ostream {
public:
    ostream &operator<<(int &n) {
        std::cout << n;
        return *this;
    }
    ostream &operator<<(const char *msg) {
        std::cout << msg;
        return *this;
    }

private:
};

istream cin;
ostream cout;
};

haizei::ostream &operator<<(haizei::ostream &out, double &z) {
    std::cout << z;
    return out;
}

ostream &operator+(ostream &out, const int &z) {
    std::cout << z;
    return out;
}

int main() {
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n << " "<< m;
    double k = 5.6;
    haizei::cout << k << "\n";
    (((((cout + 8 )<< " " )+ 9) << " ") + 10) << endl;
    return 0;
}
