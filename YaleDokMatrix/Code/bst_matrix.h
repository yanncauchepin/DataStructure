#if ! defined (BST_MATRIX_H)
#define BST_MATRIX_H 1

#include <stdbool.h>
#include <stdlib.h>

#define NIL (struct bst_matrix*) 0

struct bst_matrix {
    struct bst_matrix *left ;
    int i ;
    int j ;
    double value ;
    struct bst_matrix *right ;
} ;

bool first_is_left (int, int, int, int) ;

struct bst_matrix* add_value_bst_matrix (struct bst_matrix*, int, int, double) ;

double get_value_bst_matrix (struct bst_matrix*, int, int) ;

void get_size_bst_matrix (struct bst_matrix*, int*, int*, int*) ;

void print_bst_matrix (struct bst_matrix*) ;

void clear_bst_matrix (struct bst_matrix*) ;

#endif
