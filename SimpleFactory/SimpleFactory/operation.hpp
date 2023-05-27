//
//  operation.hpp
//  SimpleFactory
//
//  Created by galun on 2021/9/25.
//

#ifndef operation_hpp
#define operation_hpp
#include <iostream>
#include <stdio.h>

class Operation {
private:
    int numberA;
    int numberB;

public:
    int getNumberA(void) {
        return numberA;
    }
    int getNumberB(void) {
        return numberB;
    }
    void setNumberA(int _numberA) {
        numberA = _numberA;
    }
    void setNumberB(int _numberB) {
        numberB = _numberB;
    }
    virtual int getResult() {
        std::cout << "虚函数" << std::endl;
        return 0;
    };
};

class Add: public Operation {
public:
    int getResult() override {
        return getNumberA() + getNumberB();
    }
};

class Sub: public Operation {
public:
    int getResult() override {
        return getNumberA() - getNumberB();
    }
};

class Mul: public Operation {
public:
    int getResult() override {
        return getNumberA() * getNumberB();
    }
};

class Div: public Operation {
public:
    int getResult() override {
        std::cout << getNumberA() << std::endl << getNumberB() << std::endl;
        if(getNumberB() == 0) {
            std::cout << "除数不能为0" << std::endl;
            return 0;
        }
        return getNumberA() / getNumberB();
    }
};

class OperationFactory {
public:
    Operation* creatOperate(char numberOperator) {
        Operation* ops = nullptr;
        switch (numberOperator) {
            case '+':
                ops = new Add;
                break;
            case '-':
                ops = new Sub;
                break;
            case '*':
                ops = new Mul;
                break;
            case '/':
                ops = new Div;
                break;
            default:
                break;
        }
        return ops;
    }
};
#endif /* operation_hpp */
