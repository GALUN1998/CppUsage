//
//  main.cpp
//  Cast
//
//  Created by galun on 2021/8/31.
//

#include <iostream>
using namespace std;

class base
{
public:
    virtual void m() {cout << "m" << endl;}
};

class derived : public base
{
public:
    void f() {cout << "f" << endl;}
};


int main(int argc, const char * argv[]) {
    // static cast
    int a = 10;
    int b = 7;
    double result = static_cast<double>(a)/static_cast<double>(b);
    cout << result << endl;
    
    // const cast （无奈之举，一般不用）
    const int c = 10;
    const int *p = &c;
    int *q = const_cast<int *>(p);
    // not recommend
    *q = 20;
    cout << c << " " << *p << " " << *q << endl;
    cout << &c << " " << p << " " << q << endl;
    
    // dynamic cast
    base *bas = new derived;
    derived *der;
    // 下行转换
    der = dynamic_cast<derived *>(bas);
    if(der == NULL) {
        cout << "null" << endl;
    } else {
        cout << "not null" << endl;
    }
    
    return 0;
}
