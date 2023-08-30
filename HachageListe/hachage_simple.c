#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hachage_simple.h"

void init_table (struct table* A, fonction_hachage* fonct) {
    for (int i=0; i<N; i++)
        init_liste (&(A->tab[i].L)) ;
    A->hash = fonct ;
}

void clear_table(struct table* A) {
    for(int i=0; i<N; i++)
        clear_liste (&(A->tab[i].L)) ;
}

void enregistrer_table (struct table* A, double d) {
    ajout_en_tete_liste (&(A->tab[(A->hash(d))].L), d) ;
}

int rechercher_table (struct table* A, double d) {
    return recherche_liste ( &(A->tab[(A->hash(d))].L), d) ;
}

void imprimer_table (struct table*A) {
    printf("\n TABLE DE HACHAGE \n") ;
    for (int i=0;i<N;i++) {
        if (A->tab[i].L.nbelem!=0) {
            printf("%d :\t", i) ;
            imprimer_liste (&(A->tab[i].L)) ;
            printf("\n") ;
        }
    }
}
