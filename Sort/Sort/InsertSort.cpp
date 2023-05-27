//
//  InsertSort.cpp
//  Sort
//
//  Created by galun on 2021/9/12.
//

#include "InsertSort.hpp"
#include <vector>
using namespace std;

void InsertSort(vector<int>& v) {
    if(v.size() <= 1) return;
    int n = (int)v.size();
    for(int i = 0; i < n; ++i) {
        // one by one
        for(int j = i; j > 0 && v[j] < v[j-1]; --j) {
            swap(v[j], v[j-1]);
        }
    }
}
