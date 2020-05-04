/*
# Name: Moses Garcia
# Date: March 31, 2020
# Title: Lab4 C
# Description: LRU FIFO and Page Replacemnet 
*/
#ifndef _queue_H_
#define _queue_H_

#include <stdint.h>
#include "node.h"

struct queue {
  struct node *front; // front node or head
  struct node *back;  // back node or tail
};

/**
 * Allocates new queue dynamically.
 * 
 * @return pointer to the queue
 */
struct queue *queue_create();

/** 
 * Inserts new node in queue after the last node.
 *
 * @param l pointer to the queue (non-NULL)
 * @param int data
 * returns a pointer to the newly added node
 */
struct node* enqueue(struct queue *q, int data);

/** 
 * Inserts new node in queue before the first node.
 *
 * @param l pointer to the queue (non-NULL)
 * @param int data
 * returns a pointer to the newly added node
 */
struct node* queue_add_front(struct queue *q, int data);

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the queue (non-NULL)
 * @parap int data
 * @return struct snode* or NULL if no match
 */
struct node* queue_find(struct queue *q, int data);

/**
 * Deallocate a queue and all snodes
 * @param l pointer to the queue
 */
void queue_destroy(struct queue *q);

/**
 * Traverse the queue and print the content of each node.
 * @param l pointer to the queue (non-NULL)
 */
void queue_traverse(struct queue *q);

/**
 * Returns the number of elements in the queue (nodes).
 * @param l pointer to the queue (non-NULL)
 */
uint32_t queue_length(struct queue *q);

/**
 * Deletes the first snode with the given string.
 * @param l pointer to the queue (non-NULL)
 * @param int int data
 */
void queue_delete(struct queue *q, int data);

/**
 * Deletes the first snode of the queue.
 * @param l pointer to the queue (non-NULL)
 */
void dequeue(struct queue *q);

struct node* queue_get_front(struct queue* q);

struct node* queue_get_back(struct queue* q);

#endif /* _queue_H_ */
