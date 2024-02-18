/* main.c */
#include <stdio.h>
#include "simple_hashing.h"

int hashing_fonction (double value) {
    int hash = (int) value % SIZE_HASH_TABLE ;
    if (hash < 0) {
        hash = hash + SIZE_HASH_TABLE ;
    }
    return hash ;
}

int main () {
    struct hash_table hash_table ;
    init_hash_table (&hash_table, &hashing_fonction);
    double value ;
    printf("List a sequence of float ending with 0 :\n") ;
    scanf ("%lf", &value);
    while (value != 0) {
        add_value_hash_table (&hash_table, value);
        scanf("%lf", &value);
        }
    print_hash_table(&hash_table) ;
    clear_hash_table (&hash_table) ;
    return 0 ;
}
