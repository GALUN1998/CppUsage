//
//  main.cpp
//  Singleton
//
//  Created by galun on 2021/9/19.
//

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

std::once_flag g_flag;
class singleton {
    static void createInstance() {
        m_ptr = new singleton;
        static subSingleton sub;
        cout << "只调用一次" << endl;
    }
private:
    singleton(){}
private:
    static mutex m_mutex;
    static singleton* m_ptr;
public:
    static singleton* getInstance() {
//        lock_guard<mutex> lg(m_mutex);
//        std::cout << "getInstance调用" << std::endl;
//        if(m_ptr == nullptr) {
//            m_ptr = new singleton;
//            static subSingleton sub;
//        }
        std::call_once(g_flag, createInstance);
        return m_ptr;
    }
    class subSingleton {
    public:
        ~subSingleton() {
            if(m_ptr != nullptr) {
                delete m_ptr;
                m_ptr = nullptr;
                std::cout << "主函数结束，类静态函数生命周期结束，调用析构函数释放对象指针" << std::endl;
            }
        }
    };
    void printFunc() {
        std::cout << "通过类对象调用成员函数" << std::endl;
    }
};

singleton* singleton::m_ptr = nullptr;
mutex singleton::m_mutex;

int main(int argc, const char * argv[]) {
    thread th1(singleton::getInstance);
    thread th2(singleton::getInstance);
    th1.join();
    th2.join();
    std::cout << "主函数结束前" << std::endl;
    return 0;
}
