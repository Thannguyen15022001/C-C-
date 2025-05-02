#include <iostream>
#include <cstring>

class String{
private:
    unsigned int mSize;
    char *mBuffer;
public:
    explicit String(const char *str){
        mSize = strlen(str);
        mBuffer = new char[mSize + 1];
        memcpy(mBuffer,(void*)str,mSize);
        mBuffer[mSize] = '\0';
    }
    
    ~String(){
        std::cout << "Destructor" << std::endl;
        delete mBuffer;
    }
    
    char &operator[](int index){
        return mBuffer[index];
    }
    
    //Deep copy
    String(const String &other)
    {
        std::cout << "Deep copy constructor\n";
        mBuffer = new char[other.mSize];
        memcpy(mBuffer,other.mBuffer,other.mSize);
    }

    //Deep copy in assigment operator => nếu ko defind lại thì vẫn là shallow copy 
    String &operator=(const String &other)
    {
        if(this != &other){
            //Not correct due to maybe other.mSize > his->mSize so memory not enough
            // this->mSize = other.mSize;
            // memcpy(mBuffer,other.mBuffer,other.mSize);

            //Correct
            delete[] mBuffer;
            this->mSize = other.mSize;
            this->mBuffer = new char[mSize + 1];
            memcpy(this->mBuffer,other.mBuffer,this->mSize);
            this->mBuffer[mSize] = '\0';
        }
        return *this;
    }
    
    unsigned int size(){
        return mSize;
    }
    
    friend std::ostream& operator <<(std::ostream &os, const String &other){
        os << other.mBuffer;
        return os;
    }
};

int main(){
    String myString("Hello world");
    String mySecondString("World");
    mySecondString = myString;
    mySecondString[2] = 'a';
    std::cout << mySecondString  << std::endl;
    std::cout << myString << std::endl;
    return 0;
}