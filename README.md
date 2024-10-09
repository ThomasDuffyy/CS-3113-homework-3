# CS-3113-homework-3
this zip file contain CS 3113 homework 3, readme ,  source code

This program shows the use of Pthreads in C to calculate the sum of integers from 0 to 999 using 10 threads. Each thread calculates the sum of 1000 numbers range (0 to 999). The main thread waits for all threads to finish their computation and then sums up the result of each thread to the total sum.

using the vm homework3.c is the source code that implements the multithreaded sum calculation using Pthreads, the source code is located in directory called homework3.

Compilation steps
gcc -o homework3 homework3.c 
./homework3

The output displays the total sum of numbers 0 to 9999.
Example output<img width="321" alt="Screenshot 2024-10-09 at 1 15 41 PM" src="https://github.com/user-attachments/assets/b2b3febc-db63-4d1c-80b9-bb53a0efaec8">


Program Details:
Threads: The program creates 10 threads using the pthread_create() function. Each thread calculates the sum for a specific range of numbers.
ThreadData Structure: This structure is used to pass the range of numbers (start and end) to each thread, along with a variable to store the partial sum.
pthread_join(): The main thread waits for each thread to complete its execution and then collects the partial sum computed by each thread.
Synchronization: Since each thread works on a different range of numbers, there is no need for synchronization mechanisms like mutexes.
