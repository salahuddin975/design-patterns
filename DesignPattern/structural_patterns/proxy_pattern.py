# Subject interface
class Subject:
    def request(self):
        pass

# Real subject
class RealSubject(Subject):
    def request(self):
        print("RealSubject handles the request.")

# Proxy
class Proxy(Subject):
    def __init__(self):
        self.real_subject = None

    def request(self):
        if not self.real_subject:
            self.real_subject = RealSubject()
        self.real_subject.request()

def main():
    proxy = Proxy()
    proxy.request()

if __name__ == "__main__":
    main()


'''
Output:

RealSubject handles the request.
'''


'''
- The Proxy Pattern is a structural design pattern that provides a surrogate or placeholder for another object to control access to it. 
In Python, you can easily implement the Proxy Pattern due to the language's dynamic nature. 

- In this Python example: Subject is the interface that defines the common operation, which is request.

- RealSubject is the concrete implementation of the subject interface. It represents the real object that the proxy will control access to.

- Proxy is the proxy class. It also implements the Subject interface. The proxy lazily instantiates the RealSubject when the request method is called.

- In the main function, we create an instance of the Proxy class and call its request method. The proxy, in turn, creates and delegates the request to the RealSubject.

- The Proxy Pattern in Python allows you to control access to an object, perform lazy loading, add logging, or provide additional functionalities without 
modifying the real subject's code, similar to the C++ example.

'''

