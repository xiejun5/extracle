/*************************************************************************
	> File Name: 34.thread_pool.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月14日 星期五 00时07分53秒
 ************************************************************************/

#include<iostream>
#include <functional>
#include <thread>
#include <vector>
using namespace std;

class Task {
public :
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
    } 

    void operator()() {
        this->func();
        return ;
    }
private :
    function<void()> func;
};

void thread_func1(int a, int b) {
    cout << a << " + " << " = " << a + b << endl;
}

void thread_func2(int &n) {
    n += 1;
    return ;
}


class ThreadPool {
public :
    ThreadPool(int n = 5)
    : is_running(false), max_threads_num(n) {}

    void start() {
        is_running = true;
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
    }
    void worker() {
        cout << "worker : hello, I'm worker" << endl;
    }

    void stop() {
        if (is_running == false) return ;
        is_running = false;
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads;
        }
    }
    ~ThreadPool() {
        
    }

private :
    bool is_running;
    int max_threads_num;
    vector<thread *> threads;
};

int main() {
    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 4, 5);
    Task t3(thread_func1, 7, 5);
    t1(), t2(), t3();
    int n = 0;
    Task t4(thread_func2, ref(n));
    t4(), t4(), t4();
    cout << n << endl;

    ThreadPool tp(6);
    tp.start();
    tp.stop();
    return 0;
}
