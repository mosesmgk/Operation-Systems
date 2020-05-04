/*
# Name: Moses Garcia
# Date: March 31, 2020
# Title: Lab4 C
# Description: LRU FIFO and Page Replacemnet 
*/
#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

struct queue *queue_create() {
   struct queue *q = (struct queue*) malloc(sizeof(struct queue));
   q->front = NULL;
   q->back = NULL;
   return q;
}


struct node* enqueue(struct queue *q, int data){
   struct node *n = node_create(data);

   if(q->front == NULL){ 
      q->front = n;
      q->front->next = NULL; 
      q->back = q->front;
      q->back->next = NULL;
   }
   else{ 
      q->back->next = n; 
      q->back->next = NULL; 
   }

   return n;  
}


struct node *queue_add_front(struct queue *q, int data){
   struct node *n = node_create(data);
   struct node* temp = q->front;

   if(q->front == NULL){
      q->front = n;
      q->front->next = NULL;
      q->back = q->front;
      q->back->next = NULL;
   }
   else{
      q->front = n;
      q->front->next = temp;
   }
   return n;
}


struct node* queue_find(struct queue *q, int data){
   int find = 0;
   struct node* n = q->front;

   while(n != NULL){
      if(n->data == data){
         find = 1;
         break;
      }
      n = n->next; 
   }
   if(!find)
   return NULL;

   return n;
}

void queue_destroy(struct queue *q){
   struct node* n = q->front;

   if(q->front == NULL){ 
      if(q != NULL)

      free(q);

      return;
   }
   while(n != NULL){
      q->front = n->next; 
      if(n != NULL)
      node_destroy(n); 
      n = n->next; 
   }
   if(q->front != NULL)

   exit(1);
   
   q->back = q->front; 

   free(q); 
}


void queue_traverse(struct queue *q){
   struct node *n = q->front; 

   if(q->front == NULL)
   printf("Empty List\n");

   int i = 0;
   while(n != NULL){
      printf("%d %d\n", i, n->data);
      n = n->next;
      i++;
   }
}


uint32_t queue_length(struct queue *q){ 

   if(q->front == NULL)
   return (uint32_t)0;

   int i= 0;
   while(n != NULL){
      n = n->next;
      i++;
   }

   return (uint32_t)i;
}

void queue_delete(struct queue *q, int data){
   struct node* prev_node = q->front;
   struct node* temp = NULL;
   int find = 0;

   if(prev_node == NULL)
   return;

   if(prev_node != NULL && prev_node->data == data){
      temp = prev_node;
      prev_node = prev_node->next;
      q->front = prev_node;
      if(q->front == NULL)
      q->back = NULL;
   }
   else {
      while(prev_node != NULL){
         if(prev_node->next != NULL){
            if(prev_node->next->data == data){
               temp = prev_node->next;
               if(temp == q->back){
                  q->back = prev_node;
               }
               find = 1;
               break;
            }
         }
         prev_node = prev_node->next;
      }
      if(!find)
      return;
      prev_node->next = prev_node->next->next;
   }
   node_destroy(temp);
}


void dequeue(struct queue *q){
   struct node* temp = q->front;

   if(q->front == NULL)
   return;

   q->front = q->front->next;
   node_destroy(temp);
}
