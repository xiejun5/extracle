/*************************************************************************
	> File Name: 4.set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月24日 星期五 02时16分18秒
 ************************************************************************/

#include<iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(345);
    s.insert(65);
    s.insert(9973);
    s.insert(9000);
    cout << s.size() << endl;
    s.insert(65);
    cout << s.size() << endl;
    cout << *(s.begin()) << endl;

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }

    s.erase(s.begin());
    cout << *(s.begin()) << endl;
    return 0;
}
