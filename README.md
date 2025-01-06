# Project "Philosophers - I Never Thought Philosophy Would Be So Deadly"

Summary: This project focuses on multithreading and synchronization in C. It simulates the "Dining Philosophers" problem using threads and mutexes to model philosophers who must share forks while eating. The goal is to ensure philosophers don't starve, while avoiding deadlock and ensuring proper resource handling. It is divided into a mandatory part and an optional bonus part, which employs processes and semaphores for synchronization.

Mandatory Part:

    Objective: Implement philosophers as threads, each using mutexes to protect the shared forks.
    Requirements:
        Proper thread creation and synchronization to avoid race conditions.
        Philosophers should not starve or encounter deadlocks.
        The program must handle user-defined arguments and print philosopher states.
        Includes use of pthread functions for thread management and synchronization.

Bonus Part (Optional):

    Objective: Implement philosophers as processes using semaphores.
    Requirements:
        Each philosopher is a separate process.
        The forks are represented by semaphores, with the main process managing them.
        The bonus part is only evaluated if the mandatory part works correctly.

This project reinforces core concepts of multithreading, process synchronization, and resource sharing, providing insight into practical concurrency challenges.
