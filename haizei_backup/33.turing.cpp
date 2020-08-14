/*************************************************************************
	> File Name: 33.turing.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月13日 星期四 22时26分10秒
 ************************************************************************/

#include<iostream>

#include <cmath>
using namespace std;

template<int n>
struct IsEvent {
    static constexpr int r = !(n % 2);
};


template<int n, int s>
struct add {
    static constexpr int sum = n + s;
};

template<int n>
struct Sum {
    static constexpr int r = n + Sum<n - 1>::r;
};

template<>
struct Sum<0> {
    static constexpr int r = 1;
};

template<int n> 
struct Factorial {
    static constexpr int r = n * Factorial<n - 1>::r; 
};

template<>
struct Factorial<0> {
    static constexpr int r = 1;
};


//实现模板素数

template<int n, int i>
struct getNextN {
    static constexpr int r = (i * i > n ? 0 : n);
};

template<int n, int i>
struct getNextI {
    static constexpr int r = (n % i == 0 ? 0 : i + 1);
};

template<int n, int i>
struct IsTest {
    static constexpr int r = IsTest<getNextN<n, i>::r, getNextI<n, i>::r>::r;
};

template<int i>
struct IsTest<0, i> {
    static constexpr int r = 1;
};

template<int n>

struct IsTest<n, 0> {
        static constexpr int r = 0;
};

template<int i >
struct IsTest<2, i> {
    static constexpr int r = 1;
};
template<int n> 
struct IsPrime {
    static constexpr int r = IsTest<n, 2>::r;
};
template<int n>
struct SumPrime {
    static constexpr int r = (n * IsPrime<n>::r) + SumPrime<n - 1>::r;  
};


template<>
struct SumPrime<1> {
    static constexpr int r = 0;
};

template<int n>
struct CntPrime {
    CntPrime() {
        cout << n << endl;
    }
    static constexpr int r = CntPrime<n - 1>::r;
};

template<>
struct CntPrime<1> {
    static constexpr int r = 0;
};

template<int n, int m>
struct Check{
    static constexpr bool r = (n % m != 0) && Check<n, m-1>::r;
};

template<int n>
struct Check<n, 2>{
    static constexpr bool r = (n % 2 != 0);
};


template<int n>
struct IsPPrime{
    static constexpr int r = Check<n, (int)sqrt(n)>::r;
};


template<>
struct IsPrime<0> {
    static constexpr int r = 2;
};



int main() {
    cout <<  IsEvent<123>::r << endl;
    cout <<  IsEvent<124>::r << endl;
    
    cout << add<345, 233>::sum << endl;
    cout << Sum<10>::r << endl;

    cout << Factorial<5>::r << endl;
    cout << Factorial<10>::r << endl;

    cout << IsPrime<10>::r << endl;
    cout << IsPrime<5>::r << endl;
    cout << IsPrime<11>::r << endl;
    cout << SumPrime<15>::r << endl;
    cout << SumPrime<13>::r << endl;
    cout << CntPrime<10>::r << endl;
    return 0;
}
