/*
# Name: Moses Garcia
# Date: March 31, 2020
# Title: Lab4 C
# Description: LRU FIFO and Page Replacemnet 
*/
#ifndef _node_H_
#define _node_H_

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *node_create(int data); 
void node_destroy(struct node * n);
int node_get_data(struct node* n);
struct node* node_get_next(struct node* n);

#endif
