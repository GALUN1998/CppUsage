#include <iostream>
using namespace std;

string stringMulti(string s1, string s2) {
    int number1 = atoi(s1.c_str());
    int number2 = atoi(s2.c_str());
    int result = number1 * number2;
    return to_string(result);
}

int main() {
    string s1 = "100";
    string s2 = "2";
    cout << stringMulti(s1, s2) << endl;
    return 0;
}