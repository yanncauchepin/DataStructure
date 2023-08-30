#include <stdio.h>
#include "dok_matrix.h"
#include "yale_matrix.h"

int main () {
    struct dok_matrix *D;
    int i, j ;
    double value ;
    D = NIL ;
    scanf("%d", &i) ;
    scanf("%d", &j) ;
    while (i>=0 && j >=0) {
        scanf("%lf", &value) ;
        D = ajouter_dok_matrix(D, i, j, value) ;
        afficher_dok_matrix(D) ;
        scanf("%d", &i) ;
        scanf("%d", &j) ;
    }
    struct yale_matrix *Y ;
    init_yale_from_dok_matrix(Y, D) ;
    clear_dok_matrix(D) ;
    afficher_yale_matrix(Y) ;
    clear_yale_matrix(Y) ;
    return 0 ;
}
