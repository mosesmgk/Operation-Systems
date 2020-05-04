/*
# Name: Moses Garcia 
# Date: 4/07/2020
Lab assignment 5 Step 2
# Title: Lab5 where
threads may print same values of i problem fix 
# Description: The fix using pthread_mutex_lock(&lock)
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *go(void *);
#define NTHREADS 10

pthread_t threads[NTHREADS];

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

int main()
 {
 int i;
 for (i = 0; i < NTHREADS; i++)
 
pthread_create(&threads[i], NULL, go, &i);
pthread_mutex_lock(&lock); 

for (i = 0; i < NTHREADS; i++) 
pthread_mutex_unlock(&lock);
 {
 printf("Thread %d returned\n", i);
 pthread_join(threads[i],NULL);
 }
 printf("Main thread done.\n");
 return 0;
}
void *go(void *arg) 
{
printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);
return 0;
}
