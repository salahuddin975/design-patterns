from abc import ABC, abstractmethod

# Abstract Product
class Product(ABC):
    @abstractmethod
    def create(self):
        pass

# Concrete Products
class ConcreteProductA(Product):
    def create(self):
        print("Creating Product A")

class ConcreteProductB(Product):
    def create(self):
        print("Creating Product B")

# Abstract Factory
class Factory(ABC):
    @abstractmethod
    def create_product(self) -> Product:
        pass

# Concrete Factories
class FactoryA(Factory):
    def create_product(self) -> Product:
        return ConcreteProductA()

class FactoryB(Factory):
    def create_product(self) -> Product:
        return ConcreteProductB()

def client_code(factory: Factory):
    product = factory.create_product()
    product.create()

if __name__ == "__main__":
    factory_a = FactoryA()
    factory_b = FactoryB()

    client_code(factory_a)
    client_code(factory_b)


'''
In this Python example:

- Product is an abstract base class (ABC) representing the interface for products. It has an abstract method create() that 
must be implemented by concrete products.

- ConcreteProductA and ConcreteProductB are concrete classes that inherit from Product and provide specific implementations of the create() method.

- Factory is an abstract base class (ABC) representing the interface for factories. It declares an abstract method create_product() to create products.

- FactoryA and FactoryB are concrete factory classes that inherit from Factory. They implement the create_product() method to create specific products.

- The client_code function demonstrates how to create and use products via the factory. You pass a factory object as an argument, and 
it creates a product and calls its create() method.

- In the main section, we create instances of FactoryA and FactoryB, then use the client_code function to create and use products from both factories.

- This pattern allows you to create new types of products and factories by adding new classes that conform to the abstract interfaces 
without changing the existing client code.
'''