#include <iostream>

void friendFunction();
void nonFriendFunction();


class PrivateHolder{
    friend void friendFunction();
public:
    PrivateHolder(int exValue):
    privateValue(exValue)
    {}
private:
    int privateValue;
};

class DriverHolder : public PrivateHolder {
public:
    DriverHolder(int exValue): PrivateHolder(exValue){}
private:
    int privateDriverValue = 0;

};

void friendFunction(){
    PrivateHolder privateHoder(10);

    std::cout << "Private value of class PrivateHolder: " << privateHoder.privateValue << std::endl;

    /*
    Note that PrivateHolderDerived member function cannot access PrivateHolder::private_value, while friend
    function can do it
    */
    DriverHolder driverHolder(10);
    std::cout << "Private value of class PrivateHolder in DriverHolder: " << driverHolder.privateValue << std::endl;

    //Error because Friend declarations are not inherited
    //std::cout << "Private value of class DriverHolder : " << driverHolder.privateDriverValue << std::endl;
}

void nonFriendFunction(){
    PrivateHolder privateHoder(10);
    //Error
    //std::cout << "Private value of class PrivateHolder: " << privateHoder.privateValue << std::endl;
}

int main(){

    friendFunction();
    return 0;
}