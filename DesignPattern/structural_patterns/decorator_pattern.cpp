
#include <iostream>

// Base interface
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() {}
};

// Concrete component
class ConcreteComponent : public Component {
public:
    void operation() override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

// Decorator base class
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* comp) : component(comp) {}
    void operation() override {
        if (component) {
            component->operation();
        }
    }
};

// Concrete decorators
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

    void addedBehavior() {
        std::cout << "Additional behavior added by ConcreteDecoratorA" << std::endl;
    }

    void operation() override {
        Decorator::operation();
        addedBehavior();
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}

    void addedBehavior() {
        std::cout << "Additional behavior added by ConcreteDecoratorB" << std::endl;
    }

    void operation() override {
        Decorator::operation();
        addedBehavior();
    }
};

int main() {
    Component* component = new ConcreteComponent();
    component->operation();

    Component* decoratorA = new ConcreteDecoratorA(component);
    decoratorA->operation();

    Component* decoratorB = new ConcreteDecoratorB(decoratorA);
    decoratorB->operation();

    delete component;
    delete decoratorA;
    delete decoratorB;

    return 0;
}


/*
Output:

ConcreteComponent operation
ConcreteComponent operation
Additional behavior added by ConcreteDecoratorA
ConcreteComponent operation
Additional behavior added by ConcreteDecoratorA
Additional behavior added by ConcreteDecoratorB
*/

/*
- The Decorator Pattern is a structural design pattern that allows you to add behavior to individual objects, either statically or dynamically, 
without affecting the behavior of other objects from the same class. In C++, you can implement the Decorator Pattern by creating a series of 
decorator classes that wrap the base class and add or modify its behavior.

- In this example: Component is the base interface that defines the common operation.
- ConcreteComponent is the concrete implementation of the base component.
- Decorator is the base decorator class that also implements the Component interface. It contains a pointer to the wrapped Component.
- ConcreteDecoratorA and ConcreteDecoratorB are the concrete decorator classes that add additional behavior to the component. They override the 
operation method and call the wrapped component's operation method while adding their specific behavior.

- In the main function, we create a chain of decorators. The ConcreteComponent is wrapped by ConcreteDecoratorA, which is further wrapped by 
ConcreteDecoratorB. When we call the operation method on the final decorator, it invokes the operation of the wrapped component and adds the specific behavior.

- The Decorator Pattern allows you to extend the behavior of objects dynamically, making it a flexible way to add functionality to classes without modifying their code.
*/