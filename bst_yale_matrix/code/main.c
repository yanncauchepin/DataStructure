#include <stdio.h>
#include "bst_matrix.h"
#include "yale_matrix.h"

int main () {
    struct bst_matrix *bst_matrix = NIL ;
    int i, j ;
    double value ;
    printf("Iteratively insert coordinates and corresponding value. Stop when at least one of the coordinates is negative.\n") ;
    printf("Row coordinate : ") ;
    scanf("%d", &i) ;
    printf("Column coordinate : ") ;
    scanf("%d", &j) ;
    while (i>=0 && j >=0) {
        printf("Value : ") ;
        scanf("%lf", &value) ;
        bst_matrix = add_value_bst_matrix(bst_matrix, i, j, value) ;
        printf("Row coordinate : ") ;
        scanf("%d", &i) ;
        printf("Column coordinate : ") ;
        scanf("%d", &j) ;
    }
    printf("\nDOK Matrix :\n") ;
    print_bst_matrix(bst_matrix) ;
    printf("\n") ;
    struct yale_matrix *yale_matrix ;
    init_yale_from_bst_matrix(yale_matrix, bst_matrix) ;
    clear_bst_matrix(bst_matrix) ;
    printf("\nYale Matrix :\n") ;
    print_yale_matrix(yale_matrix) ;
    printf("\n") ;
    clear_yale_matrix(yale_matrix) ;
    return 0 ;
}
