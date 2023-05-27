//
//  main.cpp
//  SimpleFactory
//
//  Created by galun on 2021/9/25.
//

#include <iostream>
#include "operation.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    OperationFactory op;
    Operation* ptr = nullptr;
    ptr = op.creatOperate('+');
    ptr->setNumberA(10);
    ptr->setNumberB(10);
    cout << ptr->getResult() << endl;
    return 0;
}
