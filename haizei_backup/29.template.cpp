/*************************************************************************
	> File Name: 29.template.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月06日 星期四 11时46分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A(int x) : x(x) {}
    int x;
};


class B {
public :
    B(int y) : y(y) {}
    int y;
};

template<class T, typename U>
class PrintAny {

}

int operator+(const A &a, B &b) {
    return a.x + b.y;
}


/*template<typename T, typename U> 
decltype(T() + U()) add(T a, U b) {
    return a + b;
}*/


auto add(T a, U b) ->decltype(a + b) {
    return a + b;
}
namespace haizei{
template<class T, class U>
    auto max(T a, U b) -> decltype(a + b){
        return a > b ? a : b;
}
template<class T>
decltype(T()) max(T a, T b) {
        return a > b ? a : b;
}
template<> 
    int add(int a, int b) {
        return a + b;
    }
template<typename T>
    class FoolPrintAny {
        public :
        void operator()(const T &a) {
            cout << a << endl;
        }
    };
template<>
    class FoolPrintAny {
        public :
        void operator()(const T &a) {
            cout << "naughty : " << 2 * a << endl;
        }
    };
template<typename T, typename U>
    auto add(T *, U * b) -> decltype(*a + *b) {
        return add(*a, *b);
    }

template<typename T>
    void printAny(const T &a) {
        cout << a;
        return ;
    }
};
template<typename T, typename ...ARGS>
    void printAny(T &a, ARGS...args) {
        cout << a << " ";
        printfAny(args...);
        return ;
    }

//解析模板的变参函数
template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS> 
class Test<T(ARGS...)> {
public :
    T operator()(
            typename ARG<ARGS...>::__type a, 
            typename ARG<ARGS...>::__rest::__type b) {
        return a * b;
    }
}





int main() {
    double  a = 2;
    double  b = 3;
    cout << add(a, b) << endl;
    cout << add('A', 'B') << endl;

    A c(243);
    B d(23);

    cout << add(c, d) << endl;
    cout << haizei::max(a, b) << endl;
    int p = 20;
    double s = 0.03;
    cout << haizei::max(p, s) << endl;

    return 0;
}
