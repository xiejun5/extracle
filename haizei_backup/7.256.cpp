/*************************************************************************
	> File Name: 7.256.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月24日 星期五 03时51分05秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1000
int a[MAX_N  + 5], b[MAX_N + 5], ind[MAX_N + 5];

bool cmp(int i, int j) {
    return a[i] * b[i] < a[j] * b[j];
}


struct BigInt : vector<int> {
    BigInt() {}
    BigInt(int x) {
        push_back(x);
        proccess_digit();
    }

    BigInt(vector<int> &v) : vector<int>(v) {}
    BigInt operator/(int x) {
        int y = 0;
        vector<int> ret(size());
        for (int i = size() - 1; i >= 0; i--) {
            y = y * 10 + at(i);
            ret[i] = y / x;
            y %= x;
        }
        return ret;
    }

    void operator*=(int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        proccess_digit();
        return ;
    }


    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while (size() > 1 && at(size() - 1]) == 0) ret.pop_back();
        return ;
    }


};

ostream &operator<<(ostream &out, const BigInt &v) {
    for (int i = v.size() - 1; i >= 0; i--) {
        out << v[i];
    }
    return out;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }
    sort(ind + 1, ind + n + 1, cmp);
    BitInt p = a[ind[0]], ans = 0;
    for (int i = 1; i <= n; i++) {
        BitInt temp = p / b[ind[i]];
        if (temp > ans) ans = temp;
        p *= a[ind[i]];
    }

    cout << endl;
    return 0;
}
