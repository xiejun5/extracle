/*************************************************************************
	> File Name: 30.template.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月08日 星期六 14时16分25秒
 ************************************************************************/

#include<iostream>

namespace haizei {
template<typename T>
struct add_const {
    typedef const T type;
};

template<typename T>
    struct add_lvalue_reference {
        typedef T type;
    };

template<typename T>
struct add_lvalue_reference<T &> {
    typedef T type;
};

template<typename T>
struct add_lvalue_reference<T &&> {
    typedef T type;
};

template<typename T>
struct add_rvalue_reference {
        typedef T type;
};
template<typename T>
class add_rvalue_reference<T &&> {
    typedef T type;
};

template<typename T>
class add_rvalue_reference<T &> {
    typedef T type;
};

template<typename T>
struct remove_pointer {
    typedef T type;
};

template<typename T>
struct remove_pointer<T *> {
    typedef T type;
};

template<typename T>
struct remove_pointer<T* const> {
    typedef T type;
};
}

int main() {
	return 0;
}
