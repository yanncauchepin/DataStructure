/* simple_hashing.h */

#if ! defined (SIMPLE_HASHING_H)
#define SIMPLE_HASHING_H 1

#include <stdbool.h>

typedef int hashing_function (double);

#define SIZE_HASH_TABLE 100

struct cell {
    bool set ;
    double value ;
};

struct hash_table {
    struct cell table [SIZE_HASH_TABLE];
    hashing_function* hashing;
};

extern void init_hash_table (struct hash_table*, hashing_function*);

extern int check_value_hash_table (struct hash_table*, double);

extern void add_value_hash_table (struct hash_table*, double);

extern void remove_value_hash_table (struct hash_table*, double);

extern void print_hash_table (struct hash_table*);

extern void clear_hash_table (struct hash_table*);

#endif
