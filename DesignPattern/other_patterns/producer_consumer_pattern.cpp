#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

const int buffer_size = 5;  // Size of the shared buffer
std::vector<int> buffer;    // Shared buffer to store data
std::mutex mtx;             // Mutex to protect access to the buffer
std::condition_variable buffer_not_full;  // Signaled when the buffer is not full
std::condition_variable buffer_not_empty; // Signaled when the buffer is not empty

void producer(int id) {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        while (buffer.size() >= buffer_size) {
            // Buffer is full; wait for a consumer to make space
            buffer_not_full.wait(lock);
        }
        int data = i * 100 + id;
        buffer.push_back(data);
        std::cout << "Producer " << id << " produced: " << data << std::endl;
        buffer_not_empty.notify_all(); // Notify consumers that the buffer is not empty
    }
}

void consumer(int id) {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        while (buffer.empty()) {
            // Buffer is empty; wait for a producer to add data
            buffer_not_empty.wait(lock);
        }
        int data = buffer.back();
        buffer.pop_back();
        std::cout << "Consumer " << id << " consumed: " << data << std::endl;
        buffer_not_full.notify_all(); // Notify producers that the buffer is not full
    }
}

int main() {
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    for (int i = 1; i <= 3; ++i) {
        producers.emplace_back(producer, i);
        consumers.emplace_back(consumer, i);
    }

    for (auto& producer_thread : producers) {
        producer_thread.join();
    }

    for (auto& consumer_thread : consumers) {
        consumer_thread.join();
    }

    return 0;
}


/*
- The Producer-Consumer pattern is a classic multi-threading synchronization pattern where one or more producer threads produce data, and one or more 
consumer threads consume the data. The data is typically stored in a shared buffer. In this example, I'll provide a basic implementation of the 
Producer-Consumer pattern in C++ using std::thread and std::mutex.

- In this example: We have a shared buffer of a fixed size (buffer_size) to store data produced by producers and consumed by consumers.

- The producer function simulates a producer, and the consumer function simulates a consumer. Producers generate data and push it into the buffer, 
while consumers pop data from the buffer. They use condition variables to synchronize access to the buffer.

- The main function creates and starts producer and consumer threads. In this example, we have three producers and three consumers.

- Producers produce data and notify consumers when the buffer is not empty. Consumers consume data and notify producers when the buffer is not full.

- This example demonstrates a basic Producer-Consumer pattern in C++ using threads, mutexes, and condition variables to ensure safe and synchronized access to a shared buffer.
*/