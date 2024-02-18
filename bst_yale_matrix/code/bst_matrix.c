#include <stdio.h>
#include "bst_matrix.h"

bool first_is_left (int i_insert, int j_insert, int i_matrix, int j_matrix) {
    return (i_insert<i_matrix || (i_insert==i_matrix && j_insert<j_matrix) ) ;
}

static struct bst_matrix *new_node (int i, int j, double value) {
    struct bst_matrix* node;
    node = malloc (sizeof (struct bst_matrix));
    node->value = value;
    node->i = i ;
    node->j = j ;
    node->right = NIL ;
    node->left = NIL;
    return node ;
}

struct bst_matrix* add_value_bst_matrix (struct bst_matrix* bst_matrix, int i, int j, double value) {
    if (bst_matrix==NIL) {
        return new_node(i, j, value) ;
    } else {
        if (i == bst_matrix->i && j == bst_matrix->j) {
            bst_matrix->value = value ;
            printf("Udpate value of BST matrix in coordinates (%d, %d)\n", i, j) ;
        } else if (first_is_left(i, j, bst_matrix->i, bst_matrix->j)) {
            bst_matrix->left = add_value_bst_matrix(bst_matrix->left, i, j, value) ;
        } else {
            bst_matrix->right = add_value_bst_matrix(bst_matrix->right, i, j, value) ;
        }
        return bst_matrix ;
    }
}

double get_value_bst_matrix (struct bst_matrix* bst_matrix, int i , int j) {
      if (bst_matrix!=NIL) {
          if (bst_matrix->i == i && bst_matrix->j == j)
              return bst_matrix->value ;
          else if (first_is_left(i, j, bst_matrix->i, bst_matrix->j))
              return get_value_bst_matrix(bst_matrix->left, i, j) ;
          else
              return get_value_bst_matrix(bst_matrix->right, i, j) ;
      } else {
          return -1 ;
      }
}

void get_size_bst_matrix (struct bst_matrix *bst_matrix, int *max_row, int *max_column, int* nb_elem) {
    if (bst_matrix!=NIL) {
        *nb_elem += 1 ;
        if (bst_matrix->i > *max_row)
            *max_row = bst_matrix->i ;
        if (bst_matrix->j > *max_column)
            *max_column = bst_matrix->j  ;
        get_size_bst_matrix (bst_matrix->left, max_row, max_column, nb_elem) ;
        get_size_bst_matrix (bst_matrix->right, max_row, max_column, nb_elem) ;
    }
}

void print_bst_matrix (struct bst_matrix* bst_matrix) {
      if (bst_matrix!=NIL) {
          print_bst_matrix(bst_matrix->left) ;
          printf("(%d, %d) : %lf\n", bst_matrix->i, bst_matrix->j, bst_matrix->value) ;
          print_bst_matrix(bst_matrix->right) ;
      }
}

void clear_bst_matrix (struct bst_matrix* bst_matrix) {
      if (bst_matrix != NIL) {
          clear_bst_matrix(bst_matrix->left) ;
          clear_bst_matrix(bst_matrix->right) ;
          free(bst_matrix) ;
      }
}
