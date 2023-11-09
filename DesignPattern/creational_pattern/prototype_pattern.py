import copy

class Prototype:
    def clone(self):
        return copy.deepcopy(self)

    def set_info(self, info):
        self.info = info

    def get_info(self):
        return self.info

class ConcretePrototype(Prototype):
    def __init__(self):
        self.info = "Default information"

if __name__ == "__main__":
    original = ConcretePrototype()
    original.set_info("This is the original object.")

    cloned1 = original.clone()
    cloned1.set_info("This is the first cloned object.")

    cloned2 = original.clone()
    cloned2.set_info("This is the second cloned object.")

    print("Original:", original.get_info())
    print("Cloned 1:", cloned1.get_info())
    print("Cloned 2:", cloned2.get_info())



'''
Output:

Original: This is the original object.
Cloned 1: This is the first cloned object.
Cloned 2: This is the second cloned object.
'''


'''
- The Prototype Pattern in Python allows you to create new objects by copying an existing object, known as the prototype. This pattern is useful when you 
want to create new objects with the same initial state as an existing object, saving the cost of initializing the new object from scratch.

- In this example: Prototype is the base class for the prototype objects. It defines a clone method, which creates a deep copy of the object. The set_info and 
get_info methods allow you to set and retrieve the object's information.
- ConcretePrototype is a concrete class that inherits from Prototype. It sets a default value for the info attribute.

- In the main section, we create an original object and then create two clones from it. Each clone is created by calling the clone method on the original object. 
We then modify the information for each object to demonstrate that they are distinct.

- The Prototype Pattern is useful when you want to create new objects that are similar to existing ones. It allows you to create objects with the same initial 
state without the need to reinitialize them. In Python, the copy module is used to create deep copies of objects, ensuring that  the cloned objects are 
distinct from the original.
'''