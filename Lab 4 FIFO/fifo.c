/*
# Name: Moses Garcia
# Date: March 31, 2020
# Title: Lab4 C
# Description: LRU FIFO and Page Replacemnet 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "queue.h"
#include "node.h"

int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); 
    char pageCache[100]; 
    int page_in_file = 0; 
    int page_fault = 0; 
    int page_num = 0; 
    int node_total = 0; 
    struct queue* q = queue_create();
    struct node* temp = NULL;

   node_total = queue_length(q);
    while (fgets(pageCache, 100, stdin)){
    	page_num = atoi(pageCache); 

      temp = queue_find(q, page_num); 
      if(temp == NULL)
      {
         if(node_total >= CACHE_SIZE){
            dequeue(q); 
            enqueue(q, page_num);
         }
         else{
            enqueue(q, page_num);
            node_total++;
         }
         page_fault++;
      }
      page_in_file++;
    }
    printf("%d Total Page Faults in %d\n", page_fault, page_in_file);
    return 0;

}
