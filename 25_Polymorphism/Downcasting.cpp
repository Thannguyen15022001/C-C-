#include <iostream>

#define M_PI 3.14

struct Point
{
    Point(int x, int y):
    x(x), y(y)
    {}
    int x;
    int y;
};

// polymorphic class
class Shape {
public:
    virtual ~Shape() = default;
    virtual double get_surface() const = 0;
    virtual void describe_object() const { std::cout << "this is a shape" << std::endl; }
    double get_doubled_surface() const { return 2 * get_surface(); }
};

// Derived classes
class Square : public Shape {
private:
    Point top_left;
    double side_length;
public:
    Square (const Point& top_left, double side): 
        top_left(top_left),
        side_length(side_length) 
    {}

    //override
    double get_surface() const override
    { 
        return side_length * side_length; 
    }

    void describe_object() 
    {
        std::cout << "this is a square starting at " << top_left.x << ", " << top_left.y
                  << " with a length of " << side_length << std::endl;
    }
};

class Circle: public Shape { 
private:
    Point center;
    double radius;
public:
    Circle (const Point& center, double radius): 
    center(center), 
    radius(radius) 
    {}

    double get_surface() const override { return radius * radius * M_PI; }

    double get_diameter() { return 2 * radius; }
};

int main(){

    Shape *ptr_square = new Square(Point(10, 10), 10);
    std::cout << static_cast<Circle*>(ptr_square)->get_diameter() << std::endl;

    Circle *ptr_circle =  dynamic_cast<Circle*>(ptr_square);
    if(ptr_circle == NULL){
        std::cout <<"Cast error" << std::endl;
    } else {
        ptr_circle->get_diameter();
    }

    return 0;
}

/*
static_cast:
static_cast là một phép ép kiểu tại thời điểm biên dịch (compile-time cast).
Nó thường được sử dụng để chuyển đổi giữa các kiểu dữ liệu tương tự nhau (ví dụ: chuyển đổi từ int sang double).
static_cast không kiểm tra tính hợp lệ của việc chuyển đổi và không cung cấp bảo vệ chống lại các lỗi kiểu dữ liệu.

dynamic_cast:
dynamic_cast là một phép ép kiểu tại thời điểm chạy (runtime cast).
Nó thường được sử dụng trong kịch bản kế thừa và polymorphism để chuyển đổi con trỏ hoặc tham chiếu từ một lớp cơ sở sang một lớp dẫn xuất hoặc ngược lại.
dynamic_cast kiểm tra tính hợp lệ của việc chuyển đổi và trả về con trỏ hoặc tham chiếu null nếu việc chuyển đổi không hợp lệ.
*/