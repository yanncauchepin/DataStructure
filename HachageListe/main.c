/* main.c */
#include <stdio.h>
#include <stdbool.h>
#include "hachage_simple.h"

int hachage_basique (double d) {
    return (int)d % N;
}

int main () {
    struct table T ;
    double x ;
    init_table (&T, &hachage_basique);
    printf("Saisissez des flottants : (-1 pour signaler fin de saisie) :\n") ;
    scanf ("%lf", &x);
    while (x != -1) {
        enregistrer_table (&T, x);
        imprimer_table (&T);
        scanf ("%lf", &x);
    }
    printf("Indiquer une valeur à rechercher :\n") ;
    scanf("%lf",&x) ;
    if(rechercher_table(&T, x)==1)
        printf("La valeur est présente dans la table\n") ;
    else
        printf("La valeur n'est pas présente dans la table\n") ;
    clear_table (&T) ;
    return 0 ;
}
