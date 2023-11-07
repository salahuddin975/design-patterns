#include <iostream>
#include <string>

// Product
class Computer {
private:
    std::string cpu_;
    int ram_ = 0;
    std::string storage_;

public:
    void setCPU(const std::string& cpu) {
        cpu_ = cpu;
    }

    void setRAM(int ram) {
        ram_ = ram;
    }

    void setStorage(const std::string& storage) {
        storage_ = storage;
    }

    void showSpecs() {
        std::cout << "CPU: " << cpu_ << ", RAM: " << ram_ << "GB, Storage: " << storage_ << std::endl;
    }
};

// Abstract Builder
class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual Computer getResult() = 0;
};

// Concrete Builder for Gaming Computer
class GamingComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override {
        computer_.setCPU("Intel Core i9");
    }

    void buildRAM() override {
        computer_.setRAM(32);
    }

    void buildStorage() override {
        computer_.setStorage("2TB SSD");
    }

    Computer getResult() override {
        return computer_;
    }

private:
    Computer computer_;
};

// Concrete Builder for Office Computer
class OfficeComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override {
        computer_.setCPU("Intel Core i7");
    }

    void buildRAM() override {
        computer_.setRAM(16);
    }

    void buildStorage() override {
        computer_.setStorage("1TB HDD");
    }

    Computer getResult() override {
        return computer_;
    }

private:
    Computer computer_;
};

// Director
class ComputerDirector {
public:
    void setBuilder(ComputerBuilder* builder) {
        builder_ = builder;
    }

    Computer construct() {
        builder_->buildCPU();
        builder_->buildRAM();
        builder_->buildStorage();
        return builder_->getResult();
    }

private:
    ComputerBuilder* builder_;
};

int main() {
    GamingComputerBuilder gamingBuilder;
    OfficeComputerBuilder officeBuilder;
    ComputerDirector director;

    director.setBuilder(&gamingBuilder);
    Computer gamingComputer = director.construct();
    std::cout << "Gaming Computer Specs:" << std::endl;
    gamingComputer.showSpecs();

    director.setBuilder(&officeBuilder);
    Computer officeComputer = director.construct();
    std::cout << "Office Computer Specs:" << std::endl;
    officeComputer.showSpecs();

    return 0;
}




/*
- The Builder Pattern is a creational design pattern that allows you to construct complex objects step by step. It separates the construction 
of a complex object from its representation, allowing you to create different representations of an object by using the same construction process. 
This pattern is useful when you need to create objects with many optional components or configurations.

- In this example: Computer is the product class that you want to build.

- ComputerBuilder is an abstract builder class with methods for building various components of the Computer.

- GamingComputerBuilder and OfficeComputerBuilder are concrete builder classes that inherit from ComputerBuilder. They implement 
the methods to build components with specific configurations for gaming and office computers.

- ComputerDirector is responsible for directing the construction process using a specific builder.

- In the main function, we create instances of the GamingComputerBuilder and OfficeComputerBuilder, and then use the ComputerDirector 
to construct gaming and office computers with different configurations. The builder pattern allows you to create complex objects while keeping 
the construction process and product separate, making it easy to create different variants of a product.
*/
