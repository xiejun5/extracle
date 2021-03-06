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
#include <map>
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
    :  max_threads_num(n) {}
    void start() {
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
        return ;
    }
    void worker() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = true;
        while (is_running[id]) {
            //取任务
            Task *t = this->getOneTask();
            //执行任务
            (*t)();
            //释放任务
            delete t;

       }
    }
    void stop() {
        for (int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
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
    void stop_task() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = false;
        return ;
        
    }
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);
        while (task_queue.empty()) m_cond.wait(lock);//等待，直到队列中存在任务
        //在等待添加任务时，临时释放胡互斥锁。
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    int max_threads_num;
    vector<thread *> threads;
    queue<Task *> task_queue;
    std::map<std::thread::id, bool> is_running;
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
    cout << x << endl;
}

int cnt = 0;

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void cout_prime(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (is_prime(i)) __sync_fetch_and_add(&cnt, 1);
    }

    return ;
}

int main() {
    cout << "hello haizeix, amazing" << endl;
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
    for (int i = 0, j = 1; i < 5; i++, j+= 200000) {
        tp.addOneTask(cout_prime, j, j + 200000 - 1);
    }
    tp.stop();
    cout << cnt << endl;
    return 0;
}

