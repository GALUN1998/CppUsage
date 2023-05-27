//
//  main.cpp
//  CopyConstructor
//
//  Created by galun on 2021/9/17.
//

#include <iostream>
using namespace std;

class Shape {
private:
    int width;
    int length;

public:
    Shape(int w, int l): width(w), length(l) {}
    Shape(const Shape & s) {
        length = s.length;
        width = s.width;
    }
    void print() {
        cout << length << endl << width << endl;
    }
};
int main(int argc, const char * argv[]) {
    Shape s(1, 8);
    Shape s2(s);
    s2.print();
    return 0;
}
