//abr.h

#include <stdbool.h>

#define NIL (struct abr*)0

struct abr {
    struct abr* gauche ;
    int valeur ;
    struct abr* droite ;
} ;

struct abr* ajouter_abr (struct abr*, int) ;

// ajoute une valeur et retourne struct abr*

void afficher_abr (struct abr*) ;

// affiche les valeurs dans l'odre croissant

void clear_abr (struct abr*) ;

// efface complétement l'arbre

bool recherche (struct abr*, int) ;

// indique si la valeur x est dans l'arbre

void affichage_dot (struct abr*) ;

// affiche le graphique de l'arbre

int nombre_noeuds_abr (struct abr*) ;

// indique le nombre de noeuds présent dans l'arbre

int hauteur_abr (struct abr*) ;

// indique la hauteur de l'arbre

void afficher_indente (struct abr*, int) ;

// affiche les noeuds de l'arbre avec leurs hauteurs respectivent
// necessite d'indiquer la profondeur, nulle par defaut
