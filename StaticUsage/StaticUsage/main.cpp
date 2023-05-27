//
//  main.cpp
//  StaticUsage
//
//  Created by galun on 2021/8/29.
//

#include <iostream>
using namespace std;

class Bitch {
    static int girl;
    int boy;
public:
    // static函数内部只能对staic变量进行操作
    static void getTheGirl() {
        cout << "girl's age :" << girl << endl;
    }
};

// 只能在类外进行初始化
int Bitch::girl = 18;

int main(int argc, const char * argv[]) {
    Bitch b;
    b.getTheGirl();
    return 0;
}
