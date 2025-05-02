#include <iostream>
#include <memory>
#include <string>

class Entity{
private:
    std::string mName;
public:
    Entity(std::string name): mName(name){
        std::cout << "Entity Constructor\n";
    }
        
    ~Entity(){
        std::cout << "Entity Destructor\n";
    }
        
    void print(std::string text){
        std::cout << text << std::endl;
    }  
};


int main(){

    {
        std::weak_ptr<Entity> weak_ptr;
        {
            std::shared_ptr<Entity> shared_ptr = std::make_shared<Entity>("Shared pointer");
            weak_ptr = shared_ptr;
            
            if(std::shared_ptr<Entity> temp = weak_ptr.lock()){
                temp->print("Hello");
            } else {
                std::cout << "Shared pointer object is destroy\n";
            }
        }
        if(std::shared_ptr<Entity> temp = weak_ptr.lock()){
            temp->print("Hello");
        } else {
            std::cout << "Shared pointer object is destroy\n";
        }
    }


    return 0;
}


/*
    std::weak_ptr is a smart pointer in C++, used to observe a std::shared_ptr without owning the object.
    Does not increase the reference count.
    Helps avoid circular references when using shared_ptr.

*/