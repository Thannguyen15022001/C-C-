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
        mBuffer[mSize] = 0;
    }

    ~String(){
        std::cout << "Destructor" << std::endl;
        delete mBuffer;
    }

    char &operator[](int index){
        return mBuffer[index];
    }

    //Default copy constructor => just shallow copy
    // String(const String &other):
    //     mSize(other.mSize),
    //     mBuffer(other.mBuffer)
    // {
    //     std::cout << "Shallow copy constructor\n";
    // }

    unsigned int size(){
        return mSize;
    }

    friend std::ostream& operator <<(std::ostream &os, const String &other){
        os << other.mBuffer;
        return os;
    }
};


//Shallow copy vào 1 bản sao trong hàm func và bản sao này và bản gốc đều trỏ tới cùng 1 địa nên 
//khi thay đổi giá trị và thoát khỏi hàm thì bản sao sẽ delete và khi bản gốc lấy data từ địa chỉ đó thì không còn
//Giai pháp: dùng tham chiếu hạn chế copy => tăng tốc độ cpu
void func(String string){
    std::cout << string << std::endl;
    if(string.size() > 2){
        string[2] = 'k';
    }
}

void reFunc(String& string){
    std::cout << string << std::endl;
    if(string.size() > 2){
        string[2] = 'k';
    } 
}

int main(){
    String myString("Hello");
    String mySecondString = myString; //mBuffer cùng chung địa chỉ sẽ sảy ra undefind behavior khi delete mBuffer
    mySecondString[2] = 'a';
    std::cout << mySecondString  << std::endl;
    std::cout << myString << std::endl;

    String str("Hello world");
    //func(str);
    reFunc(str);
    std::cout << str << std::endl;

    return 0;
}

// Shallow copy chỉ copy nội dung còn về con trỏ thì chỉ copy địa chỉ