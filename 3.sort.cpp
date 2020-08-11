/*************************************************************************
	> File Name: 3.sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月21日 星期二 20时53分24秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b) {
    return a > b;
}

struct CMP_FUNC {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int arr[1000], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, CMP_FUNC);
    sort(arr, arr + n, [](int a, int b)->bool {return a > b;});
    for (int i = 0; i < n; i++) cout << arr[i] << endl;

    nth_element(arr,  arr + 2, arr + n);


    return 0;
}
