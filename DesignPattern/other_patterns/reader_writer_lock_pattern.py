import threading
import time

class ReaderWriterLock:
    def __init__(self):
        self.lock = threading.Lock()
        self.resource_lock = threading.Lock()
        self.resource = 0
        self.readers = 0

    def read(self, reader_id):
        with self.lock:
            self.readers += 1
            if self.readers == 1:
                # First reader acquires resource lock
                self.resource_lock.acquire()

        # Reading data
        print(f"Reader {reader_id} reads: {self.resource}")

        with self.lock:
            self.readers -= 1
            if self.readers == 0:
                # Last reader releases resource lock
                self.resource_lock.release()

    def write(self, writer_id, new_data):
        with self.lock:
            # Acquire resource lock
            self.resource_lock.acquire()

            # Writing data
            self.resource = new_data
            print(f"Writer {writer_id} writes: {self.resource}")

            # Release resource lock
            self.resource_lock.release()

def reader_thread(reader_id):
    for _ in range(5):
        rw_lock.read(reader_id)
        time.sleep(0.1)  # Simulate some work

def writer_thread(writer_id):
    for i in range(5):
        new_data = writer_id * 100 + i
        rw_lock.write(writer_id, new_data)
        time.sleep(0.1)  # Simulate some work

rw_lock = ReaderWriterLock()

reader_threads = [threading.Thread(target=reader_thread, args=(i,)) for i in range(3)]
writer_threads = [threading.Thread(target=writer_thread, args=(i,)) for i in range(2)]

for thread in reader_threads + writer_threads:
    thread.start()

for thread in reader_threads + writer_threads:
    thread.join()



'''
- Python provides a built-in module called threading for working with threads. However, Python's Global Interpreter Lock (GIL) can limit true parallel execution 
of threads in some cases. For scenarios where you need to implement a Reader-Writer Lock pattern in Python, you can use the threading module to manage concurrent 
access. Here's a basic example of a Reader-Writer Lock pattern in Python:

- In this Python example: We create a ReaderWriterLock class to manage the concurrent access of readers and writers to a shared resource. It uses 
Python's built-in threading.Lock for synchronization.

- Readers acquire a lock to access the shared resource, while writers acquire both the main lock and a resource-specific lock.

- The reader_thread and writer_thread functions simulate reader and writer threads, respectively. Readers read the shared resource, and writers write new data to it.

- We create and start three reader threads and two writer threads. The readers and writers run concurrently, and the lock implementation ensures that 
multiple readers can read simultaneously, while only one writer can write at a time.

- This example demonstrates a basic Reader-Writer Lock pattern in Python using the threading module. Keep in mind that Python's Global Interpreter Lock (GIL) 
may limit the true parallel execution of threads, so for CPU-bound tasks, you might consider using multiprocessing or alternative concurrency 
mechanisms for greater performance.
'''