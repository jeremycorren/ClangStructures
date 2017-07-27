/*
 * Hash map header.
 */

#include <stdlib.h>
#include <stdbool.h>

/* Entry node representation */
struct Entry {
    char *key;
    char *val;
    struct Entry *next;
};

/* Compute hash code for key */
unsigned hash(char *key);

/* Return value associated with key */
char *get(char *key);

/* Return entry with key */
struct Entry *_get(char *key);

/* Insert or update entry in map */
void put(char *key, char *val);

/* Return true if map contains key */
bool has(char *key);
