//Syntax: return_type (className::*ptr) (parameter type, ....);  
//Use: (Obj.*ptr)(arg, ...)
//Or
//Syntax: typedef return_type funcName(parameter type, ....)
#include <iostream>

typedef void Fn(char*);


class Entity{
public:
    void print(char* message){
        std::cout << message << std::endl;
    }
};

int main(){

    Entity entity;
    Entity *ptrEntity = &entity;

    void (Entity::*funcPtr)(char*);
    Fn Entity::*fnPtr;

    funcPtr = Entity::print;
    // funcPtr("Hello world");  => compile error  require ObjectName->*funcPtr("Hello world")"expression preceding parentheses of apparent call must have (pointer-to-) function typeC/C++"
    fnPtr = &Entity::print;

    (entity.*funcPtr)((char*)"Hello world");
    (ptrEntity->*funcPtr)((char*)"Hello world");
    return 0;
}

/*
    Địa chỉ hàm được lưu trong text segment
    Khi muốn gọi 1 hàm của 1 class thông qua con trỏ thì phải biết được object nào gọi (this pointer) và con trỏ hàm của hàm đó
*/