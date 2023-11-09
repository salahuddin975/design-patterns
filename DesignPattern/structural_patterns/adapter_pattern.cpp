#include <iostream>

// Existing class with an incompatible interface
class LegacyComponent {
public:
    void legacyOperation() {
        std::cout << "LegacyComponent is performing its legacy operation." << std::endl;
    }
};

// New interface that the client code expects
class NewInterface {
public:
    virtual void newOperation() = 0;
    virtual ~NewInterface() {}
};

// Adapter that adapts the existing class to the new interface
class Adapter : public NewInterface {
private:
    LegacyComponent legacyComponent;

public:
    void newOperation() override {
        legacyComponent.legacyOperation();
    }
};

int main() {
    NewInterface* adapter = new Adapter;

    // The client code can work with the new interface
    adapter->newOperation();

    delete adapter;

    return 0;
}



/*
- The Adapter Pattern is a structural design pattern that allows objects with incompatible interfaces to work together. It involves creating 
a wrapper (the adapter) that converts one interface into another. The adapter pattern can be implemented in C++ to make existing classes work 
with others without modifying their source code.

- In this example: LegacyComponent is an existing class with an incompatible interface, and it has a method legacyOperation.

- NewInterface is the new interface that the client code expects, and it has a method newOperation.

- Adapter is the adapter class that derives from the NewInterface and contains an instance of LegacyComponent. It adapts the LegacyComponent 
to work with the NewInterface.

- In the main function, we create an instance of the Adapter and use it to perform the newOperation. The adapter, in turn, invokes the 
legacyOperation of the LegacyComponent.

- The Adapter Pattern allows you to use existing classes with different interfaces in your code without modifying the original classes. This can be 
especially useful when working with libraries or legacy code.
*/