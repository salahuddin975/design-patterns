from abc import ABC, abstractmethod

# Context
class Context:
    def __init__(self):
        self.state = None

    def set_state(self, state):
        self.state = state

    def request(self):
        self.state.handle(self)


# State interface
class State(ABC):
    @abstractmethod
    def handle(self, context):
        pass


# Concrete State A
class ConcreteStateA(State):
    def handle(self, context):
        print("ConcreteStateA is handling the request.")
        # Optionally, change the state
        context.set_state(ConcreteStateB())


# Concrete State B
class ConcreteStateB(State):
    def handle(self, context):
        print("ConcreteStateB is handling the request.")
        # Optionally, change the state
        context.set_state(ConcreteStateA())


def main():
    context = Context()

    context.set_state(ConcreteStateA())
    context.request()

    context.request()


if __name__ == "__main__":
    main()


'''
Output:

ConcreteStateA is handling the request.
ConcreteStateB is handling the request.
'''

'''
- The State Pattern is a behavioral design pattern that allows an object to alter its behavior when its internal state changes. The object will appear to change its class. 

- In this example: State is the state interface that declares the handle method.
- ConcreteStateA and ConcreteStateB are concrete state classes that inherit from State. Each state class implements the handle method, and it may 
optionally change the state of the context.
- Context is the context class that contains a state. It has a method to set the current state and a method to make requests. The requests are 
delegated to the current state.

- In the main function, we create an instance of Context and set its initial state to ConcreteStateA. We then make a request, which is handled by the 
current state (ConcreteStateA). After the request is handled, the state may optionally change. In this example, after the first request, the state changes 
to ConcreteStateB, and the second request is handled by the new state.
'''