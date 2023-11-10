#include <iostream>
#include <vector>

// Command interface
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

// Receiver
class Receiver {
public:
    void action() {
        std::cout << "Receiver's action" << std::endl;
    }
};

// Concrete Command
class ConcreteCommand : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand(Receiver* rec) : receiver(rec) {}

    void execute() override {
        receiver->action();
    }
};

// Invoker
class Invoker {
private:
    Command* command;

public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void executeCommand() {
        command->execute();
    }
};

int main() {
    Receiver receiver;
    ConcreteCommand concreteCommand(&receiver);
    Invoker invoker;

    invoker.setCommand(&concreteCommand);
    invoker.executeCommand();

    return 0;
}


/*
Output:

Receiver's action
*/

/*
- The Command Pattern is a behavioral design pattern that turns a request into a standalone object, which contains all the information about 
the request. This separation allows for parameterization of objects with different requests, queuing of requests, and the support of undoable operations. 

- In this example: Command is the command interface that declares the execute method.
- Receiver is an object that performs the actual action.
- ConcreteCommand is a concrete command class that implements the Command interface and holds a reference to the Receiver. The execute method of ConcreteCommand 
invokes the action method of the Receiver.
- Invoker is responsible for invoking the command. It holds a reference to a command and calls its execute method.

- In the main function, we create an instance of the Receiver, ConcreteCommand, and Invoker. We set the ConcreteCommand as the command for the Invoker 
and then execute the command.

- This simple example demonstrates the basic structure of the Command Pattern in C++, where a command is encapsulated in an object, allowing for 
parameterization and decoupling of the sender (Invoker) and the receiver (Receiver).
*/