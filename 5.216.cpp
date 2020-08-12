/*************************************************************************
	> File Name: 5.216.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月24日 星期五 02时27分07秒
 ************************************************************************/

#include<iostream>
#include <set>
using namespace std;

typedef pair<string, int> PSI;

int main() {
    set<PSI> s;
    string name;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        name = name.substr(name.find(".") + 1, name.length() - name.find(".") - 1);
        s.insert(PSI(name, i));
    }

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << iter->first << endl;
    }
    


    return 0;
}
