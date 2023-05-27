//
//  main.cpp
//  FuncPtr
//
//  Created by galun on 2021/8/31.
//

#include <iostream>
using namespace std;

int * func(int *p) {
    if(p == nullptr) {
        cout << "nullptr" << endl;
        return nullptr;
    } else {
        return p;
    }
}

int main(int argc, const char * argv[]) {
    int * ptr = nullptr;
    int num = 10;
    int * ptr2 = &num;
    int * (*pf)(int *p);
    pf = func;
    pf(ptr);
    cout << *pf(ptr2) << endl;
    return 0;
}
