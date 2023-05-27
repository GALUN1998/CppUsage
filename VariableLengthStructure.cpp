#include <iostream>
using namespace std;

struct data {
    int size;
    char flexible[0];
};

int main() {
    // cout << sizeof(data) << endl;

    const char* str = "love zhuozhuo!!!";

    cout << sizeof(str) << endl;
    // cout << sizeof(*str) << endl;

    data* dataPtr = (data*)malloc(sizeof(data)+20);
    memcpy(dataPtr->flexible, str, 20);
    
    cout << dataPtr->flexible << endl;
    free(dataPtr);
    return 0;
}