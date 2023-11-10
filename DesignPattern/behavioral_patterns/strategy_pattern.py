# Strategy interface
class SortStrategy:
    def sort(self):
        pass

# Concrete strategies
class BubbleSort(SortStrategy):
    def sort(self):
        print("Sorting using Bubble Sort.")
        # Implementation of Bubble Sort

class QuickSort(SortStrategy):
    def sort(self):
        print("Sorting using Quick Sort.")
        # Implementation of Quick Sort

# Context class
class SortContext:
    def __init__(self, strategy):
        self._strategy = strategy

    def set_strategy(self, strategy):
        self._strategy = strategy

    def perform_sort(self):
        self._strategy.sort()

# Example usage
if __name__ == "__main__":
    # Create strategies
    bubble_sort = BubbleSort()
    quick_sort = QuickSort()

    # Create context with the default strategy
    context = SortContext(bubble_sort)

    # Use the default strategy
    context.perform_sort()

    # Change the strategy at runtime
    context.set_strategy(quick_sort)

    # Use the new strategy
    context.perform_sort()



'''
Output:

Sorting using Bubble Sort.
Sorting using Quick Sort.
'''

'''
- The Strategy Pattern is a behavioral design pattern that defines a family of algorithms, encapsulates each algorithm, and makes them interchangeable. 
It allows the client to choose the appropriate algorithm at runtime. 

- In this Python example: SortStrategy is the abstract strategy interface that declares a method sort.
- BubbleSort and QuickSort are concrete implementations of the SortStrategy interface.
- SortContext is the context class that contains a reference to the current strategy. It has a method perform_sort that delegates the sorting to the current strategy.

- In the example usage section, we create instances of the concrete strategies (BubbleSort and QuickSort) and use them with the SortContext. The context 
can switch between different strategies at runtime, providing flexibility and interchangeability.

- The dynamic nature of Python makes it straightforward to switch between different strategies at runtime. The Pythonic approach doesn't require explicit 
type declarations for interfaces, making the implementation concise and readable.
'''