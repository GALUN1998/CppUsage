//
//  main.cpp
//  ConstUsage
//
//  Created by galun on 2021/8/29.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    const int val = 10;
    int val2 = 10;
    int val3 = 10;
    // 修饰指针，指针是常量
    int * const ptr = &val2;
    // 修饰指针指向的变量，指针指向为常量
    int const * ptr2 = &val2;
    
    // forbidden: ptr = &val3;
    // forbidden: *ptr2 = 3;
    val2 = 3;

    cout << val << endl;
    cout << val2 << endl;
    
    return 0;
}
