import threading
import time

# Initialize a semaphore with a maximum of 2 permits
semaphore = threading.Semaphore(2)

def worker(thread_id):
    print(f"Thread {thread_id} is trying to acquire a permit.")
    
    with semaphore:
        print(f"Thread {thread_id} has acquired a permit and entered the critical section.")
        time.sleep(2)
        print(f"Thread {thread_id} has released the permit and exited the critical section.")

# Create and start multiple threads
threads = []
for i in range(4):
    thread = threading.Thread(target=worker, args=(i,))
    threads.append(thread)
    thread.start()

# Wait for all threads to finish
for thread in threads:
    thread.join()

print("All threads have finished.")



'''
- In Python, you can use the threading module to implement a semaphore pattern to control access to a shared resource in a multi-threaded environment. 
Here's an example of using the threading.Semaphore class to achieve semaphore-based synchronization:

- In this Python example: We use the threading.Semaphore class to create a semaphore with a maximum of 2 permits. This means that up to two threads 
can enter the critical section concurrently.

- The worker function simulates the work done by each thread. It attempts to acquire a permit from the semaphore using a with statement. When a permit 
is acquired, the thread enters the critical section, simulates some work (sleeps for 2 seconds), and then releases the permit when it exits the critical section.

- We create and start four threads that call the worker function.

- After starting the threads, we wait for all of them to finish by calling thread.join() for each thread.

- When you run this code, you'll see that at most two threads enter the critical section concurrently because the semaphore allows only two permits. The other 
threads wait until a permit is released, and they can acquire it to enter the critical section.

- The threading.Semaphore class provides a convenient way to implement semaphore-based synchronization in Python for managing access to shared 
resources among multiple threads.
'''