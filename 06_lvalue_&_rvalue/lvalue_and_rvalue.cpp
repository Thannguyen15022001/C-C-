#include <iostream>
#include <string>


void get_lvalue(int &a){
    std::cout << "This is lvalue: " << a << std::endl;
}

void get_rvalue(int &&a){
    std::cout << "This is rvalue: " << a << std::endl;
}


/*
    ở đây t có thể dùng const reference bởi vì complier khi truyền giá trị vào hàm thì nó sẽ tạo ra một biến tạm
    và const reference sẽ tham chiếu tới biến tạm đó và không thay đổi giá trị của nó nhưng đối với con trỏ thì không được
    bởi vì compiler ko tạo biến tạm
*/
void get_rvalue_and_lvalue(const int& a){
    std::cout << "This is rvalue or lvalue: " << a << std::endl;
}

int& return_lvalue(){
    static int lvalue = 10;
    return  lvalue;
}

int&& return_rvalue(){
    return 10;
}


int main(){

    int a = 10; // a is lvalue and 10 is rvalue
    std::string firstName = "Nguyen"; //firstName is lvalue and "Nguyen" rvalue
    std::string lastName = "Than"; //lastName is lvalue and "Than" rvalue

    std::string fullName = firstName + lastName; //fullName is lvalue and firstName + lastName rvalue
    //10 = a   => error can't assign rvalue for another variable or value

    get_lvalue(a);
    //get_lvalue(10);   => error need lvalue have address
    get_rvalue(10);
    //get_rvalue(a);    => error need to rvalue 


    return_lvalue() = 100;
    //return_rvalue() = 100;  => error due to return rvalue

    get_rvalue_and_lvalue(10);
    get_rvalue_and_lvalue(a);

    get_lvalue(++a);
    //get_lvalue(a++);  => error tại sao?


    return 0;
}

// lvalue (locator value) represents a specific memory location and its address can be taken
// rvalue (read value or right value): an rvalue is an expression that does not represent a specific memory location — its address cannot be taken directly.
//  + Usually a temporary value, a constant, or the result of an expression.
//  + Cannot assign a value to an rvalue.

// Phân biện a++ và ++a;
// int a = 10;
// int b = a++;   b = 10, a = 11 => trả về 1 biến tạm (=> rvalue) lưu giá trị cũ của a gắn cho b rồi sau đó mới tăng a lên 1

// int a = 10;
// int b = ++a;   b = 11, a = 11  => tăng a lên 1 và trả về a (biến có địa chỉ cụ thể => lvalue) 

