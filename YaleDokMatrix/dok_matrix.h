#include <stdbool.h>
#include <stdlib.h>

#define NIL (struct dok_matrix*) 0

struct dok_matrix {
    struct dok_matrix *left ;
    int i ;
    int j ;
    double value ;
    struct dok_matrix *right ;
} ;

bool first_is_right (int, int, int, int) ;

struct dok_matrix* ajouter_dok_matrix (struct dok_matrix*, int, int, double) ;

void afficher_dok_matrix (struct dok_matrix*) ;

double get_value (struct dok_matrix*, int, int) ;

void clear_dok_matrix (struct dok_matrix*) ;

void get_size_matrix (struct dok_matrix*, int*, int*, int*) ;
