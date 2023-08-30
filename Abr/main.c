#include "abr.h"
#include <stdio.h>

int main () {
    struct abr* racine;
    int x;
    racine = NIL;
    printf("Lister une suite d'entiers se terminant par -1 :\n") ;
    scanf ("%d", &x);
    while (x != -1) {
        racine = ajouter_abr (racine, x);
        afficher_abr (racine);
        scanf ("%d", &x);
        }
    clear_abr (racine);

    return 0;
}
