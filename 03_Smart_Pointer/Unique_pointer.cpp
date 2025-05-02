#include <iostream>
#include <string>
#include <memory>

class Entity{
    int val;
public:
    Entity(int value): val(value){
        std::cout << "Entity Constructor\n";
    }

    ~Entity(){
        std::cout << "Entity Destructor\n";
    }

    void print(std::string text){
        std::cout << text <<std::endl;
    }

};

std::unique_ptr<Entity> func(){
    std::unique_ptr<Entity> entity = std::make_unique<Entity>(10);
    entity->print("Hello");

    return entity; //move 
}


int main(){

    {
        //std::unique_ptr<Entity> entity(new Entity());       // Khai báo sử dụng constructor của unique_ptr - ít được sử dụng vì khi có exception xảy ra thì con trỏ được tạo ra sẽ ko có tham chiếu => memory leet
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(10);  //Nên sử dụng đảm bảo con trỏ ko bị lơ lửng khi có exception xảy ra from c++14
        entity->print("Hello");
        std::unique_ptr<Entity> entity_1 = std::move(entity);  
        entity_1->print("Hello");
    }


    {
        std::unique_ptr<Entity> entity =  func();
        entity->print("My name is Entity");
    }
    std::cout << "End main\n";
    return 0;
}

/*
    std::unique_ptr<Entity> entity = new Entity()       => Copy constructor và đang gán con trỏ kiểu *Entity cho con trỏ std::unique_ptr<Entity> và contructor của unique_ptr là explicit ko có kiểu chuyển đổi ngầm định nào
    Reason in memory library
    unique_ptr(const unique_ptr&)            = delete;  Can't use copy constructor

    std::unique_ptr<Entity> entity_0(new Entity());
    std::unique_ptr<Entity> entity_1(new Entity());
    entity_0 = entity_1;                                => Operator = overload 
    unique_ptr& operator=(const unique_ptr&) = delete;  Can't use operator = for another variable

    Note: 
    Không thể có 2 unique pointer cùng trỏ vào 1 vùng (bị chặn ở trên) vì khi 1 con trỏ unique out of scope nó sẽ free đi vùng đó
    và con trỏ unique còn lại vẫn sẽ trỏ vào vùng đã bị xóa đó => lỗi
*/