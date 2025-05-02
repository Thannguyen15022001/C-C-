#include <iostream>


struct MyException
{
    MyException(){
        std::cout << "This is constructor\n";
    }

    MyException(const MyException &other){
        std::cout << "This is copy constructor\n";
    }

    
};


void myFunction(){
    try{
        //Tạo 1 temporary object và copy vào exception object
        MyException ex;
        std::cout << &ex << std::endl;
        throw ex;
    } catch(MyException &e){  //=> copy từ exception object vào e (nếu ở đây dùng &e thì biến e trỏ thẳng đến exception object, còn nếu dùng e thì xảy ra copy constructor)
        std::cout << &e << std::endl;;
        std::cout << "Catch exception\n";
    }   
} 

int main(){
    myFunction();

    return 0;
}
