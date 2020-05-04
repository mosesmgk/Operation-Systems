/*
# Name: Moses Garcia 
# Date: 04/14/2020
# Title: Lab6 Synchronization using semaphores
# Description: This program computes a proder and consumer problem to wirte the alphabet 
*/
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define BUFF_SIZE 2
#define FULL 0
#define EMPTY 0

char buffer[BUFF_SIZE];
int nextIn = 0;
int nextOut = 0;

sem_t empty_sem_mutex; 
sem_t full_sem_mutex;

void Put(char item)
{
  int value;
  sem_wait(&empty_sem_mutex); 

  buffer[nextIn] = item;
  nextIn = (nextIn + 1) % BUFF_SIZE;
  printf("Producing %c ...nextIn %d\n",item,nextIn,item);
  if(nextIn==FULL)
  {
      sem_post(&full_sem_mutex);
      sleep(2);
  }
  sem_post(&empty_sem_mutex);

}

void * Producer()
{
  int i;
  for(i = 0; i < 26; i++)
    {
      Put((char)('A'+ i % 26));
    }
}

void Get()
{
  int item;

  sem_wait(&full_sem_mutex); 

  item = buffer[nextOut];
  nextOut = (nextOut + 1) % BUFF_SIZE;
  printf("\t...Consuming %c ...nextOut %d\n",item,nextOut,item);
  if(nextOut==EMPTY) 
      sleep(1);
    }

  sem_post(&full_sem_mutex);
}

void * Consumer()
{
  int i;
  for(i = 0; i < 26; i++)
    {
      Get();
    }
}

int main()
{
  pthread_t ptid,ctid;
 
  sem_init(&empty_sem_mutex,0,1);
  sem_init(&full_sem_mutex,0,0);
/*
  if(pthread_create(&ptid, NULL,Producer, NULL))
    {
      printf("\n ERROR creating thread 1");
      exit(1);
    }

  if(pthread_create(&ctid, NULL,Consumer, NULL))
    {
      printf("\n ERROR creating thread 2");
      exit(1);
    }

  if(pthread_join(ptid, NULL))
    {
      printf("\n ERROR joining thread");
      exit(1);
    }

  if(pthread_join(ctid, NULL)) 
    {
      printf("\n ERROR joining thread");
      exit(1);
    }
*/
  sem_destroy(&empty_sem_mutex);
  sem_destroy(&full_sem_mutex);

  pthread_exit(NULL);
  return 1;
}
