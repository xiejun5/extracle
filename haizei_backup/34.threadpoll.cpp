/*************************************************************************
	> File Name: 34.thread_pool.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 四  8/13 16:07:49 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <unistd.h>

using namespace std;

class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
    }
    void operator()() {
        this->func();
        return ;
    }

private:
    function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int n = 5) 
    : is_running(false), max_threads_num(n) {}
    void start() {
        if (is_running) return ;
        is_running = true;
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
        return ;
    }
    void worker() {
        while (is_running) {
            //取任务
            Task *t = this->getOneTask();
            if (t == nullptr) break;
            //执行任务
            (*t)();
            //释放任务
            delete t;

        }
    }
    void stop() {
        if (is_running == false) return ;
        do {
            unique_lock<mutex> lock(m_mutex);
            is_running = false;
            m_cond.notify_all();
        } while (0);
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        do {
            unique_lock<mutex> lock(m_mutex);
            while (!task_queue.empty()) {
                task_queue.pop();
            }
        } while (0);
        return ;
    }
    
    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS... args) {
        unique_lock<mutex> lock(m_mutex);
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }

private:
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);
        while (is_running && task_queue.empty()) m_cond.wait(lock);//等待，直到队列中存在任务
        //在等待添加任务时，临时释放胡互斥锁。
        if (is_running == false) return nullptr;
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    bool is_running;
    int max_threads_num;
    vector<thread *> threads;
    queue<Task *> task_queue;
    mutex m_mutex;
    condition_variable m_cond;
};

void thread_func1(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
    return ;
}

void thread_func2(int &n) {
    n += 1;
    return ;
}

void task_func(int x) {
    cout << "task func : " << x << endl;
}

int main() {
    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 5, 6);
    Task t3(thread_func1, 7, 8);
    t1(), t2(), t3();
    int n = 0;
    
    Task t4(thread_func2, ref(n));
    t4(), t4(), t4();
    cout << n << endl;

    ThreadPool tp(6);
    tp.start();
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 222);
    tp.addOneTask(task_func, 234);
    sleep(3);
    tp.stop();
    return 0;
}

