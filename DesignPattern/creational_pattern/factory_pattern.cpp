#include <iostream>

// Abstract Product
class Product {
public:
    virtual void create() = 0;
};

// Concrete Product A
class ConcreteProductA : public Product {
public:
    void create() override {
        std::cout << "Creating Product A" << std::endl;
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void create() override {
        std::cout << "Creating Product B" << std::endl;
    }
};

// Abstract Factory
class Factory {
public:
    virtual Product* createProduct() = 0;
};

// Concrete Factory for Product A
class FactoryA : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

// Concrete Factory for Product B
class FactoryB : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};

int main() {
    Factory* factoryA = new FactoryA();
    Product* productA = factoryA->createProduct();
    productA->create();

    Factory* factoryB = new FactoryB();
    Product* productB = factoryB->createProduct();
    productB->create();

    delete factoryA;
    delete productA;
    delete factoryB;
    delete productB;

    return 0;
}



/*
- The Factory Method Pattern in C++ is a creational design pattern that defines an interface
 for creating objects but allows subclasses to alter the type of objects that will be created. 
 It abstracts the process of object creation and provides a way to create objects without 
 specifying their exact class. 
- In this example: Product is an abstract class representing the interface for products. It has a 
virtual create() method that must be implemented by concrete products.
- ConcreteProductA and ConcreteProductB are concrete classes that inherit from Product and provide 
specific implementations of the create() method.
- Factory is an abstract class representing the interface for factories. It declares a pure virtual 
function createProduct() to create products.
- FactoryA and FactoryB are concrete factory classes that inherit from Factory. They implement of 
the createProduct() method to create specific products.
- In the main function, you create instances of the factories (FactoryA and FactoryB) and use them 
to create products (ConcreteProductA and ConcreteProductB).
- This pattern allows you to create new types of products and factories by simply adding new classes
 that conform to the abstract interfaces, without changing the existing client code.
*/