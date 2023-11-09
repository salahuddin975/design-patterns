class Singleton:
    _instance = None      # Private variable to hold the single instance

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(Singleton, cls).__new__(cls)    # creates a new instance
            cls._instance.init_singleton()    # perform any initialization here
        return cls._instance 

    def init_singleton(self):
        self.value = 0    # example attribute for the singleton

if __name__ == '__main__':
    s1 = Singleton()
    s2 = Singleton()
    s1.value = 10
    print(s1.value)
    print(s2.value)
    print(s1 is s2)



'''
Output:

10
10
True
'''

'''
- The Singleton class defines a private class variable _instance to hold the single instance of the class.
- The __new__ method is overridden to control the creation of instances. It checks whether _instance is already set. If not, it creates a new instance 
and assigns it to _instance. If _instance already exists, it returns the existing instance.
- The init_singleton method can be used for any initialization logic for the singleton.

- In the usage section, you create two instances s1 and s2, but they both refer to the same underlying object. Modifying the value attribute of s1 also 
changes the value attribute of s2 because they share the same instance.
'''
