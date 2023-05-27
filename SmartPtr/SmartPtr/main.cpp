//
//  main.cpp
//  SmartPtr
//
//  Created by galun on 2021/8/28.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // c++11 not support
    // auto_ptr<string> autoPtr1(new string("Hi Smart Ptr"));
    // auto_ptr<string> antoPtr2;
    // autoPtr2 = autoPtr1;
    
    // cannot be copy
    unique_ptr<string> uniquePtr(new string("Hi Unique Ptr"));

    shared_ptr<string> sharedPtr1(new string("Hi Shared Ptr"));
    shared_ptr<string> sharedPtr2;
    sharedPtr2 = sharedPtr1;
    cout << *sharedPtr1 << endl;
    cout << sharedPtr1.use_count() << endl;
    
    sharedPtr1.reset();
    cout << sharedPtr2.use_count() << endl;
    
    
    weak_ptr<string> weakPtr(sharedPtr1);
    cout << sharedPtr1.use_count() << endl;
    cout << "done" << endl;
    return 0;
}
