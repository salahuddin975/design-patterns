# Command interface
class Command:
    def execute(self):
        pass

# Receiver
class Receiver:
    def action(self):
        print("Receiver's action")

# Concrete Command
class ConcreteCommand(Command):
    def __init__(self, receiver):
        self.receiver = receiver

    def execute(self):
        self.receiver.action()

# Invoker
class Invoker:
    def __init__(self):
        self.command = None

    def set_command(self, command):
        self.command = command

    def execute_command(self):
        if self.command:
            self.command.execute()

def main():
    receiver = Receiver()
    concrete_command = ConcreteCommand(receiver)
    invoker = Invoker()

    invoker.set_command(concrete_command)
    invoker.execute_command()

if __name__ == "__main__":
    main()



'''
Output:

Receiver's action
'''

'''
- The Command Pattern is a behavioral design pattern that turns a request into a standalone object, which contains all the information about 
the request. This separation allows for parameterization of objects with different requests, queuing of requests, and the support of undoable operations. 

- In this example: Command is the command interface that declares the execute method.
- Receiver is an object that performs the actual action.
- ConcreteCommand is a concrete command class that inherits from Command and holds a reference to the Receiver. The execute method of ConcreteCommand 
invokes the action method of the Receiver.
- Invoker is responsible for invoking the command. It holds a reference to a command and calls its execute method.

- In the main function, we create an instance of the Receiver, ConcreteCommand, and Invoker. We set the ConcreteCommand as the command for the 
Invoker and then execute the command.

- This Python example follows the basic structure of the Command Pattern, where a command is encapsulated in an object, allowing for parameterization 
and decoupling of the sender (Invoker) and the receiver (Receiver).
'''
