#include <iostream>
#include <vector>

// Model
class Model {
private:
    std::vector<std::string> data;

public:
    void addData(const std::string& item) {
        data.push_back(item);
    }

    const std::vector<std::string>& getData() {
        return data;
    }
};

// View
class View {
public:
    void displayData(const std::vector<std::string>& data) {
        std::cout << "Data in the Model:" << std::endl;
        for (const auto& item : data) {
            std::cout << item << std::endl;
        }
    }

    void showMessage(const std::string& message) {
        std::cout << "Message: " << message << std::endl;
    }
};

// Controller
class Controller {
private:
    Model model;
    View view;

public:
    void addData(const std::string& item) {
        model.addData(item);
        view.showMessage("Data added successfully.");
    }

    void displayData() {
        view.displayData(model.getData());
    }
};

int main() {
    Controller controller;

    controller.addData("Item 1");
    controller.addData("Item 2");
    controller.addData("Item 3");

    controller.displayData();

    return 0;
}


/*
Output:

Message: Data added successfully.
Message: Data added successfully.
Message: Data added successfully.
Data in the Model:
Item 1
Item 2
Item 3
*/


/*
- The Model-View-Controller (MVC) pattern is a design pattern that separates an application into three interconnected components: Model, View, and Controller. 
It's used to structure the code of an application to ensure the separation of concerns, making the code more modular and maintainable. 

- Implementing the Model-View-Controller (MVC) pattern in C++ helps in separating the concerns of an application by dividing it into three 
interconnected components: the Model, View, and Controller. Below is a simple example of the MVC pattern in C++. In this example, we'll 
create a basic text-based console application.

- In this example: Model: The Model class represents the application's data and business logic. It provides methods to modify and access the data. 
In this case, it stores a vector of strings.
- View: The View class is responsible for displaying the data to the user. It provides methods for rendering data and messages to the console.
- Controller: The Controller class acts as an intermediary between the Model and the View. It receives user input, interacts with the Model to 
update data, and instructs the View to display information.

- In the main function, a Controller object is created, and data is added to the Model using the Controller's addData method. The displayData method 
of the Controller is used to display the data in the Model via the View.

- The MVC pattern separates concerns, making the application easier to maintain and extend. In more complex applications, you can have multiple views 
and controllers to manage different aspects of the application, while the Model remains consistent.
*/