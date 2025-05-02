#include <iostream>

class Accesser{
public: 
    Accesser(int exval):
    privateValue(exval)
    {}
    void accessPrivate();
private:
    int privateValue;
};

class PrivateHoder{
public:
    PrivateHoder(int exValue):
    privateValue(exValue)
    {}
    friend class Accesser;
private:
    int privateValue;
    void accessPrivate();
};

void Accesser::accessPrivate(){
    PrivateHoder privateHoder(10);

    std::cout <<"Access private value of PrivateHoder class: " << privateHoder.privateValue << std::endl;  
}

void PrivateHoder::accessPrivate(){
    Accesser accesser(10);
    // Can't access to private value of Accesser class because PrivateHoder class isn't friend class of Accesser class
    //std::cout <<"Access private value of PrivateHoder class: " << accesser.privateValue << std::endl;  
}

int main(){
    Accesser accesser(10);
    accesser.accessPrivate();

    return 0;
}