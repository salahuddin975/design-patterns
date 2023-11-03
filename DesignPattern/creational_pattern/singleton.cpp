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
