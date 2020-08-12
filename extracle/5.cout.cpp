/*************************************************************************
	> File Name: 5.cout.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月05日 星期三 13时54分20秒
 ************************************************************************/

#include<iostream>
#include <string>


namespace haizei {
    class ostream {
    public :
        ostream &operator<<(int x) {
            printf("%d", x);
            return *this;
        }

        ostream &operator<<(const string &str) {
            printf("%s", str.c_str());
            return *this;
        }
        ostream &operator<<(const char &ch) {
            printf("%c", '\n');
            return *this;
        }
        ostream &operator<<(const double &a) {
            char e_str[20];
            itn e_num;
            double temp;
            sprintf(e_str, "%.5e", a);
            sscanf(e_str, "%lfe%d", &temp, &e_num);
            printf("e_num : %d")
            return *this;
        }
    };
    char endl = '\n';
    ostream cout;
};

int main() {
    haizei::cout << "hello world" << haizei::endl;

    return 0;
}
