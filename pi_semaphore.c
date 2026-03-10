//Varun Ramani, parallel pi estimation using pthreads and Simpson's Rule
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h> 

//global vars
double areas = 6400000.0;
double sum = 0.0;
double xIncrement;
int numThreads;
sem_t sem; 

//thread function takes in long for index at which to start at
void* calculate_pi(void* arg) {
    //cast arg to start index
    long start = (long)arg;
    double localSum = 0.0;
  
    //calc upper limit
    long upperLim = start + (6400000 / numThreads);
    if (upperLim >= 6400000) {
        upperLim = 6400001; 
    }

    //loop to add values
    for (long i = start; i < upperLim; i++) {
      
        double currentx = i * xIncrement;
        //checks if start or end so it doesnt multiply
        //improved logic for multiplication
        if (i == 0 || i == 6400000) {
            localSum += (double) 4.0 / (1.0 + pow(currentx, 2));
        } else if (i % 2 != 0) {
            localSum += ((double) 4.0 / (1.0 + pow(currentx, 2)) * 4.0);
        } else {
            localSum += ((double) 4.0 / (1.0 + pow(currentx, 2)) * 2.0);
        }
    }
    //lock and unlock semaphore
    sem_wait(&sem); 
    sum += localSum;
    sem_post(&sem); 
    
    return NULL;
}

//main takes in 2 arguments from cmd line, one being num threads
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./pi_parallel <numThreads>\n");
        return 1;
    }

    numThreads = atoi(argv[1]);
    if (numThreads < 1) {
        printf("Please enter a valid thread count.\n");
        return 1;
    }

    xIncrement = 1.0 / areas;
    //initialize sem
    sem_init(&sem, 0, 1); 

    pthread_t threads[numThreads];

    //starts timer
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    long chunk_size = 6400000 / numThreads;

    //start all threads
    for (long i = 0; i < numThreads; i++) {
        long startIndex = i * chunk_size;
        pthread_create(&threads[i], NULL, calculate_pi, (void*)startIndex);
    }

    //join all threads
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    //end timer and convert nanoseconds to decimal seconds
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double totalTime = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

    // Final calculations
    sum = sum * (xIncrement / 3.0);
    double error = M_PI - sum;

    // Print results
    printf("Estimated value of Pi for %.0f points using Simpson's rule = %.15f\n", areas, sum);
    printf("Computation error = Exact value - Estimated value = %.15f\n", error);
    printf("Total runtime: %.15f seconds\n", totalTime);
    //destroy sem
    sem_destroy(&sem); 
    return 0;
}
