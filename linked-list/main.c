/*
 * Tester.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.h"

int main() {
    /* Create list */
    struct List list;
    init_list(&list);

    /* Add nodes to list */
    printf("%s\n", "Testing push and traverse_list: ");
    push(&list, "world");
    push(&list, "hello");
    traverse_list(&list, (void (*)(void *))(print_data));
    printf("\n");

    /* Test contains */
    printf("%s\n", "Testing contains: ");
    printf("%d %d\n", contains(&list, "hello"), contains(&list, "no"));
    printf("\n");
     
    /* Test find_node and add_after */
    printf("%s\n", "Testing find_node and add_after: ");
    struct Node *add = find_node(&list, "hello", (int (*)(const void *, const void *))(strcmp));
    add_after(&list, add, "my");
    traverse_list(&list, (void (*)(void *))(print_data));
    printf("\n");

    /* Test reverse_list */
    printf("%s\n", "Testing reverse_list: ");
    reverse_list(&list);
    traverse_list(&list, (void (*)(void *))(print_data));
    printf("\n");

    /* Test remove_all_nodes */
    printf("%s\n", "Testing remove_all_nodes: ");
    remove_all_nodes(&list);
    traverse_list(&list, (void (*)(void *))(print_data));
    return 0;
}
