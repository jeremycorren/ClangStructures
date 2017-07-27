/*
 * Tester.
 */

#include <stdio.h>
#include "hashmap.h"

 int main() {
     /* Insert entries into map */
     printf("%s\n", "Testing put and get:");
     put("Lincoln", "16");
     put("Roosevelt", "26");

     /* Testing get */
     printf("%s %s\n", "Lincoln:", get("Lincoln"));
     printf("%s %s\n", "Roosevelt:", get("Roosevelt"));
     printf("\n");

     /* Testing put on update */
     printf("%s\n", "Testing put on update:");
     put("Roosevelt", "32");
     printf("%s %s\n", "Roosevelt:", get("Roosevelt"));
     printf("\n");

     /* Testing has */
     printf("%s\n", "Testing has:");
     printf("%d\n", has("Lincoln"));
     printf("%d\n", has("Washington"));
     printf("\n");
     return 0;
 }
