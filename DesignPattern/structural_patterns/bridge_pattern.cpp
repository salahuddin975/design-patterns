#include <iostream>

// Implementor interface
class Implementor {
public:
    virtual void operationImpl() = 0;
    virtual ~Implementor() {}
};

// Concrete Implementor A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor A operation" << std::endl;
    }
};

// Concrete Implementor B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor B operation" << std::endl;
    }
};

// Abstraction
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}
    virtual void operation() = 0;
    virtual ~Abstraction() {}
};

// Refined Abstraction
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        implementor->operationImpl();
    }
};

int main() {
    Implementor* implA = new ConcreteImplementorA();
    Implementor* implB = new ConcreteImplementorB();

    Abstraction* abstractionA = new RefinedAbstraction(implA);
    Abstraction* abstractionB = new RefinedAbstraction(implB);

    abstractionA->operation();
    abstractionB->operation();

    delete abstractionA;
    delete abstractionB; 
}


/*
Output:

Concrete Implementor A operation
Concrete Implementor B operation
*/

/*
- The Bridge Pattern is a structural design pattern that separates an object's abstraction from its implementation so that the two can vary independently. 
It's particularly useful when you want to avoid a permanent binding between an abstraction and its implementation, allowing them to change and evolve separately. 

- In this example: Implementor is the implementor interface that defines the operation that the abstraction will use.
- ConcreteImplementorA and ConcreteImplementorB are concrete implementors that provide specific implementations of the operation.
- Abstraction is the abstraction class that uses the implementor interface. It contains a pointer to the implementor.
- RefinedAbstraction is a specific refined abstraction class that delegates the operation to the implementor.

- In the main function, we create instances of ConcreteImplementorA and ConcreteImplementorB, then use them to create instances of RefinedAbstraction. 
We call the operation method on each refined abstraction, which in turn calls the appropriate operationImpl method on the respective implementor.

- The Bridge Pattern in C++ allows you to separate the abstraction from its implementation, enabling them to evolve independently and providing 
flexibility for future changes.
*/

