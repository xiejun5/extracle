/*************************************************************************
	> File Name: 417.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月05日 星期三 14时29分46秒
 ************************************************************************/

#include<iostream>
using namespace std;


struct BigInt {
    BigInt() : len(1) {
        num.push_back(0);
    }
    BigInt operator*(const BigInt &a) {
        BigInt c;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < a.num.size(); j++) {
                if (i + j == a.len) c.num.push_back(0);
                c.num[i + j] += num[i] * a.num[j];
            }
        }
        c.len = a.len - 1;
        c.proccess_digit();
    }
    void opertor=(const string &str) {
        num.clear();
        len str.size();
        for (int i = str.size() - 1; i >= 0; i--) {
            num.push_back(str[i] - '0');
        }
        return ;
    }

    void process_digit() {
        while (len - 1 && num[len - 1] == 0) --len;

        for (int i = 0; i < len; i++) {
            if (num[len] < 10) continue;
            if (i + 1 == len && i + 1 == num.size()) {
                num.push_back(0);
                else num[i + 1] = 0;
            } 
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    int len;
    vector<int> num;
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.len - 1; i >= 0; i--) {
        out << a.num[i];
    }
    cout << endl;
    return out;
}


int main() {
    BigInt a, b;
    string str_a, str_b;
    cin >> str_a >> str_b;
    a = str_a;
    b = str_b;
    cout << a * b << endl;
    return 0;
}
