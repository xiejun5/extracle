/*************************************************************************
	> File Name: 2.map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月21日 星期二 20时09分43秒
 ************************************************************************/

#include<iostream>
#include<map>
#include <unordered_map>
using namespace std;


int main() {
    map<double, string> arr;
    arr[1.2] = "hello";
    arr[4.3] = "world";
    arr[-4.5] = "haizei";
    arr[89.7] = "world";
    cout << arr[1.2] << endl;
    cout << arr[4.3] << endl;

    double n;
    while (cin >> n) {
        if (arr.find(n) != arr.end()) {
            cout << "find : " << arr[n] << endl;
        } else {
            cout << "not found : " << n << endl;
        }
    }

    for (map<double, string>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}
