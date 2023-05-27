//
//  QuickSort.cpp
//  Sort
//
//  Created by galun on 2021/9/14.
//

#include "QuickSort.hpp"
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&vec, int low, int high) {
    int pivot = vec[low];
    while(low < high) {
        while(low < high && vec[high] >= pivot) {
            high--;
        }
        vec[low] = vec[high];
        while(low < high && vec[low] <= pivot) {
            low++;
        }
        vec[high] = vec[low];
    }
    vec[low] = pivot;
    return low;
}

void QuickSort(vector<int>&vec, int low, int high) {
    if(low < high) {
        int pivot = partition(vec, low, high);
        QuickSort(vec, low, pivot-1);
        QuickSort(vec, pivot+1, high);
    }
}
