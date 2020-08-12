/*************************************************************************
	> File Name: intArray.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月07日 星期五 23时34分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

class IntArray {
public :
    IntArray(int n) : n(n){
        this->arr = new int[n];
    }
    int &operator[](int ind) {
        if (ind < 0) return this->arr[n + ind];
        return this->arr[ind];
    }
    void operator+=(int x) {
        for (int i = 0; i < n; i++) {
            arr[i] += 5;
        }
        return ;
    }

    friend ostream &operator<<(ostream &out, const IntArray &a);
    ~IntArray() {
        delete[] this->arr;
    }
private :
    int *arr, n;
};

ostream &operator<<(ostream &out, const IntArray &a) {
    out << "<Class IntArray> :";
    for (int i = 0; i < a.n; i++) {
        out << a.arr[i] << " " ;
    }
    out << endl;
    return out;
}

int main() {
    srand(time(0));
    IntArray a(10);
    return 0;
}
