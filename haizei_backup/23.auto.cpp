/*************************************************************************
	> File Name: 23.auto.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月03日 星期一 02时40分02秒
 ************************************************************************/

#include<iostream>
#include <map>
using namespace std;


class {
public :
    static const auto x = 123;
};

int main() {
    auto a = 123;
    cout << sizeof(a) << endl;
    map<int, int> arr;
    arr[23442434] = 3234234;
    arr[23424] = 2342;
    arr[234] = 1000;
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }

    for (auto  x  :  arr) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
