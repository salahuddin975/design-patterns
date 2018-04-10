#include <iostream>


void pattern_types();

void singleton_pattern();
void factory_pattern();
void builder_pattern();
void prototype_pattern();

void adapter_pattern();
void composite_pattern();

void command_pattern();


int main()
{
    int type, want_to_continue;

    while (true)
    {
        pattern_types();

        std::cout << "Please, input your choice: ";
        std::cin >> type;

        switch (type)
        {
        case 1:
            std::cout << "\n------------------ Singleton Pattern ----------------------\n"<< std::endl;
            singleton_pattern();
            break;

        case 2:
            std::cout << "\n------------------- Factory Pattern ------------------------\n" << std::endl;
            factory_pattern();
            break;

        case 3:
            std::cout << "\n--------------- Abstract Factory Pattern ---------------------\n" << std::endl;
            break;

        case 4:
            std::cout << "\n------------------- Builder Pattern ------------------------\n" << std::endl;
            break;

        case 5:
            std::cout << "\n------------------ Prototype Pattern ------------------------\n" << std::endl;
            prototype_pattern();
            break;

        case 6:
            std::cout << "\n------------------ Adapter Pattern ------------------------\n" << std::endl;
            adapter_pattern();
            break;

		case 9:
			std::cout << "\n------------------ Composite Pattern ------------------------\n" << std::endl;
			composite_pattern();
			break;

		case 15: 
			std::cout << "\n------------------ Command Pattern ------------------------\n" << std::endl;
			command_pattern();
			break;
        default:
            std::cout << "Your input choice is not correct." << std::endl;
            break;
        }

        std::cout << "\n\nWould you like to exit? 0 -> exit" << std::endl;

        std::cin >> want_to_continue;
        if (want_to_continue == false){
            break;
        }
    }

	return 0;
}


void pattern_types()
{
    std::cout << "\n\n\n---------------------- Creational Pattern -------------------" << std::endl;

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
    std::cout << "24. Visitor Pattern" << std::endl;

    std::cout << "\n---------------------- Other Patterns ---------------------------" << std::endl;

    std::cout << "25. Business Delegation Pattern" << std::endl;
    std::cout << "26. Composite Entity Pattern" << std::endl;
    std::cout << "27. Data Access Object Pattern" << std::endl;
    std::cout << "28. Front Controller Pattern" << std::endl;
    std::cout << "29. Intercepting Filter Pattern" << std::endl;
    std::cout << "30. MVC Pattern" << std::endl;
    std::cout << "31. Null Object Pattern" << std::endl;
    std::cout << "32. Service Locator Pattern" << std::endl;
    std::cout << "33. Transfer Object Pattern" << std::endl << std::endl << std::endl;
}
