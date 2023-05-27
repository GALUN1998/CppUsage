#include <iostream>
#include <algorithm>
using namespace std;

char* MyReverse(char* str) {
    char* begin = str;
    char* temp = str;
    int size = 0;
    while(*temp != '\0') {
        ++size;
        ++temp;
    }
    char* end = str+size-1;
    while(begin < end) {
        char tmp = *begin;
        *begin = *end;
        *end = tmp;
        ++begin;
        --end;
    }
    return str;
}

int main() {
    // 不能用char* str, 否则会被认为是常量, 不允许修改
    char str[]= "Iloveyou";
    cout << MyReverse(str) << endl;
    return 0;
}