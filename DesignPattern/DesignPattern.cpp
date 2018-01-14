#include <iostream>


void pattern_types();
void test_singleton();


int main()
{
    int type;


    while (true)
    {
        pattern_types();
        std::cin >> type;

        switch (type)
        {
        case 1:
            test_singleton();
            break;

        default:
            break;
        }
    }

	return 0;
}


void pattern_types()
{
    std::cout << "---------------------- Creational Pattern -----------------------" << std::endl;

    std::cout << "1. Singleton Pattern" << std::endl;
    std::cout << "2. Factory Pattern" << std::endl;
    std::cout << "3. Abstract Factory Pattern" << std::endl;
    std::cout << "4. Builder Pattern" << std::endl;
    std::cout << "5. Prototype Pattern" << std::endl;

    std::cout << "\n---------------------- Structural Pattern -----------------------" << std::endl;

    std::cout << "6. Adapter Pattern" << std::endl;
    std::cout << "7. Bridge Pattern" << std::endl;
    std::cout << "8. Filter Pattern" << std::endl;
    std::cout << "9. Composite Pattern" << std::endl;
    std::cout << "10. Decorator Pattern" << std::endl;
    std::cout << "11. Facade Pattern" << std::endl;
    std::cout << "12. Flyweight Pattern" << std::endl;
    std::cout << "13. Proxy Pattern" << std::endl;

    std::cout << "\n---------------------- Behavioral Pattern -----------------------" << std::endl;

    std::cout << "14. Chain of Responsibility Pattern" << std::endl;
    std::cout << "15. Command Pattern" << std::endl;
    std::cout << "16. Interpreter Pattern" << std::endl;
    std::cout << "17. Iterator Pattern" << std::endl;
    std::cout << "18. Mediator Pattern" << std::endl;
    std::cout << "19. Memento Pattern" << std::endl;
    std::cout << "20. Observer Pattern" << std::endl;
    std::cout << "21. State Pattern" << std::endl;
    std::cout << "22. Strategy Pattern" << std::endl;
    std::cout << "23. Template Pattern" << std::endl;

}
