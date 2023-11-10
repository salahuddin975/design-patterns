#include <iostream>

// Context
class Context;

// State interface
class State {
public:
    virtual void handle(Context& context) = 0;
};

// Concrete State A
class ConcreteStateA : public State {
public:
    void handle(Context& context) override;
};

// Concrete State B
class ConcreteStateB : public State {
public:
    void handle(Context& context) override;
};

// Context
class Context {
private:
    State* currentState;

public:
    Context() : currentState(nullptr) {}

    void setState(State* state) {
        currentState = state;
    }

    void request() {
        currentState->handle(*this);
    }
};

// Concrete State A implementation
void ConcreteStateA::handle(Context& context) {
    std::cout << "ConcreteStateA is handling the request." << std::endl;
    // Optionally, change the state
    context.setState(new ConcreteStateB());
}

// Concrete State B implementation
void ConcreteStateB::handle(Context& context) {
    std::cout << "ConcreteStateB is handling the request." << std::endl;
    // Optionally, change the state
    context.setState(new ConcreteStateA());
}

int main() {
    Context context;

    context.setState(new ConcreteStateA());
    context.request();

    context.request();

    return 0;
}


/*
Output:

ConcreteStateA is handling the request.
ConcreteStateB is handling the request.
*/

/*
- The State Pattern is a behavioral design pattern that allows an object to alter its behavior when its internal state changes. The object will appear to change its class. 

- In this example: State is the state interface that declares the handle method.
- ConcreteStateA and ConcreteStateB are concrete state classes that implement the State interface. Each state class handles the request and may optionally 
transition the context to a different state.
- Context is the context class that contains a state. It delegates the handling of requests to the current state.

- In the main function, we create an instance of Context and set its initial state to ConcreteStateA. We then make a request, which is handled by the 
current state (ConcreteStateA). After the request is handled, the state may optionally change. In this example, after the first request, the state changes 
to ConcreteStateB, and the second request is handled by the new state.
*/