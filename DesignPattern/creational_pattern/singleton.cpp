#include <iostream>

class Singleton{
private:
  static Singleton* instance;   // private static pointer to hold the singleton object
  Singleton() {}                // private constructor to prevent instantiation from outside

public:
  static Singleton* getInstance() {    // public static method to access the single instance
    if (instance == nullptr){
      instance = new Singleton();
    }
    return instance;
  }
  void print() {
    std::cout << "singleton print method" << std::endl;
  }
};


Singleton* Singleton::instance = nullptr;      // initialize the static pointer to nullptr;

int main() {
  Singleton* s1 = Singleton::getInstance();
  Singleton* s2 = Singleton::getInstance();

  s1->print();
  s2->print();
  
  std::cout << (s1 == s2) << std::endl;
  return 0;
}

/*
- The Singleton class contains a private static pointer instance to hold the single instance of the class.
- The constructor is made private to prevent external instantiation of the class.
- The getInstance static method is used to access the single instance. It checks whether instance is already created; if not, it creates a new instance, and if it already exists, it returns the existing instance.
- In the main function, you create two instances, s1 and s2, using the getInstance method. They both refer to the same underlying object, as shown by the output comparison.
*/
