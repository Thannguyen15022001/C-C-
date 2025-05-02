// TOPIC: Shared pointer In C++ (from C++11)

//NOTES:
//1. shared_ptr is a smart pointer which can share the ownership of object (managed object).
//2. Several shared_ptr can point to the same object (managed object).
//3. It keep a reference count to maintain how many shared_ptr are pointing to the same object and
//   once last shared_ptr goes out of scope then the managed object gets deleted.
//4. shared_ptr is threads safe and not thread safe.
//   a. control block is thread safe => When multiple threads copy, assign, or destroy a shared_ptr, updating the reference count is guaranteed to be safe and not cause a race condition.
//   b. managed object is not safe. => race condition when multiple thread access to object
//5. There are three ways shared_ptr will destroyed managed object.
//   a. If the last shared_ptr goes out of scope.
//   b. If you initialize shared_ptr with some other shared_ptr
//   c. If you reset shared_ptr.
//6. Reference count doesn't work when we use reference or pointer of shared_ptr.
//More info.
//Control block contain: reference count, weak count(if has weak_ptr), Deleter


#include <iostream>
#include <memory>
#include <string>
#include <thread>


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

void myThread(std::shared_ptr<Entity> arg){
    std::cout << "Reference cout: " << arg.use_count() << std::endl;
    //If thread modify object it is not safe => race condition.
}

int main(){

    {
        std::shared_ptr<Entity> entity_0 = std::make_shared<Entity>("entity_0");
        
        {
            std::shared_ptr<Entity> entity_1 = entity_0;
            entity_1->print("Hello I'm entity_1");   
        }
        entity_0->print("Hello I'm entity_0");
    }
    std::cout << "==============================================\n";
    {
        std::shared_ptr<Entity> entity = std::make_shared<Entity>("entity");
        std::thread thread1(myThread, entity), thread2(myThread,entity), thread3(myThread,entity);
        thread1.join();
        thread2.join();
        thread3.join();
        std::cout << "Reference count: " << entity.use_count() << std::endl;
    }
    std::cout << "==============================================\n";
    {
        //b. If you initialize shared_ptr with some other shared_ptr
        std::shared_ptr<Entity> entity_1 = std::make_shared<Entity>("entity_1");
        std::shared_ptr<Entity> entity_2 = std::make_shared<Entity>("entity_2");

        std::cout << "Reference count entity_1: " << entity_1.use_count() << std::endl;
        std::cout << "Reference count entity_2: " << entity_2.use_count() << std::endl;
        entity_1 = entity_2; //Object entity_1 will be destroy.
        std::cout << "Reference count entity_1: " << entity_1.use_count() << std::endl;
        std::cout << "Reference count entity_2: " << entity_2.use_count() << std::endl;
    }

    {
        //   c. If you reset shared_ptr.
        std::shared_ptr<Entity> entity_1 = std::make_shared<Entity>("entity_1");
        std::shared_ptr<Entity> entity_2 = entity_1;

        std::cout << "Reference count entity_1: " << entity_1.use_count() << std::endl;
        entity_2.reset();   //delete linking
        std::cout << "Reference count entity_1: " << entity_1.use_count() << std::endl;
        entity_1.reset();   //delete object
        std::cout << "End scope\n";
    }

    {
        //6. Reference count doesn't work when we use reference or pointer of shared_ptr.
        std::shared_ptr<Entity> entity_1 = std::make_shared<Entity>("entity_1");
        std::shared_ptr<Entity> *entity_2 = &entity_1;
        std::shared_ptr<Entity> &entity_3 = entity_1;
        std::cout << "Reference count entity_1: " << entity_1.use_count() << std::endl;
    }

    std::cout << "End main\n";
    return 0;
}

/*
    Why we should use std::make_shared<>() intead of using constructor of std::shared_ptr()
    Because shared pointer has to allocate another block of memory called the control block where it stores that reference count(số lượng shared pointer)
    and if you creat if you first created a new entity and the pass it into the shared pointer constructor it has to allocate that's two allocation because
    constructing the enitity first and then be shared pointer has the controller cut it has to construct its control block.
    Whereas if you do make share it can actually construct them together which is a lot more efficient.


    Khi số lượng shared pointer trỏ đến 1 vùng memory về 0 thì nó sẽ tự free đi

    📦 Về cơ bản: shared_ptr hoạt động như thế nào?
        shared_ptr giữ một reference count (bộ đếm số người đang sở hữu đối tượng).
        Khi reference count = 0, đối tượng sẽ được delete.
        Mỗi khi có 1 shared_ptr trỏ đến đối tượng, bộ đếm tăng lên.
        Khi shared_ptr bị huỷ hoặc reset, bộ đếm giảm.


    Translate: 
    If you initialize shared_ptr with some other shared_ptr
    Nếu bạn gán (assign) một shared_ptr với shared_ptr khác, mà nó đang trỏ đến một đối tượng cũ, thì đối tượng cũ có thể bị huỷ nếu không còn shared_ptr nào khác trỏ tới.
*/