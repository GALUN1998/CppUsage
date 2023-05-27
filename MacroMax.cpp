#include <iostream>
using namespace std;
#define MAX(a,b) ({int _a = a; int _b = b; _a > _b ? _a : _b;})

int main()
{
    cout << MAX(10, 5) << endl;
    return 0;
}