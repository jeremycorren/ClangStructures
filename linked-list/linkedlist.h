/*
 * Linked list header.
 */

#include <stdbool.h>

/* Node representation */
struct Node {
    void *data;
    struct Node *next;
};

/* Linked list representation */
struct List {
    struct Node *head;
};

static inline void init_list(struct List *list) {
    list->head = 0;
}

/* Insert node at the front of the list */
struct Node *push(struct List *list, void *data);

/* Remove node at the front of the list */
void *pop(struct List *list);

/* Return true if list contains node with key */
bool contains(struct List *list, const void *key);

/* Step through list to find node whose data matches key */
struct Node *find_node(struct List *list, const void *key, int(*compar)(const void *, const void *));

/* Insert node into middle of list */
struct Node *add_after(struct List *list, struct Node *prev, void *data);

/* Reverse the list */
void reverse_list(struct List *list);

/* Clear the list */
void remove_all_nodes(struct List *list);

/* Step through each node in the list and pass to func */
void traverse_list(struct List *list, void (*func)(void *));

/* Print node's data member */
void print_data(void *data);
