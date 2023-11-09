# Base interface
class Component:
    def operation(self):
        pass

# Concrete component
class ConcreteComponent(Component):
    def operation(self):
        print("ConcreteComponent operation")

# Decorator base class
class Decorator(Component):
    def __init__(self, component):
        self.component = component

    def operation(self):
        if self.component:
            self.component.operation()

# Concrete decorators
class ConcreteDecoratorA(Decorator):
    def added_behavior(self):
        print("Additional behavior added by ConcreteDecoratorA")

    def operation(self):
        super().operation()
        self.added_behavior()

class ConcreteDecoratorB(Decorator):
    def added_behavior(self):
        print("Additional behavior added by ConcreteDecoratorB")

    def operation(self):
        super().operation()
        self.added_behavior()

def main():
    component = ConcreteComponent()
    component.operation()

    decorator_a = ConcreteDecoratorA(component)
    decorator_a.operation()

    decorator_b = ConcreteDecoratorB(decorator_a)
    decorator_b.operation()

if __name__ == "__main__":
    main()




'''
- The Decorator Pattern is a structural design pattern in which you can add behavior to objects dynamically without altering their class structure. 
In Python, it's relatively straightforward to implement the Decorator Pattern due to the language's dynamic and flexible nature. 

- In this Python example: Component is the base interface that defines the common operation.

- ConcreteComponent is the concrete implementation of the base component.

- Decorator is the base decorator class that also implements the Component interface. It contains a reference to the wrapped Component.

- ConcreteDecoratorA and ConcreteDecoratorB are the concrete decorator classes that add additional behavior to the component. They override the 
operation method and call the wrapped component's operation method while adding their specific behavior.

- In the main function, we create a chain of decorators. The ConcreteComponent is wrapped by ConcreteDecoratorA, which is further wrapped by 
ConcreteDecoratorB. When we call the operation method on the final decorator, it invokes the operation of the wrapped component and adds the specific behavior.

- The Decorator Pattern allows you to dynamically extend the behavior of objects in Python without modifying their classes, making it a flexible 
and powerful way to add functionality.

'''