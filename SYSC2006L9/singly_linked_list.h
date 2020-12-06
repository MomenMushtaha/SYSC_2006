/* SYSC 2006 Winter 2019 Lab 9 */

/* A node in a singly-linked list that stores values of type int. */

typedef struct intnode {
    int    value;
    struct intnode *next;
} intnode_t;


/* Functions presented in lectures. */

intnode_t *intnode_construct(int value, intnode_t *next);
intnode_t *push(intnode_t *head, int value);
int length(intnode_t *head);
void print_list(intnode_t *head);

/* Functions that are implemented in Lab 9. */

int count(intnode_t *head, int target);
int index(intnode_t *head, int target);
int fetch(intnode_t *head, int index);
intnode_t *pop(intnode_t *head, int *popped_value);
