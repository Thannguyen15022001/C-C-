#include <iostream>


class Class {
public:
    Class(int x, int y, int z):
        mX(x), mY(y), mZ(z)
    {}
    int mX, mY, mZ;
    char mM, mN, mO;

    static int mStaticVariable;
};

int Class::mStaticVariable = 7777;

int globalVariable = 100;


int main(){
    Class myClass(10,20,30);
    Class *ptrClass = &myClass;

    int *ptrI;      //can point any where
    ptrI = &myClass.mX;
    //ptrI = &Class::mX;             //compile error data type int * != int Class::*
    ptrI = &globalVariable;
    ptrI = &Class::mStaticVariable;  


    int Class::*ptrInClass;   //Just point within class can't point outside Class and need instance to access
    ptrInClass = &Class::mX;
    //ptrInClass = &globalVariable;   //error
    //ptrInClass = &Class::mStaticVariable;  //error

    myClass.*ptrInClass = 9999;
    std::cout << myClass.mX << std::endl;
    ptrClass->*ptrInClass =8888;
    std::cout << myClass.mX << std::endl;


    char Class::*charPtrInClass = &Class::mM;
    return 0;
}