/*************************************************************************
	> File Name: 18.String.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月01日 星期六 22时32分23秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;



namespace haizei {
class string {
public :
    string() {
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }

    string(const char *str) {
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;

    }
    char &at(int ind) {
        if (ind < 0 || ind >= __length) {
            cout << "String Error : out of range" << endl;
            return __end;
        }
        return this->operator[](ind);
    }
    

    char &operator[](int ind) {
        return buff[ind];
    }

    const char *c_str() const {
        return buff;    
    }

    string operator+(const string &s) {
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }


private :
    int __length, __buff_size;
    char *buff;
    char __end;
};
};



ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str() << endl;
    return out;
}
int main() {
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = "haerbin";
    haizei::string sd;
    cout << s1 << endl;
    s1[3] = '6';
    cout << s1 + s2 + s3 << endl;

    return 0;
}
