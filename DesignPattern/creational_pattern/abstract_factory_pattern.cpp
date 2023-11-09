#include <iostream>

// Abstract products
class AbstractProductA {
public:
    virtual void use() = 0;
};

class AbstractProductB {
public:
    virtual void consume() = 0;
};

// Concrete products for Product Family 1
class ConcreteProductA1 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using Product A1" << std::endl;
    }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void consume() override {
        std::cout << "Consuming Product B1" << std::endl;
    }
};

// Concrete products for Product Family 2
class ConcreteProductA2 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using Product A2" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void consume() override {
        std::cout << "Consuming Product B2" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// Concrete factories for Product Family 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// Concrete factories for Product Family 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();

    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();

    productA1->use();
    productB1->consume();

    productA2->use();
    productB2->consume();

    delete factory1;
    delete productA1;
    delete productB1;

    delete factory2;
    delete productA2;
    delete productB2;

    return 0;
}


/*
Output:

Using Product A1
Consuming Product B1
Using Product A2
Consuming Product B2
*/


/*
- The Abstract Factory Pattern in C++ is a creational design pattern that provides an interface for creating families of related or 
dependent objects without specifying their concrete classes. It is often used when you need to ensure that the created objects are 
compatible with each other and when you want to hide the details of object creation.

- In this example: AbstractProductA and AbstractProductB are abstract classes representing the interface for product families. 
Concrete products are derived from these abstract classes.
- ConcreteProductA1, ConcreteProductB1, ConcreteProductA2, and ConcreteProductB2 are concrete product classes for two different product families.
- AbstractFactory is an abstract class defining the interface for creating products. It declares abstract methods for creating AbstractProductA and AbstractProductB.
- ConcreteFactory1 and ConcreteFactory2 are concrete factory classes for two different product families. They implement the AbstractFactory 
interface to create products from their respective families.

- In the main function, we create instances of ConcreteFactory1 and ConcreteFactory2, and use these factories to create products. 
This demonstrates how you can create products from different families using the same interface, achieving separation of product creation and product use.

- This pattern is useful when you need to ensure that the products are compatible within the same family and when you want to 
abstract the creation process to select different product families without changing the client code.
*/

