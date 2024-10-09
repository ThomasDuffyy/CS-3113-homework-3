#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 10
#define NUMBERS_PER_THREAD 1000

// Structure to pass data to each thread
typedef struct {
    int start;
    int end;
    long sum;
} ThreadData;

// Function that each thread will execute to calculate the sum
void* calculate_sum(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    data->sum = 0;
    for (int i = data->start; i <= data->end; ++i){
        data->sum += i;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int range_start = 0;
    long total_sum = 0;

    // Create 10 threads, each handling 1000 numbers
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_data[i].start = range_start;
        thread_data[i].end = range_start + NUMBERS_PER_THREAD - 1;
        range_start += NUMBERS_PER_THREAD;

        // Create thread and check for errors
        if (pthread_create(&threads[i], NULL, calculate_sum, (void*)&thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for each thread to complete and accumulate the total sum
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].sum;
    }

    // Print total sum
    printf("Total sum of numbers from 0 to 9999: %ld\n", total_sum);

    return 0;
}
