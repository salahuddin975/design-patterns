#include <iostream>

// Strategy interface
class SortStrategy {
public:
    virtual void sort() const = 0;
};

// Concrete strategies
class BubbleSort : public SortStrategy {
public:
    void sort() const override {
        std::cout << "Sorting using Bubble Sort.\n";
        // Implementation of Bubble Sort
    }
};

class QuickSort : public SortStrategy {
public:
    void sort() const override {
        std::cout << "Sorting using Quick Sort.\n";
        // Implementation of Quick Sort
    }
};

// Context class
class SortContext {
private:
    SortStrategy* strategy;

public:
    SortContext(SortStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortStrategy* strategy) {
        this->strategy = strategy;
    }

    void performSort() const {
        strategy->sort();
    }
};

int main() {
    // Create strategies
    BubbleSort bubbleSort;
    QuickSort quickSort;

    // Create context with the default strategy
    SortContext context(&bubbleSort);

    // Use the default strategy
    context.performSort();

    // Change the strategy at runtime
    context.setStrategy(&quickSort);

    // Use the new strategy
    context.performSort();

    return 0;
}


/*
Output:

Sorting using Bubble Sort.
Sorting using Quick Sort.
*/

/*
- The Strategy Pattern is a behavioral design pattern that defines a family of algorithms, encapsulates each algorithm, and makes them interchangeable. 
It allows the client to choose the appropriate algorithm at runtime. 

- In this example: SortStrategy is the abstract strategy interface that declares a method sort.
- BubbleSort and QuickSort are concrete implementations of the SortStrategy interface.
- SortContext is the context class that contains a pointer to the current strategy. It has a method performSort that delegates the sorting to the current strategy.

- In the main function, we create instances of the concrete strategies (BubbleSort and QuickSort) and use them with the SortContext. The context can switch 
between different strategies at runtime, providing flexibility and interchangeability.

- This pattern is useful when you have multiple algorithms that can be used interchangeably, and you want to avoid exposing the details of the algorithms 
to the client code. The client code interacts with the context class, and the actual algorithm is encapsulated within the strategy classes.
*/

