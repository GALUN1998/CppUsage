//
//  main.cpp
//  Packaged_task
//
//  Created by galun on 2021/9/23.
//

#include <iostream>
#include <future>
#include <thread>
using namespace std;

int test(int number) {
    cout << "Test func" << endl;
    cout << number << endl;
    return number+1;
}

int main(int argc, const char * argv[]) {
    // 将可调用对象包装起来，方便作为线程入口函数
    packaged_task<int(int)> pt(test);
    thread t(ref(pt), 10);
    t.join();
    // 获取结果，保存下来
    future<int> result = pt.get_future();
    cout << result.get() << endl;
}
