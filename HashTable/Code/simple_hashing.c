#include <stdio.h>
#include <stdlib.h>
#include "simple_hashing.h"

void init_hash_table (struct hash_table* hash_table, hashing_function* hashing_function) {
    for (int i=0 ; i<SIZE_HASH_TABLE ; i++) {
        hash_table->table[i].set = false ;
        hash_table->table[i].value = 0 ;
    }
    hash_table->hashing = hashing_function ;
}

int check_value_hash_table (struct hash_table* hash_table, double value) {
    struct cell cell = hash_table->table[(hash_table->hashing(value))] ;
    if (cell.set == false) {
        return 0 ;
    } else {
        if (cell.value == value) {
            return 1 ;
        } else {
            return 2 ;
        }
    }
}

void add_value_hash_table (struct hash_table* hash_table, double value) {
    int check = check_value_hash_table(hash_table, value);
    if (check==0) {
        hash_table->table[hash_table->hashing(value)].value = value ;
        hash_table->table[hash_table->hashing(value)].set = true ;
    } else if (check==2) {
        printf("Error : Case %d in hash table is already set.\n", hash_table->hashing(value));
    }
}

void remove_value_hash_table (struct hash_table* hash_table, double value) {
    if (check_value_hash_table(hash_table, value)==1) {
        hash_table->table[(hash_table->hashing(value))].set = false ;
    }
}

void print_hash_table (struct hash_table* hash_table) {
    printf("\nHASH TABLE :\n") ;
    for (int i=0 ; i<SIZE_HASH_TABLE ; i++) {
        if (hash_table->table[i].set == true) {
            printf("Key %d = Value %lf\n", i, hash_table->table[i].value) ;
        }
    }
}

void clear_hash_table (struct hash_table* hash_table) {
    // empty fonction
}
