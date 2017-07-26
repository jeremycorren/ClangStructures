/*
 * Binary tree header.
 */

#include <stdlib.h>

/* Node representation */
struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
};

/* Binary tree representation */
struct Tree {
    struct Node *root;
};

/* Initialize tree */
static inline void init_tree(struct Tree *tree) {
    tree->root = NULL;
}

/* Insert node into tree */
void insert(struct Tree *tree, void *data);
struct Node *_insert(struct Node *node, void *data);

/* Remove node with min key from tree */
void remove_min(struct Tree *tree);
struct Node *_remove_min(struct Node *node);

/* Traverse tree */
void traverse_tree(struct Tree *tree, void (*func)(void *));
void _traverse_tree(struct Node *node, void (*func)(void *));

/* Print node's data member */
void print_data(void *data);
