/*************************************************************************
	> File Name: 29.template.cpp
	> Author:
	> Mail: 
	> Created Time: 四  8/ 6 11:45:58 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class A {
public :
    A(int x) : x(x) {}
    int x;
};

class B {
public: 
    B(int y) : y(y) {}
    int y;
};

int operator+(const A &a, const B &b) {
    return a.x + b.y;
}

namespace haizei {

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

template<>
int add(int a, int b) {
    cout << "add int : "<< a << " " << b << endl;
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b);
}

template<typename T, typename U>
auto max(T a, U b) -> decltype(a + b) {
    return a < b ? b : a;
}

template<typename T, typename U>
auto min(T a, U b) -> decltype(a + b) {
    return a < b ? a : b;
}

class PrintAny {
public :
    template<typename T>
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<typename T>
class FoolPrintAny {
public:
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<>
class FoolPrintAny<int> {
public:
    void operator()(const int &a) {
        cout << "naughty : " << 2 * a << endl;
    }
};

template<typename T>
void printAny(const T &a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void printAny(const T &a, ARGS...args) {
    cout << a << " ";
    printAny(args...);
    return ;
}

template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::__type __type;
};


template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...> {
    typedef T __type;
};

template<typename T>
struct ARG<0,  T> {
	typedef T __type;
};


template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(
        typename ARG<0, ARGS...>::__type a, 
        typename ARG<1, ARGS...>::__type b) {
        return a + b;
    }
};

template<typename T, typename ...ARGS> class Test2;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {    
public :
    T operator()(ARGS... args) {
        return add<T>(args...);
    }
private :
    template<typename T1, typename U, typename ...US>
    T1 add(U a, US ...args) {
        return a + add<T1>(args...);
    }

    template<typename T1, typename U>
    T1 add(U a) {
        return a;
    }
    
};

template<typename T, typename U>
T test_param_func(U a) {
    return T(a * 2);
}

void func2(double (*func)(double)) {
    cout << func(2.3) << endl;
}

template<typename T>
struct add_const {
    typedef const T type;
};

template<typename T>
struct add_const<const T> {
    typedef const T type;
};

template<typename T>
struct add_const<T *> {
    typedef const T type;
};




template<typename T>
struct add_lvalue_reference {
    typedef T &type;
};

template<typename T>
struct add_lvalue_reference<T &> {
    typedef T &type;
};

template<typename T>
struct add_lvalue_reference<T &&> {
    typedef T &&type;
};

template<typename T>
struct add_rvalue_references {
    typedef T &&type;
};

template<typename T> struct add_rvalue_references<T &&>{ typedef T type; };

template<typename T> struct add_rvalue_references<T &> { typedef T type; };

template<typename T> struct remove_pointer { typedef T type; };

template<typename T> struct remove_pointer<T *> { typedef T type; };

template<typename T> struct remove_pointer<T* const> { typedef T type;};
template<typename T> struct remove_reference { typedef T type; };

template<typename T> struct remove_reference<T &> { typedef T type; };
template<typename T> struct remove_reference<T &&> { typedef T type; };

template<typename T> 
typename add_rvalue_references<T>::type move(T &&a) { 
    return typename add_rvalue_references<T>::type(a); 
};

void f(int &x) {
    cout << "f cuntion : left value" << endl;
    return ;
}

void f(int &&x) {
    cout << " f cution : right value" << endl;
    return ;
}

template<typename T>
typename remove_reference<T>::type  add2(T &&a, T &&b) {
    typename remove_reference<T>::type c = a + b;
    return  c;
}


}

int main() {
    typedef haizei::add_const<int>::type N; 
    typedef haizei::add_const<int *>::type s;

    int inta = 123, intb = 456;
    cout << haizei::add2(inta, intb) << endl;
    cout << haizei::add2(123, 456) << endl;
    haizei::func2(haizei::test_param_func);
    A a(1000);
    B b(645);
	
    cout << a + b << endl;
    cout << haizei::add(2, 3) << endl;
    cout << haizei::add(2.3, 4.3) << endl;
    cout << haizei::add(2.3, 5) << endl;
    cout << haizei::add(5, 2.3) << endl;
    cout << haizei::add(string("hello"), "hello world") << endl;
    cout << haizei::add(a, b) << endl;
    cout << haizei::max(4, 3) << endl;
    cout << haizei::max(4.3, 3) << endl;
    cout << haizei::min(4, 3) << endl;
    cout << haizei::min(4.3, 3) << endl;
    haizei::PrintAny print;
    print(123);
    print(45678);
    print(3.4);
    print("hello world");
    print("hello haizei");
    print(&a);
    haizei::FoolPrintAny<string> f;
    f("hello world");
    haizei::FoolPrintAny<int> f2;
    f2(123);
    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl;
    cout << haizei::add(p, q) << endl;
    haizei::printAny(123, 34.5, "hello world", &a);
    haizei::Test<int(int, int)> f3;
    cout << f3(3, 4) << endl;
    
    haizei::Test2<int(int, int, int, int)> f4;
    cout << f4(1, 2, 3, 4 ) << endl;

    haizei::f(n);
    haizei::f(haizei::move(n));
    cout << n << endl;
    return 0;
}

