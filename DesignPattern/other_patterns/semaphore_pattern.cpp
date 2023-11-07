#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore<int> semaphore(2); // Allow up to 2 threads to enter the critical section

void worker(int id) {
    std::cout << "Thread " << id << " is waiting." << std::endl;
    semaphore.acquire(); // Try to acquire a permit

    // Critical section
    std::cout << "Thread " << id << " entered the critical section." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " exited the critical section." << std::endl;

    semaphore.release(); // Release the permit
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}



/*
- The Semaphore pattern is a synchronization primitive used to control access to a shared resource in a multi-threaded or multi-process environment. 
It helps in managing concurrent access to resources by allowing a limited number of threads or processes to enter a critical section simultaneously. 
In C++, you can use the std::semaphore introduced in C++20 to implement semaphore-based synchronization. Here's an example of using std::semaphore:

- In this example: We include the necessary headers for working with std::semaphore.

- We create a counting semaphore semaphore with an initial count of 2, which allows up to 2 threads to enter the critical section concurrently.

- The worker function represents the work that each thread does. It starts by waiting for the semaphore to acquire a permit.

- In the critical section, each thread prints a message, simulates work by sleeping for 2 seconds, and then prints another message.

- After exiting the critical section, the thread releases the permit by calling semaphore.release().

- In the main function, we create three threads (t1, t2, and t3) to demonstrate the semaphore-based synchronization. You can see that at most two 
threads can enter the critical section concurrently due to the semaphore's initial count of 2.

- Compile this code with C++20 support to use std::semaphore. This example shows how you can use semaphores to control concurrent access to a critical 
section in a multi-threaded C++ program.
*/
