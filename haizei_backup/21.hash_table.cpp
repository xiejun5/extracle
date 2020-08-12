/*************************************************************************
	> File Name: 21.hash_table.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月02日 星期日 03时13分24秒
 ************************************************************************/

#include<iostream>
using namespace std;


class IHashFunc {
public :
    virtual int operator()(int) = 0;
};



class HashTable {
    typedef int (*HashFunc_T)(int);
    typedef pair<int, int> PII;
public :
    HashTable(HashFunc_T func);
    HashTable(IHashFunc &);
    int &operator[](int x) {
        int hash = 0;
        switch (hash_type) {
            case 1: hash = func1(x); break;
            case 2: hash = (*func2)(x); break;
        }
        if (hash < 0) ind = hash & oxffffff;
        int ind = hash % __size, t = 1;
        while (data[ind] && data[ind]->first != x) {
            ind += t * t;
            if (ind < 0) ind = ind & 0xfffffff;
            ind %= __size;
            t += 1;
        }
        if (data[ind] == nullptr) data[ind] = new PII(x, 0);
        return data[ind]->second;
    }
private :
    HashTable(HashFunc_T, IHashFunc, int);
    int hash_type;
    HashFunc_T func1;
    int __size;
    IHashFunc *func2;
    PII **arr;
};

HashTable::HashTable(HashFunct_T func1, IHashFunc &func2, int hash_type) 
: func1(func1), func2(&func2), hash_type(hash_type){
    this->__size = 1000;
    this->data = new PII *[this->size];
    for (int i = 0; i < this->__size; i++) this->data[i] = nullptr;
}

HashTable::HashTable(HashTable::HashFunc_T func)
: HashTable(func, nullptr, 1) {
}
HashTable::HashTable(IHashFunc &func)
: HashTable(nullptr, func, 2){
}

int hash1(int x) {
    return (x << 1) ^ (x << 3) ^ (x >> 5);
}

int main() {
    HashTable h1(hash1), h2();
    return 0;
}
