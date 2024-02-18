#include <stdio.h>
#include "yale_matrix.h"

static void get_yale_values_from_bst_matrix (struct yale_matrix* yale_matrix, struct bst_matrix* bst_matrix, int* elem, int* index) {
    if (bst_matrix!=NIL) {
        get_yale_values_from_bst_matrix(yale_matrix, bst_matrix->left, elem, index) ;
        yale_matrix->Values[*elem] = bst_matrix->value ;
        yale_matrix->J[*elem] = bst_matrix->j ;
        *elem = *elem + 1 ;
        *index = bst_matrix->i+1 ;
        yale_matrix->I[*index] = *elem ;
        get_yale_values_from_bst_matrix(yale_matrix, bst_matrix->right, elem, index) ;
    }
}

void init_yale_from_bst_matrix (struct yale_matrix* yale_matrix , struct bst_matrix* bst_matrix) {
    int max_row = 0 ;
    int max_column = 0 ;
    int nb_elem = 0 ;
    get_size_bst_matrix(bst_matrix, &max_row, &max_column, &nb_elem) ;
    yale_matrix->nb_rows = max_row + 1 ;
    yale_matrix->nb_columns = max_column + 1 ;
    yale_matrix->nb_elem = nb_elem ;
    yale_matrix->Values = (double*) malloc (yale_matrix->nb_elem*sizeof(double)) ;
    yale_matrix->J = (int*) malloc (yale_matrix->nb_elem*sizeof(int)) ;
    yale_matrix->I = (int*) malloc ((yale_matrix->nb_rows+1)*sizeof(int)) ;
    for (int i=0 ; i<=yale_matrix->nb_rows ; i++) {
        yale_matrix->I[i] = 0 ;
    }
    int elem = 0 ;
    int index = 0 ;
    get_yale_values_from_bst_matrix(yale_matrix, bst_matrix, &elem, &index) ;
    index = 0 ;
    while (index<=yale_matrix->nb_rows && yale_matrix->I[index] == 0) {
        index++ ;
    }
    int value = yale_matrix->I[index] ;
    while (index<=(yale_matrix->nb_rows)) {
        if (yale_matrix->I[index] == 0) {
            yale_matrix->I[index] = value ;

        } else {
            value = yale_matrix->I[index] ;
        }
        index++ ;
    }
}

void print_yale_matrix (struct yale_matrix* yale_matrix) {
    if (yale_matrix!=NUL) {
        printf("Size of matrix : %d x %d\n", yale_matrix->nb_rows, yale_matrix->nb_columns) ;
        printf("Contains %d elements\n", yale_matrix->nb_elem) ;
        printf("Y : [") ;
        for (int i=0 ; i<yale_matrix->nb_elem ; i++) {
            printf("%lf  ", yale_matrix->Values[i]) ;
        }
        printf("]\n") ;
        printf("J : [") ;
        for (int i=0 ; i<yale_matrix->nb_elem ; i++) {
            printf("%d  ", yale_matrix->J[i]) ;
        }
        printf("]\n") ;
        printf("I : [") ;
        for (int i=0 ; i<=yale_matrix->nb_rows ; i++) {
            printf("%d  ", yale_matrix->I[i]) ;
        }
        printf("]\n") ;
    }
}

void clear_yale_matrix (struct yale_matrix* yale_matrix) {
    free(yale_matrix->Values) ;
    free(yale_matrix->J) ;
    free(yale_matrix->I) ;
}
