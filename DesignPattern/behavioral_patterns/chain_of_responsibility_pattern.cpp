#include <iostream>
#include <string>

// Handler interface
class Handler {
public:
    virtual void handleRequest(const std::string& request) = 0;
    virtual ~Handler() {}
};

// Concrete Handler
class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "ConcreteHandlerA handling request A" << std::endl;
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }

    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

private:
    Handler* nextHandler = nullptr;
};

// Another Concrete Handler
class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "ConcreteHandlerB handling request B" << std::endl;
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }

    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

private:
    Handler* nextHandler = nullptr;
};

int main() {
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;

    handlerA.setNextHandler(&handlerB);

    handlerA.handleRequest("A");
    handlerA.handleRequest("B");
    handlerA.handleRequest("C");

    return 0;
}

/*
Output:

ConcreteHandlerA handling request A
ConcreteHandlerB handling request B
*/

/*
- The Chain of Responsibility Pattern is a behavioral design pattern that allows an object to pass a request along a chain of potential handlers. 
Upon receiving a request, each handler decides either to process the request or to pass it along to the next handler in the chain. 

- In this example: Handler is the handler interface that declares the handleRequest method.
- ConcreteHandlerA and ConcreteHandlerB are concrete handler classes that inherit from Handler. Each handler checks if it can handle the request; 
if not, it passes the request to the next handler in the chain.

- In the main function, we create instances of ConcreteHandlerA and ConcreteHandlerB. We set ConcreteHandlerB as the next handler for ConcreteHandlerA. 
We then make several requests, and each handler processes the request or passes it along the chain if it cannot handle it.

- This example demonstrates the basic structure of the Chain of Responsibility Pattern in C++, where each handler decides whether to handle a request 
or pass it to the next handler in the chain.
*/
