/*************************************************************************
	> File Name: 30.function.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月08日 星期六 15时25分36秒
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;


namespace haizei {

template<typename RT, typename ...PARAMS> class base {
public :
    virtual RT operator()(PARAMS...) = 0;
    virtual ~base() {}
};

template<typename RT, typename ...PARAMS> 
class normal_func : public base<RT, PARAMS...> {
public :
    typedef RT(*func_type)(PARAMS...);
    normal_func(func_type func) : ptr(func){
    }
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }
private :
    func_type ptr;
};

template<typename C, typename RT, typename ...PARAMS> 
class functor : public base<RT, PARAMS...> {
public :
    typedef RT(*func_type)(PARAMS...);
    functor(C &func) : ptr(func){}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }
    virtual ~functor() {}
private :
    C &ptr;
};
template<typename RT, typename ...PARMS> class function;
template<typename RT, typename ...PARMS> 
class function<RT(PARMS...)> {
public :
    function(RT (*func)(PARMS...args)) : ptr(new normal_func<RT, PARMS...>(func)){
    }
    template<typename T>
    function(T &&a) 
    : ptr(new functor<typename remove_reference<T>::type, RT, PARMS...>(a)){
    }

    RT operator()(PARMS... args) {
        this->ptr->operator()(args...);
    }

    ~function() {
        delete ptr;
    }
private :
    base<RT, PARMS...> *ptr;

};
}
void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
}

int add(int a, int b) {
    return a + b;
}

struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b;
    }
};


template<typename T, ARGS...> class Cnt;
template<typename T, ARGS...>
class Cnt<T(ARGS...)> {
public :
    Cnt(function<T(ARGS...)> g) : g(g), __n(0){}
    int operator()(ARGS...args) {
        __n += 1;
        return g(args);
    }
    int getCnt() {
        return this->__n;
    }
private :
    function<int(int, int)> g;
    int __n;
};


int main() {
    MaxClass max;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    
    Cnt add_cnt(add);
    add_cnt(3, 5);
    add_cnt(3, 5);
    add_cnt(4, 5);
    cout << add_cnt.getCnt() << endl;
    return 0;
}
