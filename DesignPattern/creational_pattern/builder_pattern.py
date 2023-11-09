class Computer:
    def __init__(self, cpu, ram, storage):
        self.cpu = cpu
        self.ram = ram
        self.storage = storage

    def __str__(self):
        return f"CPU: {self.cpu}, RAM: {self.ram}GB, Storage: {self.storage}"

class ComputerBuilder:
    def __init__(self):
        self.cpu = None
        self.ram = None
        self.storage = None

    def set_cpu(self, cpu):
        self.cpu = cpu
        return self

    def set_ram(self, ram):
        self.ram = ram
        return self

    def set_storage(self, storage):
        self.storage = storage
        return self

    def build(self):
        return Computer(self.cpu, self.ram, self.storage)

# Director
class ComputerDirector:
    def construct_gaming_computer(self):
        return ComputerBuilder() \
            .set_cpu("Intel Core i9") \
            .set_ram(32) \
            .set_storage("2TB SSD") \
            .build()

    def construct_office_computer(self):
        return ComputerBuilder() \
            .set_cpu("Intel Core i7") \
            .set_ram(16) \
            .set_storage("1TB HDD") \
            .build()

if __name__ == "__main__":
    director = ComputerDirector()

    gaming_computer = director.construct_gaming_computer()
    print("Gaming Computer Specs:")
    print(gaming_computer)

    office_computer = director.construct_office_computer()
    print("Office Computer Specs:")
    print(office_computer)



'''
Output:

Gaming Computer Specs:
CPU: Intel Core i9, RAM: 32GB, Storage: 2TB SSD
Office Computer Specs:
CPU: Intel Core i7, RAM: 16GB, Storage: 1TB HDD
'''

'''
- The Builder Pattern in Python is a creational design pattern that allows you to construct complex objects step by step. It separates 
the construction of a complex object from its representation, enabling the creation of different representations of an object by using 
the same construction process. This pattern is useful when you need to create objects with many optional components or configurations.

- In this example: Computer is the product class that you want to build.
- ComputerBuilder is the builder class with methods for setting different components of the computer. Each method returns self, allowing for method chaining.
- The ComputerDirector is responsible for directing the construction process using specific builder methods to build gaming and office computers.

- In the main section, we create an instance of the ComputerDirector and use it to construct gaming and office computers with different configurations. 
The builder pattern allows you to create complex objects while keeping the construction process and product separate, making it easy to create different variants of a product.
'''