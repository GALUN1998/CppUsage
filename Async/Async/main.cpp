//
//  main.cpp
//  Async
//
//  Created by galun on 2021/9/23.
//

#include <iostream>
#include <future>
using namespace std;

int test(int number) {
    cout << number << endl;
    return number+1;
}

class Test {
public:
    int testMemberFunc(int number) {
        cout << "member func" << endl;
        cout << number << endl;
        return number+2;
    }
};
int main(int argc, const char * argv[]) {
    future<int> result = async(test, 10);
    int ret = result.get();
    cout << ret << endl;
    
    Test t;
    future<int> result2 = async(&Test::testMemberFunc, &t, 10);
    int ret2 = result2.get();
    cout << ret2 << endl;
    return 0;
}
