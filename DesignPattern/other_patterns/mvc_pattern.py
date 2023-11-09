class Model:
    def __init__(self):
        self.data = []

    def add_data(self, item):
        self.data.append(item)

    def get_data(self):
        return self.data

class View:
    def display_data(self, data):
        print("Data in the Model:")
        for item in data:
            print(item)

    def show_message(self, message):
        print("Message:", message)

class Controller:
    def __init__(self):
        self.model = Model()
        self.view = View()

    def add_data(self, item):
        self.model.add_data(item)
        self.view.show_message("Data added successfully.")

    def display_data(self):
        data = self.model.get_data()
        self.view.display_data(data)

def main():
    controller = Controller()

    controller.add_data("Item 1")
    controller.add_data("Item 2")
    controller.add_data("Item 3")

    controller.display_data()

if __name__ == "__main__":
    main()



'''
Output:

Message: Data added successfully.
Message: Data added successfully.
Message: Data added successfully.
Data in the Model:
Item 1
Item 2
Item 3
'''

'''
- In this Python example, we follow the same principles as in the C++ example:
- Model: The Model class represents the application's data and business logic. It provides methods to modify and access the data, which in this case is a simple list.
- View: The View class is responsible for displaying data to the user. It provides methods for rendering data and messages to the console.
- Controller: The Controller class acts as an intermediary between the Model and the View. It receives user input, interacts with the Model to 
update data, and instructs the View to display information.

- In the main function, a Controller object is created, and data is added to the Model using the Controller's add_data method. The display_data 
method of the Controller is used to display the data in the Model via the View.

- The MVC pattern in Python follows the same principles as in other programming languages, making it easier to maintain and extend your applications 
by separating concerns and keeping your code organized.
'''
