#include <stdio.h>
#include "bst_matrix.h"

#define NUL (struct yale_matrix*)0

struct yale_matrix {
    int nb_columns ;
    int nb_rows ;
    int nb_elem ;
    double *Values ;
    int *I ;
    int *J ;
} ;

void init_yale_from_bst_matrix (struct yale_matrix*, struct bst_matrix*) ;

void print_yale_matrix (struct yale_matrix*) ;

void clear_yale_matrix (struct yale_matrix*) ;
