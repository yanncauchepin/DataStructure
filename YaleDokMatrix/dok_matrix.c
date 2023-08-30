#include <stdio.h>
#include "dok_matrix.h"

bool first_is_right (int ix, int jx, int iy, int jy) {
    return (ix>iy || (ix==iy && jx>jy) ) ;
}

static struct dok_matrix *new_value (int i, int j, double value) {
    struct dok_matrix* X;
    X = malloc (sizeof (struct dok_matrix));
    X->value = value;
    X->i = i ;
    X->j = j ;
    X->right = NIL ;
    X->left = NIL;
    return X ;
}

struct dok_matrix* ajouter_dok_matrix (struct dok_matrix* D, int i, int j, double d) {
    if (D==NIL)
        return new_value(i, j, d) ;
    else {
        if (i == D->i && j == D->j) {
            D->value = d ;
            printf("Changement de la valeur aux coordonnees (%d, %d)\n", i, j) ;
        }
        else if (first_is_right(i, j, D->i, D->j))
            D->right = ajouter_dok_matrix(D->right, i, j, d) ;
        else
            D->left = ajouter_dok_matrix(D->left, i, j, d) ;
        return D ;
    }
}

void afficher_dok_matrix (struct dok_matrix* D) {
      if (D!=NIL) {
          afficher_dok_matrix(D->left) ;
          printf("(%d, %d) : %lf\n", D->i, D->j, D->value) ;
          afficher_dok_matrix(D->right) ;
      }
}

double get_value (struct dok_matrix* D, int i , int j) {
      if (D!=NIL) {
          if (D->i == i && D->j == j)
              return D-> value ;
          else if (first_is_right(i, j, D->i, D->j))
              return get_value(D->right, i, j) ;
          else
              return get_value(D->left, i, j) ;
      }
      else
          return -1 ;
}

void get_size_matrix (struct dok_matrix *D, int *line_max, int *column_max, int* nb_elem) {
    if (D!=NIL) {
        *nb_elem += 1 ;
        if (D->i > *line_max)
            *line_max = D->i ;
        if (D->j > *column_max)
            *column_max = D->j  ;
        get_size_matrix (D->left, line_max, column_max, nb_elem) ;
        get_size_matrix (D->right, line_max, column_max, nb_elem) ;
    }
}

void clear_dok_matrix (struct dok_matrix* D) {
      if (D != NIL) {
          clear_dok_matrix(D->right) ;
          clear_dok_matrix(D->left) ;
          free(D) ;
      }
}
