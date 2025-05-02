//Syntax: return_type (*FuncPtrName) (parameter type, ....);  
#include <iostream>

void print(char *message);

void myPrint(void (*print)(char*), char * message);

class myClass{
public:
    static void entityPrint(char * message){
        std::cout << "This is static print in Entity class\n";
        std::cout << message << std::endl;
    }
};

int main(){
    void (*myFuncPtr)(char *);
    myFuncPtr = &print;   // or myFuncPtr = print;
    myFuncPtr((char*)"Hello world");

    myPrint(myFuncPtr,(char*)"This is message from myPrint");
   
    myFuncPtr = myClass::entityPrint;
    myFuncPtr((char*)"This is message from static print");
    return 0;
}

void print(char *message)
{
    std::cout << message << std::endl;
}

void myPrint(void (*print)(char*), char * message)
{
    std::cout << "This is myPrint\n";
    print(message);
}

