#include <stdio.h>
//#include "yale_matrix.h"
#include "dok_matrix.h"

#define NUL (struct yale_matrix*)0

struct yale_matrix {
    int nb_columns ;
    int nb_lines ;
    int nb_elem ;
    double *V ;
    int *I ;
    int *J ;
} ;

static void get_yale_values_from_dok_matrix (struct yale_matrix*Y, struct dok_matrix*D, int*elem, int*indice) {
    if (D!=NIL) {
        get_yale_values_from_dok_matrix(Y, D->left, elem, indice) ;
        Y->V[*elem] = D->value ;
        Y->J[*elem] = D->j ;
        *elem = *elem + 1 ;
        *indice = D->i+1 ; // do not continue for i vide (i vide =0 au lieu d'incrementer)
        Y->I[*indice] = *elem ;
        get_yale_values_from_dok_matrix(Y, D->right, elem, indice) ;
    }
}

void init_yale_from_dok_matrix (struct yale_matrix*Y , struct dok_matrix*D) {
    int line_max = 0 ;
    int column_max = 0 ;
    int nb_elem = 0 ;
    get_size_matrix(D, &line_max, &column_max, &nb_elem) ;
    Y->nb_lines = line_max + 1 ;
    Y->nb_columns = column_max + 1 ;
    Y->nb_elem = nb_elem ;
    Y->V = (double*) malloc (  Y->nb_elem*sizeof(double)) ;
    Y->J = (int*) malloc (  Y->nb_elem*sizeof(int)) ;
    Y->I = (int*) malloc ((Y->nb_lines+1)*sizeof(int)) ;
    for (int line=0 ; line<=(Y->nb_lines) ; line++)
        Y->I[line] = 0 ;
    int elem = 0 ;
    int indice = 0 ;
    get_yale_values_from_dok_matrix(Y, D, &elem, &indice) ;
    indice = 0 ;
    while (indice<=(Y->nb_lines) && Y->I[indice] == 0)
        indice++ ;
    int value = Y->I[indice] ;
    while (indice<=(Y->nb_lines)) {
        if (Y->I[indice] == 0)
            Y->I[indice] = value ;
        else
            value = Y->I[indice] ;
        indice++ ;
    }
}

void afficher_yale_matrix (struct yale_matrix*Y) {
    if (Y!=NUL) {
        printf("Size of matrix : %d x %d\n", Y->nb_lines, Y->nb_columns) ;
        printf("Contains %d elements\n", Y->nb_elem) ;
        printf("Y : [") ;
        for (int elem=0 ; elem<(Y->nb_elem) ; elem++)
            printf("%lf   ", Y->V[elem]) ;
        printf("]\n") ;
        printf("J : [") ;
        for (int elem=0 ; elem<(Y->nb_elem) ; elem++)
            printf("%d   ", Y->J[elem]) ;
        printf("]\n") ;
        printf("I : [") ;
        for (int line=0 ; line<=(Y->nb_lines) ; line++)
            printf("%d   ", Y->I[line]) ;
        printf("]\n") ;
    }
}

void clear_yale_matrix (struct yale_matrix*Y) {
    free(Y->V) ;
    free(Y->J) ;
    free(Y->I) ;
}
