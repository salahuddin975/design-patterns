import threading
import time
import queue

# Shared queue to store the data
shared_queue = queue.Queue(maxsize=5)  # Set the maximum queue size

# Producer function
def producer(id):
    for i in range(10):
        data = f"Data-{i} from Producer-{id}"
        print(f"Producer-{id} produced: {data}")
        shared_queue.put(data)
        time.sleep(0.1)  # Simulate some work

# Consumer function
def consumer(id):
    while True:
        data = shared_queue.get()
        if data is None:
            break  # Exit the loop when a sentinel value is received
        print(f"Consumer-{id} consumed: {data}")
        shared_queue.task_done()  # Mark the task as done

# Create and start producer threads
producer_threads = []
for i in range(3):
    producer_thread = threading.Thread(target=producer, args=(i,))
    producer_threads.append(producer_thread)
    producer_thread.start()

# Create and start consumer threads
consumer_threads = []
for i in range(2):
    consumer_thread = threading.Thread(target=consumer, args=(i,))
    consumer_threads.append(consumer_thread)
    consumer_thread.start()

# Wait for all producer threads to finish
for producer_thread in producer_threads:
    producer_thread.join()

# Send sentinel values to indicate the end of data
for _ in range(len(consumer_threads)):
    shared_queue.put(None)

# Wait for all consumer threads to finish
for consumer_thread in consumer_threads:
    consumer_thread.join()

print("All threads have finished.")



'''
- The Producer-Consumer pattern is a classic multi-threading synchronization pattern where one or more producer threads produce data, and one or more 
consumer threads consume the data. In Python, you can implement the Producer-Consumer pattern using the threading module for thread management and a 
shared queue for communication between producers and consumers. Here's a basic example:

- In this Python example: We use the queue.Queue class to create a shared queue with a maximum size of 5. The queue is used to pass data between producers and consumers.

- The producer function simulates a producer by producing data and putting it into the shared queue. Producers are designed to produce data continuously for demonstration purposes.

- The consumer function simulates a consumer by consuming data from the shared queue. Consumers keep consuming data until they receive a sentinel 
value (None), indicating the end of data.

- We create and start three producer threads and two consumer threads. The producers and consumers operate concurrently.

- After all producer threads have finished, we send sentinel values (None) to indicate the end of data for consumers.

- The code waits for all consumer threads to finish and prints a message when all threads have finished.

- This example demonstrates a basic Producer-Consumer pattern in Python using threads and a shared queue for synchronization and communication between producers and consumers.
'''

