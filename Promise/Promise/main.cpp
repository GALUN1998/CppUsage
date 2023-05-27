//
//  main.cpp
//  Promise
//
//  Created by galun on 2021/9/23.
//

#include <iostream>
#include <future>
#include <thread>
using namespace std;

void send(int number, promise<int> &msg) {
    number++;
    number *= 2;
    msg.set_value(number);
    return;
}

void receive(promise<int> &msg) {
    // promise和packaged_task都用get_future()获取结果
    future<int> result = msg.get_future();
    // 输出结果
    cout << result.get() << endl;
}
int main(int argc, const char * argv[]) {
    promise<int> msg;
    thread t1(send, 9, ref(msg));
    thread t2(receive, ref(msg));
    t1.join();
    t2.join();
    return 0;
}
