/*
 * Binary tree implementation.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binarytree.h"

/* Insert node into tree */
void insert(struct Tree *tree, void *data) {
    tree->root = _insert(tree->root, data);
}

/* Recursively insert node into tree */
struct Node *_insert(struct Node *node, void *data) {
    int comp;
    if (node == NULL) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->data = data;
        node->left = node->right = NULL;
    } else if ((comp = strcmp(data, node->data)) < 0)
        node->left = _insert(node->left, data);
    else if (comp > 0)
        node->right = _insert(node->right, data);
    else
        node->data = data;
    return node;
}

/* Remove node with min data from tree */
void remove_min(struct Tree *tree) {
    tree->root = _remove_min(tree->root);
}

/* Recursively remove node with min data from tree */
struct Node *_remove_min(struct Node *node) {
    if (node->left == NULL) return node->right;
    node->left = _remove_min(node->left);
    return node;
}

/* Traverse tree */
void traverse_tree(struct Tree *tree, void (*func)(void *)) {
    _traverse_tree(tree->root, func); 
    printf("\n");
}

/* Recursively traverse tree */
void _traverse_tree(struct Node *node, void (*func)(void *)) {
    if (node != NULL) {
        _traverse_tree(node->left, func);
        func(node->data);
        _traverse_tree(node->right, func);
    }
}

/* Print node's data member */
void print_data(void *data) {
    printf("%s ", (char *) data);
}
