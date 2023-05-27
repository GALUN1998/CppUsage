//
//  main.cpp
//  MultiThread
//
//  Created by galun on 2021/9/17.
//

#include <iostream>
#include <mutex>
#include <list>
#include <thread>
using namespace std;

class Msg {
private:
    mutex m_mutex;
    mutex m_mutex1;
    mutex m_mutex2;
    list<int> l;
public:
    void recvMsgFunc() {
        for(int i = 0; i < 100; ++i) {
            // 调用了构造函数，离开作用域之后会调用析构函数
            lock(m_mutex1, m_mutex2);
            lock_guard<mutex> lg(m_mutex);
            // m_mutex.lock();
            l.push_back(i);
            // m_mutex.unlock();
            m_mutex1.unlock();
            m_mutex2.unlock();
            cout << "recvMsgFunc, receive:" << i << endl;
        }
    }
    
    void sendMsgFunc() {
        for(int i = 0; i < 100; ++i) {
            m_mutex.lock();
            if(!l.empty()) {
                cout << "sendMsgFunc, send:" << l.front() << endl;
                l.pop_front();
            } else {
                cout << "empty now" << endl;
            }
            m_mutex.unlock();
        }

    }
};
int main(int argc, const char * argv[]) {
    Msg msg;
    // 如果非引用，就会调用拷贝构造函数
    thread t1(&Msg::recvMsgFunc, &msg);
    thread t2(&Msg::sendMsgFunc, &msg);
    
    t1.join();
    t2.join();
    cout << "ending" << endl;
    return 0;
}
