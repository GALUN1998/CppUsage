#include <iostream>
#include <vector>
using namespace std;

void Heapify(vector<int>& numbers, int heapsize, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int max = index;
    if((left < heapsize) && (numbers[left] > numbers[max])) {
        max = left;
    }
    if((right < heapsize) && (numbers[right] > numbers[max])) {
        max = right;
    }
    // 发生了交换
    if(max != index) {
        swap(numbers[max], numbers[index]);
        Heapify(numbers, heapsize, max);
    }
}

void BuildHeap(vector<int>& numbers, int heapsize) {
    for(int i = heapsize/2-1; i >= 0; --i) {
        Heapify(numbers, heapsize, i);
    }
}

void HeapSort(vector<int>& numbers, int heapsize) {
    BuildHeap(numbers, heapsize);
    int not_sort_size = heapsize;
    while(not_sort_size != 0) {
        swap(numbers[0], numbers[not_sort_size-1]);
        --not_sort_size;
        Heapify(numbers, not_sort_size, 0);
    }
}

int main() {
    vector<int> numbers = {11, 2, 8, 9, 4, 3, 25, 1};
    int heapsize = numbers.size();
    HeapSort(numbers, heapsize);
    for(int i = 0; i < heapsize; ++i) {
        cout << numbers[i] << endl;
    }
}