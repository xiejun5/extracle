/*************************************************************************
	> File Name: 31.cnt.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月08日 星期六 16时37分35秒
 ************************************************************************/

#include<iostream>
#include <functional>
using namespace std;


template<typename RT, typename ...ARGS> class FunctionCnt;
template<typename RT, typename ...ARGS> 
class FunctionCnt<RT(ARGS...)> {
public :
    FunctionCnt(function<RT(ARGS...)> g) : g(g), cnt(0) {}
    RT operator()(ARGS... args) {
        cnt += 1;
        return g(args...);
    }
    int get_cnt() {
        return cnt;
    }
private :
    int cnt;
    function<RT(ARGS...)> g;
};

int add(int a, int b) {
    return a + b;
}


class A {
public :
    int  operator()(int a, int b) {
        return a + b;
    }
};
int main() {
    FunctionCnt <int(int, int)>c(add);
    c(2, 4);
    c(4, 5);
    cout << c.get_cnt() << endl;
    FunctionCnt <double(double, double)> s(add);
    s(3.4, 2.5);
    cout << s.get_cnt() << endl; 
    A k;
    FunctionCnt <int(int, int)>b(k); 
    b(4, 5);
    b(2, 6);
    cout << b.get_cnt() << endl;
    


    return 0;
}
