#include <iostream>
#include <thread>
#include <shared_mutex>

std::shared_mutex rwLock;  // Create a shared reader-writer lock
int sharedData = 0;

void reader(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate some work
    std::shared_lock<std::shared_mutex> lock(rwLock);
    std::cout << "Reader " << id << " reads: " << sharedData << std::endl;
}

void writer(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate some work
    std::unique_lock<std::shared_mutex> lock(rwLock);
    sharedData = id;
    std::cout << "Writer " << id << " writes: " << sharedData << std::endl;
}

int main() {
    std::thread writers[3];
    std::thread readers[5];

    for (int i = 0; i < 3; ++i) {
        writers[i] = std::thread(writer, i);
    }

    for (int i = 0; i < 5; ++i) {
        readers[i] = std::thread(reader, i);
    }

    for (int i = 0; i < 3; ++i) {
        writers[i].join();
    }

    for (int i = 0; i < 5; ++i) {
        readers[i].join();
    }

    return 0;
}


/*
- The Reader-Writer Lock pattern is a synchronization pattern that allows multiple readers to access a resource simultaneously but ensures that only 
one writer can access the resource at a time. This pattern is used to manage concurrent access to shared resources while optimizing performance. 
In C++, you can implement a Reader-Writer Lock using the std::shared_mutex introduced in C++17. Here's an example:

- In this example: We use the std::shared_mutex to create a shared reader-writer lock, rwLock. The std::shared_lock is used by readers to lock the resource 
in a shared (read) mode, and the std::unique_lock is used by writers to lock the resource exclusively.

- The reader function simulates a reader. It sleeps for some time to simulate work, then acquires a shared lock using std::shared_lock to read the shared data and prints it.

- The writer function simulates a writer. It sleeps for some time to simulate work, then acquires a unique lock using std::unique_lock to write data to 
the shared resource and prints it.

- In the main function, we create and start three writer threads and five reader threads.

- The writers and readers run concurrently, and you'll notice that multiple readers can access the shared data simultaneously, while only one writer 
can access the data at a time.

- This example demonstrates the Reader-Writer Lock pattern in C++ using the std::shared_mutex. It provides efficient synchronization for shared data 
access while allowing multiple readers to read simultaneously and ensuring exclusive access for writers.

*/
