#include <iostream>


class String{
public:
    String(const char *str){
        std::cout << "Constructor\n";
    }

    String(const String& other){
        std::cout <<"Copy constructor\n";
    }

    String(String&& other){
        std::cout <<"Move constructor\n";
    }
        
    ~String(){
        std::cout << "Destructor" << std::endl;
    }
};


void normalFunc(String str){

}


void referenceFunc(String &str){

}

void constRefFunc(const String &str)
{
    std::cout << "Address temporary variable: " << &str << std::endl;
}

int main(){
    /*
    When you pass an argument to a function, and the argument is a prvalue expression of the function's parameter
    type, and this type (argument of function) is NOT a REFERENCE, then the prvalue's construction can be elided.
    */
    normalFunc("Hello");  //or normalFunc(String("Hello"))  => copy constructor will be elided (prvalue is passed to lvalue)

    String str("Hello");
    normalFunc(str);      //copy constructor will be occur because lvalue is passed to lvalue


    /*
    error bởi vì hàm referenceFunc cần một tham chiếu nhưng do chúng ta truyền vào 1 prvalue nên hàm không thể tham chiếu đến biến 
    tạm đó được => để có thể tham chiếu đến biến tạm chúng ta cần defind "const" (void referenceFunc(const String &str)) lúc này hàm
    sẽ tham chiếu đến địa chỉ biến tạm và không thể thay đổi giá trị của biến tạm.
    */
    //referenceFunc("Hello"); 
    constRefFunc("Hello");
    return 0;
}
