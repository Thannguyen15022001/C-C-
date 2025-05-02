#include <iostream>


template<typename T> 
class SmartPtr{
private:
    T *ptr;
public:
    SmartPtr(T *exPtr = nullptr):
    ptr(exPtr)
    {}
    ~SmartPtr()
    {
        if(ptr != nullptr)
            delete ptr;
    }

    T &operator *(){
        return *ptr;
    }
    T *operator ->(){
        return ptr;
    }
    SmartPtr<T> &operator = (const SmartPtr<T>&) = delete; //Cấm gọi operator = 
    SmartPtr<T> (const SmartPtr<T>&) = delete; //Cấm copy constructor
    //SmartPtr<T>& operator=(SmartPtr<T>&&) = delete;  //Cấm move
};

class Entity{
private:
    std::string mName;
public:
    Entity(std::string name): mName(name){
        std::cout << "Entity Constructor of instance " + mName << std::endl;
    }
        
    ~Entity(){
        std::cout << "Entity Destructor of instance " + mName << std::endl;
    }
        
    void print(std::string text){
        std::cout << text << std::endl;
    }   
};

int main(){
    {
        SmartPtr<Entity> mySmartPtr(new Entity("Entity"));
        mySmartPtr->print("Hello");
        //SmartPtr<Entity> mySmartPtr_1 = mySmartPtr;  error
        //mySmartPtr_1->print("Hello");
    }

    std::cout << "End main\n";
    return 0;
}