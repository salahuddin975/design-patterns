#include <iostream>
#include <vector>

// Component interface
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() {}
};

// Leaf class
class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Composite class
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void operation() override {
        std::cout << "Composite operation" << std::endl;
        for (Component* child : children) {
            child->operation();
        }
    }
};

int main() {
    Leaf leaf1, leaf2;
    Composite composite;
    composite.add(&leaf1);
    composite.add(&leaf2);

    composite.operation();

    return 0;
}


/*
Output:

Composite operation
Leaf operation
Leaf operation
*/

/*
- The Composite Pattern is a structural design pattern that allows you to compose objects into tree structures to represent part-whole hierarchies. 
In this pattern, individual objects and compositions of objects are treated uniformly. It's commonly used in situations where you need to work with objects 
that form a hierarchical structure. 

- In this example: Component is the base interface that defines the common operation, which is operation.
- Leaf is a leaf class that represents individual objects.
- Composite is a composite class that can contain other components, including both leaves and other composites. It can have one or more children.
- The add method in the Composite class allows adding child components.
- The operation method of the Composite class iterates through its children and invokes their operation methods. The Composite can represent a tree 
structure where each node can be either a Leaf or another Composite.

- In the main function, we create instances of Leaf and Composite, add the leaves to the composite, and call the operation method on the composite. 
The composite, in turn, calls operation on all of its children.

- The Composite Pattern in C++ allows you to treat individual objects and compositions of objects uniformly, simplifying the manipulation of complex hierarchical structures.

*/