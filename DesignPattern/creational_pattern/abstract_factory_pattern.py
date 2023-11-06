from abc import ABC, abstractmethod

# Abstract Product A
class AbstractProductA(ABC):
    @abstractmethod
    def operation_A(self):
        pass

# Concrete Product A1
class ConcreteProductA1(AbstractProductA):
    def operation_A(self):
        return "Product A1 operation"

# Concrete Product A2
class ConcreteProductA2(AbstractProductA):
    def operation_A(self):
        return "Product A2 operation"

# Abstract Product B
class AbstractProductB(ABC):
    @abstractmethod
    def operation_B(self):
        pass

# Concrete Product B1
class ConcreteProductB1(AbstractProductB):
    def operation_B(self):
        return "Product B1 operation"

# Concrete Product B2
class ConcreteProductB2(AbstractProductB):
    def operation_B(self):
        return "Product B2 operation"

# Abstract Factory
class AbstractFactory(ABC):
    @abstractmethod
    def create_product_A(self) -> AbstractProductA:
        pass

    @abstractmethod
    def create_product_B(self) -> AbstractProductB:
        pass

# Concrete Factory 1
class ConcreteFactory1(AbstractFactory):
    def create_product_A(self) -> AbstractProductA:
        return ConcreteProductA1()

    def create_product_B(self) -> AbstractProductB:
        return ConcreteProductB1()

# Concrete Factory 2
class ConcreteFactory2(AbstractFactory):
    def create_product_A(self) -> AbstractProductA:
        return ConcreteProductA2()

    def create_product_B(self) -> AbstractProductB:
        return ConcreteProductB2()

def client_code(factory: AbstractFactory):
    product_A = factory.create_product_A()
    product_B = factory.create_product_B()

    print(product_A.operation_A())
    print(product_B.operation_B())

if __name__ == "__main__":
    factory1 = ConcreteFactory1()
    client_code(factory1)

    factory2 = ConcreteFactory2()
    client_code(factory2)


'''
- The Abstract Factory Pattern in Python is a creational design pattern that provides an interface for creating families of related or dependent 
objects without specifying their concrete classes. It allows you to create instances of multiple classes that belong to the same family of objects.

- In this example: AbstractProductA and AbstractProductB are abstract classes representing the interface for product families. 
Concrete products are derived from these abstract classes.

- ConcreteProductA1, ConcreteProductA2, ConcreteProductB1, and ConcreteProductB2 are concrete product classes for two different product families.

- AbstractFactory is an abstract class defining the interface for creating products. It declares abstract methods for creating AbstractProductA and AbstractProductB.

- ConcreteFactory1 and ConcreteFactory2 are concrete factory classes for two different product families. They implement the AbstractFactory 
interface to create products from their respective families.

- The client_code function demonstrates how to create products from different families using the same interface. We create instances of 
ConcreteFactory1 and ConcreteFactory2, and use them to create and operate on products from the respective families.

- This pattern is useful when you need to ensure that the products are compatible within the same family and when you want to abstract the creation 
process to select different product families without changing the client code.
'''

