# Implementor interface
class Implementor:
    def operation_impl(self):
        pass

# Concrete Implementor A
class ConcreteImplementorA(Implementor):
    def operation_impl(self):
        print("Concrete Implementor A operation")

# Concrete Implementor B
class ConcreteImplementorB(Implementor):
    def operation_impl(self):
        print("Concrete Implementor B operation")

# Abstraction
class Abstraction:
    def __init__(self, implementor):
        self.implementor = implementor

    def operation(self):
        self.implementor.operation_impl()

# Refined Abstraction
class RefinedAbstraction(Abstraction):
    def operation(self):
        super().operation()

def main():
    implA = ConcreteImplementorA()
    implB = ConcreteImplementorB()

    abstractionA = RefinedAbstraction(implA)
    abstractionB = RefinedAbstraction(implB)

    abstractionA.operation()
    abstractionB.operation()

if __name__ == "__main__":
    main()



'''
Output:

Concrete Implementor A operation
Concrete Implementor B operation
'''

'''
- The Bridge Pattern is a structural design pattern that separates an object's abstraction from its implementation so that they can vary independently. 
In Python, this pattern is relatively simple to implement due to the language's dynamic nature. 

- In this Python example: Implementor is the implementor interface that defines the operation that the abstraction will use.
- ConcreteImplementorA and ConcreteImplementorB are concrete implementors that provide specific implementations of the operation.
- Abstraction is the abstraction class that uses the implementor interface. It contains a reference to the implementor.
- RefinedAbstraction is a specific refined abstraction class that delegates the operation to the implementor.

- In the main function, we create instances of ConcreteImplementorA and ConcreteImplementorB, then use them to create instances of RefinedAbstraction. 
We call the operation method on each refined abstraction, which in turn calls the appropriate operation_impl method on the respective implementor.

- The Bridge Pattern in Python allows you to separate the abstraction from its implementation, enabling them to vary independently and providing 
flexibility for future changes.
'''