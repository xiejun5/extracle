/*************************************************************************
	> File Name: 9.hashtable.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月12日 星期三 09时26分10秒
 ************************************************************************/

#include<iostream>
#include 
using namespace std;

class Node {
public :
    Node() : flag(false), str(nullptr) {}
    void clear() {
        this->flag = false;
        if (this->str) free(this->str);
        this->str = nullptr;
        return ;
    }
    void insert(const char *str) {
        this->clear();
        this->flag = true;
        this->str = strdup(str);
        return ;
    }
    bool empty() { return this->flag == false; }
    bool operator!=(const char *str) {
        if (this->str == nullptr) return true;
        return strcmp(this->str, str) != 0;
    }
    bool operator==() {
        return !((*this) != str);
    }
private :
    bool flag;
    char *str;
};

class HashFunc {
public :
    virtual int operator()(const char *str) const = 0;
};



class HashTable {
public :
    HashTable(const HashFunc &func);
    bool insert(const char *str);
    bool find(const char *str);
private :
    int _size;
    Node *data;
    const HashFunc *p_func;
};

HashTable::HashTable(const HashFunc &func) : p_func(&func) {
    this->_size = 100;
    this->data = new Node[this->_size];
}

bool HashTable::insert(const char *str) {
    int ind = (*p_func)(str) % this->_size;
    int times = 1;
    while (!data[ind].empty() && data[ind] != str) {
        ind += times * times;
        ind %= this->_size;
    }
    if (data[ind] == str) return false;
    data[ind].insert(str);
    return true;
}

Node &HashTable::find_position(const char *str) {
    
}
int main() {

    return 0;
}
