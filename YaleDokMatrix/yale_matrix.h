#include <stdio.h>

#define NUL (struct yale_matrix*)0

struct yale_matrix {
    int nb_columns ;
    int nb_lines ;
    int nb_elem ;
    double *V ;
    int *I ;
    int *J ;
} ;

void init_yale_from_dok_matrix (struct yale_matrix*, struct dok_matrix*) ;

void afficher_yale_matrix (struct yale_matrix*) ;

void clear_yale_matrix (struct yale_matrix*) ;
