//
//  SelectSort.cpp
//  Sort
//
//  Created by galun on 2021/9/12.
//

#include "SelectSort.hpp"
#include <iostream>
#include <vector>
using namespace std;

void SelectSort(vector<int>& v) {
    if(v.size() <= 1) return;
    int n = (int)v.size();
    for(int i = 0; i < n - 1; ++i) {
        int index = i;
        for(int j = i + 1; j < n; ++j) {
            if(v[j] < v[index]) {
                index = j;
            }
        }
        swap(v[index], v[i]);
    }
}
