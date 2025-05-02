#include <iostream>

class Set{
private:
    int card;
public:
    Set(void){card = 0;}

    // Hàm này không thay đổi dữ liệu của đối tượng
    void show() const {
        std::cout << "Card: " << card << std::endl;
    }

        // Hàm này có thể thay đổi dữ liệu của đối tượng
    void setValue(int v) {
        card = v;
    }
};

/*
Hàm const chỉ có thể gọi các thành viên const
Trong một hàm const, bạn không thể gọi một hàm không const
*/

class Example {
private:
    int value;

public:
    Example(int v) : value(v) {}

    void show() const {
        std::cout << "Giá trị: " << value << std::endl;
        // setValue(30); // Lỗi! Không thể gọi hàm không const từ hàm const
    }

    void setValue(int v) {
        value = v;
    }
};

/*Hàm const trong kế thừa*/
class Base {
public:
    virtual void display() const {
        std::cout << "Hàm display() của Base\n";
    }
};

class Derived : public Base {
public:
    void display() const override { // Ghi đè hàm const
        std::cout << "Hàm display() của Derived\n";
    }
};

int main() {
    Set obj;

    obj.show();      // Được phép gọi vì show() là hàm const
    obj.setValue(20); 
    obj.show();      // Vẫn hoạt động bình thường


    const Example obj_1(10);  // Đối tượng hằng số

    obj_1.show();   // Được phép vì show() là const
    // obj_1.setValue(20); // Lỗi! Vì setValue() không phải là const

    Base* ptr;
    Derived obj_2;
    ptr = &obj_2;

    ptr->display(); // Gọi hàm display() của Derived

    return 0;
}