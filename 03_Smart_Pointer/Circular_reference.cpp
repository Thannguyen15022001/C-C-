#include <iostream>
#include <memory>
#include <string>

struct B;

struct A
{
    std::shared_ptr<B> sharedPointer_B;
};


struct B
{
    std::shared_ptr<A> sharedPointer_A;
};

struct D;
struct C
{
    std::shared_ptr<D> sharedPointer_D;
};

struct D
{
    std::weak_ptr<C> sharedPointer_C;
};


void circularReference(){
    std::cout << "Circular reference\n";
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    std::cout << a.use_count() << std::endl;
    std::cout << b.use_count() << std::endl;

    a->sharedPointer_B = b;
    b->sharedPointer_A = a;

    std::cout << a.use_count() << std::endl;
    std::cout << b.use_count() << std::endl;
}

void noneCircularReference(){
    std::cout << "None Circular Reference\n";
    std::shared_ptr<C> c = std::make_shared<C>();
    std::shared_ptr<D> d = std::make_shared<D>();

    std::cout << c.use_count() << std::endl;
    std::cout << d.use_count() << std::endl;

    c->sharedPointer_D = d;
    d->sharedPointer_C = c;

    std::cout << c.use_count() << std::endl;
    std::cout << d.use_count() << std::endl;
}

int main(){

    

    //memory leek
    //a->sharedPointer_B=b;
    //b->sharedPointer_A=a;

    //circularReference();
    noneCircularReference();
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


    Circular_reference
        Stack
        +------------------------+
    ┌───| shared_ptr<A> a        |
    |   | shared_ptr<B> b        |──┐
    |   +------------------------+  │
    |                               |
    |                               |
    |    Heap:                      |
    |   ┌──────────────┐     ┌──────────────┐
    └───│    Object A  │     │    Object B  │
        │──────────────│     │──────────────│
        │ shared_ptr<B>│────▶│     b        │
        └──────────────┘     │ shared_ptr<A>│
                 ▲           └──────────────┘
                 │                   │
                 └───────────────────┘
*/