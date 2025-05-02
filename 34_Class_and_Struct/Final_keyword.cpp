// Using for Version ≥ C++11
#include <iostream>

class BaseClassFinal final {

};

//Compile Error 
// class DriverClass : public BaseClassFinal {

// }

class BaseClass {

};

class DriverClass final : public BaseClass {

};

//Compile Error
// class ChirdClass : public DriverClass {

// }


int main(){


}