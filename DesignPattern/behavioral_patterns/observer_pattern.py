# Observer interface
class Observer:
    def update(self, message):
        pass

# Concrete Observer
class ConcreteObserver(Observer):
    def __init__(self, name):
        self.name = name

    def update(self, message):
        print(f"{self.name} received message: {message}")

# Subject (Observable) interface
class Subject:
    def attach(self, observer):
        pass

    def detach(self, observer):
        pass

    def notify(self, message):
        pass

# Concrete Subject
class ConcreteSubject(Subject):
    def __init__(self):
        self.observers = []

    def attach(self, observer):
        self.observers.append(observer)

    def detach(self, observer):
        if observer in self.observers:
            self.observers.remove(observer)

    def notify(self, message):
        for observer in self.observers:
            observer.update(message)

def main():
    subject = ConcreteSubject()

    observer1 = ConcreteObserver("Observer 1")
    observer2 = ConcreteObserver("Observer 2")

    subject.attach(observer1)
    subject.attach(observer2)

    subject.notify("Hello, observers!")

    subject.detach(observer2)

    subject.notify("Updated message")

if __name__ == "__main__":
    main()



'''
Output:

Observer 1 received message: Hello, observers!
Observer 2 received message: Hello, observers!
Observer 1 received message: Updated message
'''

'''
- The Observer Pattern is a behavioral design pattern that defines a one-to-many dependency between objects so that when one object (the subject) changes 
its state, all its dependents (observers) are notified and updated automatically. In Python, you can implement the Observer Pattern using classes and 
functions or methods to manage the relationship between subjects (observable objects) and observers.

- In this Python example: Observer is the observer interface that defines the update method for receiving updates from the subject.
- ConcreteObserver is a concrete observer class that implements the update method and can receive and process updates.
- Subject is the subject (observable) interface that defines methods for attaching, detaching, and notifying observers.
- ConcreteSubject is a concrete subject class that maintains a list of observers and notifies them when there is a change in its state.

- In the main function, we create a ConcreteSubject instance and two ConcreteObserver instances. We attach both observers to the subject, notify them with
 a message, detach one observer, and notify the remaining observer again.

- This example demonstrates the Observer Pattern in Python, where the subject notifies its observers when it changes state, allowing for a one-to-many
 relationship between the subject and observers.
'''
