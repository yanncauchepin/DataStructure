// liste.c

#include <stdio.h>
#include <stdlib.h>
#include "liste_double.h"

// Constructeur. L est passé en mode R.

void init_liste (struct liste* L)
{
    L->nbelem = 0;
    L->tete = NIL;
    L->queue = NIL; // nouveau
}

// L passé en mode DR ; d en mode D.

void ajout_en_tete_liste (struct liste* L, double d)
{   struct maillon* M;

// 1.
    M = (struct maillon*)malloc (sizeof (struct maillon));
// 2.
    M->valeur = d;
    M->suivant = L->tete;
// 3.
    L->nbelem += 1;
    L->tete = M;

    if (L->queue == NIL)    // nouveau
        L->queue = M;       // nouveau
}

void ajout_en_queue_liste (struct liste* L, double d)
{   struct maillon* M;
    struct maillon* N;

// 1.
    M = (struct maillon*)malloc (sizeof (struct maillon));
    M->valeur = d;
    M->suivant = NIL;
    if (L->nbelem == 0)
    {
        L->tete = M;
        L->queue = M;       // nouveau
    } else
    {
// 2.
/*
 * Ancien code, sans pointeur de queue
        N = L->tete;
        while (N->suivant != NIL)
            N = N->suivant;
 */
        N = L->queue;       // nouveau (décommenter le code ci-dessus)
/*
 *    for (int i = 0; i < L->nbelem-1; i++)
 *        N = N->suivant;
 */
// 3.
        N->suivant = M;
        L->queue = M;       // nouveau
    }
// 4.
    L->nbelem += 1;
}

void clear_liste (struct liste* L)
{   struct maillon *M, *S;

    M = L->tete;
    while (M != NIL)
    {   S = M->suivant;
        free (M);
        M = S;
    }
}

void imprimer_liste (struct liste* L)
{   struct maillon* M;

    printf ("[");
/* 1ère version de la boucle
 *  M = L->tete;
 *  for (int i = 0; i < L->nbelem; i++)
 *  {   printf ("%lf, ", M->valeur);
 *      M = M->suivant;
 *  }
 */
// 2ème version de la boucle
    M = L->tete;
    while (M != NIL)
    {   printf ("%lf, ", M->valeur);
        M = M->suivant;
    }
/* 3ème version de la boucle
 *  for (M = L->tete; M != NIL; M = M->suivant)
 *      printf ("%lf, ", M->valeur);
 */
    printf ("]\n");
}

int recherche_liste (struct liste* L, double d) {
    struct maillon *M ;
    M = L->tete;
    while ((M != NIL) && (M->valeur!=d))
        M=M->suivant ;
    if (M->valeur==d)
        return 1 ;
    else
        return 0 ;
}
