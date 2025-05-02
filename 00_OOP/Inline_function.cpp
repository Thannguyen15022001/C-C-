#include <iostream>

class Point {
private:
    int xVal, yVal;
public:
    void Setpt(int, int);
    void OffsetPt(int, int);
};

inline void Point::Setpt(int x, int y){
    xVal = x;
    yVal = y;
}




int main(){


    return 0
}