#include <iostream>

class Accesser{
public:
    void friendMethod();
};


class PrivateHolder{
public:
    PrivateHolder(int exValue): privateValue(exValue){}
private:
    int privateValue;
    friend void Accesser::friendMethod();
};

void Accesser::friendMethod(){
    PrivateHolder privateHolder(10);

    std::cout <<"Private value of friend class: " << privateHolder.privateValue << std::endl;
}

int main(){
    Accesser accesser;

    accesser.friendMethod();
}