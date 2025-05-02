#include <iostream>


struct S 
{
    int mX;
    explicit S(int x): mX(x){
        std::cout << "Construct S(" << mX << ")\n";
    }

    //Copy constructor
    S(const S &other): mX(other.mX){
        std::cout <<"Copy S(" << mX << ")\n";
    }

    ~S(){
        std::cout <<"Destructor\n";
    }
};

//Named Return Value Optimization có thể bật tắt bằng -fno-elide-constructors
S makeValue_NRVO(int value){
    S s(value);  //tạo trực biến s và copy vào return value           // S s = value  -> tạo 1 biến tạm với giá trị value rồi sau đó gắn lại cho giá trị s rồi sau đó copy vào return value
    return s; 
    
    //the same
    //return S(value);
}

//Unnamed Return Value Optimization  bắt buộc từ c++17 cho dù tắt cờ -fno-elide-constructors
S makeValue_URVO(int value){
    return S(value); 
    //Tạo 1 biến temporary object
    //Copy từ temporary → exception object (hoặc return value object)
    //Trình biên dịch sẽ copy temp1 vào một vùng nhớ đặc biệt gọi là return value object (tạm gọi temp2) — nơi lưu kết quả để trả về.
}

S makeDoubleValue(int value){
    S s = makeValue_NRVO(value);
    s.mX = 2*value;
    return s;
}

int main(){
    S myValue = makeValue_NRVO(100);
    return 0;

}


//$  g++ -O0 -fno-elide-constructors -o main main.cpp     -fno-elide-constructors: disable elision copy
//Chỉ áp dụng cho kiểu dữ liệu class và ko áp dụng cho kiểu dữ liệu nguyên thủy như int, char, float .. (tùy compiler)