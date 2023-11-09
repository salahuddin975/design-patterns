#include <iostream>
#include <vector>

// Observer interface
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// Concrete Observer
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}
    
    void update(const std::string& message) override {
        std::cout << name << " received message: " << message << std::endl;
    }

private:
    std::string name;
};

// Subject (Observable) interface
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(const std::string& message) = 0;
};

// Concrete Subject
class ConcreteSubject : public Subject {
public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify(const std::string& message) override {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

private:
    std::vector<Observer*> observers;
};

int main() {
    ConcreteSubject subject;

    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.notify("Hello, observers!");
    subject.detach(&observer2);
    subject.notify("Updated message");

    return 0;
}


/*
Output:

Observer 1 received message: Hello, observers!
Observer 2 received message: Hello, observers!
Observer 1 received message: Updated message
*/

/*
- The Observer Pattern is a behavioral design pattern that defines a one-to-many dependency between objects so that when one object changes state, 
all its dependents (observers) are notified and updated automatically. In C++, you can implement the Observer Pattern using classes and pointers or 
references to manage the relationship between subjects (observable objects) and observers.

- In this example: Observer is the observer interface that defines the update method for receiving updates from the subject.
- ConcreteObserver is a concrete observer class that implements the update method and can receive and process updates.
- Subject is the subject (observable) interface that defines methods for attaching, detaching, and notifying observers.
- ConcreteSubject is a concrete subject class that maintains a list of observers and notifies them when there is a change in its state.

- In the main function, we create a ConcreteSubject instance and two ConcreteObserver instances. We attach both observers to the subject, notify 
them with a message, detach one observer, and notify the remaining observer again.

- This example demonstrates the Observer Pattern in C++, where the subject notifies its observers when it changes state, allowing for a one-to-many 
relationship between the subject and observers.
*/
