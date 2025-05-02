#include <iostream>


class Guaranteed{
public:
    Guaranteed() = default;
    Guaranteed(const Guaranteed& other) = delete;   //copy constructor
    Guaranteed(Guaranteed&& other) = delete;        //Move constructor
};

Guaranteed getGuaranteed(){
    return Guaranteed();    //Compile error from C++11 before and compile ok from C++17
}

int main()
{
    Guaranteed guaranteed = getGuaranteed();
    return 0;
}

/*
    C++11:
    Từ C++11 trở lui, copy elision là tối ưu hóa không bắt buộc (optional). Trình biên dịch phải giả định rằng một copy hoặc move constructor sẽ được gọi, 
    ngay cả khi nó biết rằng sẽ elide. Nghĩa là copy/move bị lượt bỏ bởi compiler nhưng vẫn phải bắt buộc có move/copy constructor được defind (bởi vì copy elision chỉ là optional)

    C++17:
    Từ C++17 trở đi trong các tình huống như return T(...), compiler không cần phải có copy/move constructor tồn tại, vì nó bắt buộc phải elide (copy elision là bắt buộc)
*/