#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int>& data, int key, int left, int right) {
    // 当left > right，代表找不到
    if(left <= right) 
    {   
        int mid = (left + right)/2; 
        if(key > data[mid]) {
            // 记得return
            return BinarySearch(data, key, mid+1, right);
        } else if(key < data[mid]) {
            return BinarySearch(data, key, left, mid-1);
        } else {
            return mid;
        }
    }
    // 要给返回值，不然有可能出问题，返回值会乱七八糟的
    return -1;
}

int main() {
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 9};
    int index = BinarySearch(data, 10, 0, data.size()-1);
    if(index == -1) {
        cout << "not found" << endl;
    } else {
        cout << index << endl;
    }
    return 0;
}