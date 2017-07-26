/*
 * Tester.
 */

#include <stdio.h>
#include "binarytree.h"

int main() {
    /* Create binary tree */    
    struct Tree tree;
    init_tree(&tree);

    /* Insert nodes into tree */
    printf("%s\n", "Testing insert and traverse_tree: ");
    insert(&tree, "beta");
    insert(&tree, "alpha");
    insert(&tree, "gamma");
    traverse_tree(&tree, (void (*)(void *))(print_data));
    printf("\n"); 

    /* Test remove_min */
    printf("%s\n", "Testing remove_min: ");
    remove_min(&tree);
    traverse_tree(&tree, (void (*)(void *))(print_data));
    printf("\n");
   
    return 0;
}
