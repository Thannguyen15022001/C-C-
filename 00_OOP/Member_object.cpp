#include <iostream>

// The contained object’s class has an accessible default constructor.
// class Point {
// public:
//     Point(){
//         std::cout << "Constructor of Point was called\n";
//     }
// };

// class Rectangle {
// private:
//     Point top;
//     Point bottom;
// public:
//     Rectangle(){
//         std::cout << "Constructor of Rectangle was called\n";
//     }
// };


class Point {
    int xVal;
public:
    Point(int val){
        xVal = val;
        std::cout << "Constructor of Point was called\n";
    }
};

class Rectangle {
private:
    Point top;
    Point bottom;
public:
    Rectangle(int xVal, int yVal)
    :top(xVal),bottom(yVal)
    {
        std::cout << "Constructor of Rectangle was called\n";
    }
};

int main(){
    Rectangle Rec(10,5); 

    return 0;
}