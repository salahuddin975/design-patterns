# Component interface
class Component:
    def operation(self):
        pass

# Leaf class
class Leaf(Component):
    def operation(self):
        print("Leaf operation")

# Composite class
class Composite(Component):
    def __init__(self):
        self.children = []

    def add(self, component):
        self.children.append(component)

    def operation(self):
        print("Composite operation")
        for child in self.children:
            child.operation()

if __name__ == "__main__":
    leaf1 = Leaf()
    leaf2 = Leaf()
    composite = Composite()
    composite.add(leaf1)
    composite.add(leaf2)

    composite.operation()



'''
Output:

Composite operation
Leaf operation
Leaf operation
'''

'''
- The Composite Pattern is a structural design pattern that allows you to compose objects into tree structures to represent part-whole hierarchies. 
In this pattern, individual objects and compositions of objects are treated uniformly. It's commonly used in situations where you need to work with 
objects that form a hierarchical structure. 

- In this Python example: Component is the base interface that defines the common operation, which is operation.

- Leaf is a leaf class that represents individual objects.

- Composite is a composite class that can contain other components, including both leaves and other composites. It can have one or more children.

- The add method in the Composite class allows adding child components.

- The operation method of the Composite class iterates through its children and invokes their operation methods. The Composite can represent a tree 
structure where each node can be either a Leaf or another Composite.

- In the main part of the code, we create instances of Leaf and Composite, add the leaves to the composite, and call the operation method on the composite. 
The composite, in turn, calls operation on all of its children.

- The Composite Pattern in Python allows you to treat individual objects and compositions of objects uniformly, simplifying the manipulation of complex 
hierarchical structures.

'''