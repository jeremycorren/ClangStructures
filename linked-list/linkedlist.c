/*
 * Linked list functions.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "linkedlist.h"

/* Insert node at the front of the list */
struct Node *push(struct List *list, void *data) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        perror("push: Malloc failed");
        exit(0);
    }
    node->data = data;
    node->next = list->head;
    list->head = node;
    return node;
}

/* Remove node from the front of list */
void *pop(struct List *list) {
    struct Node *node = list->head;
    void *data = node->data;
    list->head = node->next;
    free(node);
    return data;
}

/* Return true if list contains node whose data matches key */
bool contains(struct List *list, const void *key) {
    return find_node(list, key, (int (*)(const void *, const void *))(strcmp)) != NULL;
}

/* Step through list to find node whose data matches key */
struct Node *find_node(struct List *list, const void *key, int(*compar)(const void *, const void *)) {
    struct Node *p = list->head;
    for ( ; p != NULL; p = p->next)
        if (compar(p->data, key) == 0)
            return p;
    return NULL;
}

/* Insert node into middle of list */
struct Node *add_after(struct List *list, struct Node *prev, void *data) {
    if (prev == NULL)
        return push(list, data);
    else {
        struct Node *node = (struct Node*) malloc(sizeof(struct Node));
        if (node == NULL) {
            perror("add_after: Malloc failed");
            exit(0);
        }
        node->data = data;
        node->next = prev->next;
        prev->next = node;
        return node;
    }
}

/* Reverse the list */
void reverse_list(struct List *list) {
    struct Node *prev = NULL;
    struct Node *node = list->head;
    while (node != NULL) {
        struct Node *after = node->next;   
        node->next = prev;
        prev = node;
        node = after;       
    }
    list->head = prev; 
}

/* Clear the list */
void remove_all_nodes(struct List *list) {
    struct Node *p = list->head;
    for ( ; p != NULL; p = p->next)
        pop(list);
}

/* Step through each node in the list and pass to func */
void traverse_list(struct List *list, void (*func)(void *)) {
    struct Node *p = list->head;
    if (p == NULL) {
        printf("%s\n", "traverse_list: List is empty");
        exit(0);
    }
    for ( ; p != NULL; p = p->next)
        func(p->data);
    printf("\n");
}

/* Print node's data member */
void print_data(void *data) {
    printf("%s ", (char *) data);
}
