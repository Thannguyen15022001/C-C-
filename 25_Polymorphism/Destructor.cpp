#include <iostream>


// polymorphic class
class VirtualDestructor {
public:
    virtual ~VirtualDestructor() = default;  // If doesn't define vertual destructor then Destructor of driver class isn't called
};

// Driver class
class VirtualDriver : public VirtualDestructor{
public:
    ~VirtualDriver(){
        std::cout << "VirtualDriver is called" << std::endl;
    }
};

// polymorphic class
class ProtectedDestructor {
protected:
    ~ProtectedDestructor() = default;
};

// Driver class
class ProtectedDriver : public  ProtectedDestructor{
public:
    ~ProtectedDriver(){
        std::cout << "ProtectedDriver is called" << std::endl;
    }
};

int main(){

/*
In the this case, this will cause object
destruction to check the vtable, automatically calling the correct destructor based on the dynamic type
*/
    VirtualDestructor *ptr_Des = new VirtualDriver();
    delete ptr_Des;  //Destructor of Square doesn't call because class Shape doesn't defined vertual destructor


/*
In the this case, destroying the object through a base class pointer/reference is disabled, and the object can only be
deleted when explicitly treated as its actual type.
*/
    ProtectedDestructor *ptr_Pro = new ProtectedDriver();
    delete static_cast<ProtectedDriver*>(ptr_Pro);
    //delete ptr_Pro  ERROR

    return 0;
}

/*

If a class is intended to be used polymorphically, with derived instances being stored as base pointers/references,
its base class' destructor should be either virtual or protected. 

*/