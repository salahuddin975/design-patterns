from abc import ABC, abstractmethod

# Handler interface
class Handler(ABC):
    @abstractmethod
    def handle_request(self, request):
        pass

# Concrete Handler A
class ConcreteHandlerA(Handler):
    def __init__(self, successor=None):
        self.successor = successor

    def handle_request(self, request):
        if request == "A":
            print("ConcreteHandlerA handling request A")
        elif self.successor:
            self.successor.handle_request(request)

# Concrete Handler B
class ConcreteHandlerB(Handler):
    def __init__(self, successor=None):
        self.successor = successor

    def handle_request(self, request):
        if request == "B":
            print("ConcreteHandlerB handling request B")
        elif self.successor:
            self.successor.handle_request(request)

def main():
    handlerA = ConcreteHandlerA()
    handlerB = ConcreteHandlerB()

    # Set the successor for ConcreteHandlerA
    handlerA.successor = handlerB

    # Send requests
    handlerA.handle_request("A")
    handlerA.handle_request("B")
    handlerA.handle_request("C")

if __name__ == "__main__":
    main()


'''
Output:

ConcreteHandlerA handling request A
ConcreteHandlerB handling request B
'''

'''
- The Chain of Responsibility Pattern is a behavioral design pattern that allows an object to pass a request along a chain of potential handlers. 
Upon receiving a request, each handler decides either to process the request or to pass it along to the next handler in the chain. 

- In this Python example: Handler is an abstract base class that declares the handle_request method.
- ConcreteHandlerA and ConcreteHandlerB are concrete handler classes that inherit from Handler. They implement the handle_request method and have a successor
 attribute to store the next handler in the chain.

- In the main function, we create instances of ConcreteHandlerA and ConcreteHandlerB. We set ConcreteHandlerB as the successor for ConcreteHandlerA. We then 
send requests to ConcreteHandlerA, and each handler processes the request or passes it to the next handler in the chain.

- This example demonstrates the basic structure of the Chain of Responsibility pattern in Python, where each handler in the chain decides whether to handle 
a request or pass it to the next handler.
'''
