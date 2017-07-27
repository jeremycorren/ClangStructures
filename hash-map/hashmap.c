/*
 * Hash map implementation.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hashmap.h"

#define SIZE 1

/* Hash map representation */
static struct Entry *map[SIZE];

/* Compute hash code for key */
unsigned hash(char *key) {
    unsigned code;
    for (code = 0; *key != '\0'; key++)
        code = *key + 31 * code;
    return code % SIZE;
}

/* Return value associated with key */
char *get(char *key) {
    struct Entry *entry = _get(key);
    return entry->val;
}

/* Return entry with key */
struct Entry *_get(char *key) {
    struct Entry *chain = map[hash(key)];
    for ( ; chain != NULL; chain = chain->next)
        if (strcmp(key, chain->key) == 0)
            return chain;
    return NULL;
}

/* Insert or update entry in map */
void put(char *key, char *val) {
    struct Entry *entry;
    unsigned code;
    if ((entry = _get(key)) == NULL) {
        entry = (struct Entry *) malloc(sizeof(*entry));
        if (entry == NULL) {
            perror("put: Malloc failed");
            exit(0);
        }
        entry->key = key;
        entry->val = val;
        code = hash(key);
        entry->next = map[code];
        map[code] = entry;
    } else
        entry->val = val;
}

/* Return true if map contains key */
bool has(char *key) {
    return _get(key) != NULL;
}
