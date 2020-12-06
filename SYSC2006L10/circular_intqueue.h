/* 
 * SYSC 2006 Winter 2019 Lab 10
 *
 * circular_intqueue.h - circular linked-list implementation of a queue.
 */

 /* A queue consists of exactly one instance of the intqueue_t struct,
  * and 0 or more instances of the intnode_t struct.
  * All instances are allocated from the heap.
  */

/* A node in the linked list. */

typedef struct intnode {
    int value;
    struct intnode *next;
} intnode_t;


typedef struct {
    intnode_t *rear;   // Points to the node at the tail of the 
                       // queue's linked list
    int size;          // The # of nodes in the queue's linked list
} intqueue_t;

intnode_t *intnode_construct(int value, intnode_t *next);

intqueue_t *intqueue_construct(void);

void intqueue_enqueue(intqueue_t *queue, int value);
_Bool intqueue_dequeue(intqueue_t *queue, int *element);
_Bool intqueue_front(const intqueue_t *queue, int *element);

void intqueue_print(const intqueue_t *queue);
