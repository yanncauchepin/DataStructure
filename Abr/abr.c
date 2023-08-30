// abr.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "abr.h"


void afficher_abr (struct abr* A) {
    if (A !=NIL) {
        afficher_abr(A->gauche) ;
        printf("%d  ", A->valeur) ;
        afficher_abr(A->droite) ;
    }
}

void clear_abr (struct abr* A) {
    if (A != NIL) {
        clear_abr(A->gauche) ;
        clear_abr(A->droite) ;
        free(A) ;
    }
}

bool recherche (struct abr*A, int x) {
    if (A==NIL)
      return false ;
    else if (A->valeur==x)
      return true ;
    else {
        if (A->valeur > x)
            recherche (A->gauche, x);
        else
            recherche (A->droite, x);
    }
}

static void affichage_dot_abr (struct abr*A, FILE* f) {
    if (A->gauche!=NIL) {
        struct abr* B ;
        B = A-> gauche ;
        fprintf(f, "%d -> %d [label=\"gauche\"];\n", A->valeur, B->valeur) ;
        affichage_dot_abr (A->gauche, f) ;
    }
    if (A->droite!=NIL) {
        affichage_dot_abr (A->droite, f) ;
        struct abr* B ;
        B = A-> droite ;
        fprintf(f, "%d -> %d [label=\"droit\"];\n", A->valeur, B->valeur) ;
    }
}

void affichage_dot (struct abr*A) {
    FILE * f ;
    f= fopen("ABR.dot", "w") ;
    assert (f!=NULL) ;
    fprintf(f,"digraph G{\n");
    if (A==NIL)
        fprintf(f,"  NIL ;\n") ;
    else if ((A->gauche==NIL) && (A->droite==NIL))
        fprintf(f, "%d;\n", A->valeur) ;
    else
        affichage_dot_abr (A, f) ;
    fprintf(f,"}\n") ;
    fclose(f) ;
    system("dot ABR.dot -o ABR.pdf") ;
    system("evince ABR.pdf") ;
}

int hauteur_abr (struct abr* A) {
    if (A == NIL)
      return 0 ;
    else if ((A->gauche==NIL) && (A->droite==NIL))
      return 0 ;
    else {
        if (hauteur_abr(A->gauche) > hauteur_abr(A->droite))
            return hauteur_abr(A->gauche) + 1 ;
        else
            return hauteur_abr(A->droite) +1 ;
    }
}

int nombre_noeuds_abr (struct abr*A) {
    if (A == NIL)
      return 0 ;
    else
        return (1 + nombre_noeuds_abr(A->gauche) + nombre_noeuds_abr(A->droite)) ;
}

void afficher_indente (struct abr* A, int prof) {
    if (A != NIL) {
        afficher_indente(A->gauche, prof+1) ;
        for (int i=0;i<prof;i++)
            printf("\t") ;
        printf("%d\n", A->valeur) ;
        afficher_indente(A->droite, prof+1) ;
    }
}

static struct abr* new_feuille (int value) {
    struct abr* A;
    A = malloc (sizeof (struct abr));
    A->valeur = value;
    A->gauche = NIL ;
    A->droite = NIL;
    return A;
}

struct abr* ajouter_abr (struct abr* A, int value) {
    if (A == NIL)
        return new_feuille (value);
    else {
        if (A->valeur > value)
            A->gauche = ajouter_abr (A->gauche, value);
        else
            A->droite = ajouter_abr (A->droite, value);
        return A;
    }
}
