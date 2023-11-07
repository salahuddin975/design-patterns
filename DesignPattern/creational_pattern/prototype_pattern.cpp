#include <iostream>
#include <string>

class Prototype {
public:
    virtual Prototype* clone() const = 0;

    virtual void setInfo(const std::string& info) {
        info_ = info;
    }

    virtual std::string getInfo() const {
        return info_;
    }

protected:
    std::string info_;
};

class ConcretePrototype : public Prototype {
public:
    Prototype* clone() const override {
        ConcretePrototype* newPrototype = new ConcretePrototype();
        newPrototype->setInfo(this->getInfo());
        return newPrototype;
    }
};

int main() {
    ConcretePrototype original;
    original.setInfo("This is the original object.");

    ConcretePrototype* cloned1 = dynamic_cast<ConcretePrototype*>(original.clone());
    cloned1->setInfo("This is the first cloned object.");

    ConcretePrototype* cloned2 = dynamic_cast<ConcretePrototype*>(original.clone());
    cloned2->setInfo("This is the second cloned object.");

    std::cout << "Original: " << original.getInfo() << std::endl;
    std::cout << "Cloned 1: " << cloned1->getInfo() << std::endl;
    std::cout << "Cloned 2: " << cloned2->getInfo() << std::endl;

    delete cloned1;
    delete cloned2;

    return 0;
}



/*
- The Prototype Pattern is a creational design pattern that allows you to create new objects by copying an existing object, known as the prototype. 
This pattern is useful when you want to create new objects with the same initial state as an existing object, saving the cost of initializing the new object from scratch.

- In this example: Prototype is the base class for the prototype objects. It defines a clone method, which will be implemented by concrete prototypes. 
The setInfo and getInfo methods allow you to set and retrieve the object's information.

- ConcretePrototype is a concrete class that inherits from Prototype. It implements the clone method, making a deep copy of the object, and also allows 
setting and getting the object's information.

- In the main function, we create an original object and then create two clones from it. Each clone is created by calling the clone method on the 
original object. We then modify the information for each object to demonstrate that they are distinct.

- After using the cloned objects, remember to delete them to free the allocated memory.

- The Prototype Pattern is useful when you want to create new objects that are similar to existing ones. It allows you to create objects with the same 
initial state without the need to reinitialize them.
*/