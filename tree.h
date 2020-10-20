
struct Performance * newPerformance();
void attachNode( struct Performance*performance, struct Node**node_ptr,void *src, unsigned int width );
int comparNode( struct Performance *performance, struct Node**node_ptr, int (*compar)(const void *, const void *),void *target);
struct Node**next( struct Performance *performance, struct Node**node_ptr, int direction);
void readNode( struct Performance *performance, struct Node **node_ptr, void *dest, unsigned int width );
void detachNode(struct Performance *performance, struct Node**node_ptr);
void addItem( struct Performance *performance, struct Node**node_ptr,int (*compar)(const void *, const void *),void *src, unsigned int width );
void freeTree( struct Performance *performance, struct Node**node_ptr);
int searchItem( struct Performance *performance, struct Node **node_ptr,int (*compar)(const void *, const void *),void *target, unsigned int width );

struct Performance{
    unsigned int reads;
    unsigned int writes;
    unsigned int frees;
    unsigned int mallocs;
};

struct Node{
    void * data;
    struct Node * lt;
    struct Node * gte;
};