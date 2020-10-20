#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct Performance * newPerformance(){
    struct Performance * perf = malloc(sizeof(struct Performance));
    perf->frees = 0;
    perf->mallocs = 0;
    perf->reads = 0;
    perf->writes = 0;
    return(perf);
}

void attachNode( struct Performance*performance, struct Node**node_ptr,void *src, unsigned int width ){
    struct Node * newNode = malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf(stderr,"Can't allocate enough memory for a new node struct");
    }

    newNode->data = malloc(sizeof(unsigned char) * width);

    if(newNode->data == NULL){
        printf(stderr,"Can't allocate enough memory for a new data struct");
    }

    memcpy(newNode->data,src,width);
    newNode->gte = NULL;
    newNode->lt = NULL;

    *node_ptr = newNode;
    performance->mallocs++;
    performance->writes++;
}

int comparNode( struct Performance *performance, struct Node**node_ptr, int (*compar)(const void *, const void *),void *target){
    struct Node * currentNode = *node_ptr;
    return((*compar)(target,currentNode->data));
}

struct Node**next( struct Performance *performance, struct Node**node_ptr, int direction){
    struct Node * currentNode = *node_ptr;
    struct Node ** nextNode = NULL;
    if(currentNode == NULL){
         printf(stderr,"Tree is empty");
    }

    if(direction >= 0){
        *nextNode = currentNode->gte;
    }
    else{
        *nextNode = currentNode->lt;
    }
    performance->reads++;
    return(nextNode);
}

void readNode( struct Performance *performance, struct Node **node_ptr, void *dest, unsigned int width ){
    struct Node * currentNode = *node_ptr;
    if(currentNode == NULL){
        printf(stderr,"Tree is empty");
    }

    memcpy(dest,currentNode->data,width);
    performance->reads++;
}

void detachNode(struct Performance *performance, struct Node**node_ptr){
    struct Node * nodeToBeFreed = *node_ptr;

    free(nodeToBeFreed->data);
    free(nodeToBeFreed);
    *node_ptr = NULL;
}