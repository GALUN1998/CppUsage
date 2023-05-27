//
//  main.cpp
//  Lambda
//
//  Created by galun on 2021/9/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // 1
    auto basicLambda = [] { std::cout << "Hello lambda!" << std::endl; };
    // basicLambda();
    // 2
    auto add = [](int a, int b) { return a+b; };
    // std::cout << add(0, 1) << std::endl;
    // 3
    int val = 3;
    vector<int> v = {1, 3, 4, 5, 7, 9};
    int count = count_if(v.begin(), v.end(), [val](int x) { return x > val; });
    // cout << count << endl;
    // 4
    sort(v.begin(), v.end(),[](int a, int b) { return a > b;});
    for(auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
