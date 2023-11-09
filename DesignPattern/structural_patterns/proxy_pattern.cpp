#include <iostream>

// Subject interface
class Subject {
public:
    virtual void request() = 0;
    virtual ~Subject() {}
};

// Real subject
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject handles the request." << std::endl;
    }
};

// Proxy
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    Proxy() : realSubject(nullptr) {}

    void request() override {
        if (!realSubject) {
            realSubject = new RealSubject();
        }
        realSubject->request();
    }

    ~Proxy() {
        if (realSubject) {
            delete realSubject;
        }
    }
};

int main() {
    Proxy proxy;

    proxy.request();

    return 0;
}

/*
Output: 

RealSubject handles the request.
*/

/*
- The Proxy Pattern is a structural design pattern that provides a surrogate or placeholder for another object to control access to it. 
It can be used for various purposes, such as controlling access, logging, or lazy initialization. In C++, you can implement the Proxy Pattern 
to provide a controlled interface to an object. 

- In this example: Subject is the interface that defines the common operation, which is request.

- RealSubject is the concrete implementation of the subject interface. It represents the real object that the proxy will control access to.

- Proxy is the proxy class. It also implements the Subject interface. The proxy, in this case, lazily instantiates the RealSubject when the request method is called.

- In the main function, we create an instance of the Proxy class and call its request method. The proxy, in turn, creates and delegates the request to the RealSubject.

- The Proxy Pattern can be useful in scenarios where you want to control access to an object, perform lazy loading, add logging, or provide additional 
functionalities without modifying the real subject's code.
*/
