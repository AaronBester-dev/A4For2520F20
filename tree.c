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
}

int comparNode( struct Performance *performance, struct Node**node_ptr, int (*compar)(const void *, const void *),void *target){
    
}