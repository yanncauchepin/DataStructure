// liste.h

/*
 * Le type struct liste permet de représenter des listes chaînées
 * avec pointeur de queue.
 * - Le champ nbelem contient le nombre d'éléments (= le nombre de maillons)
 * - Le champ tete contient l'adresse du maillon de tete
 * - Le champ queue contient l'adresse du maillon de queue.
 * La liste vide est codée par tete = queue = NIL et nbelem = 0.
 * Les maillons sont alloués dynamiquement.
 * Le champ suivant du dernier maillon vaut NIL
 */

struct maillon {
    double valeur;
    struct maillon* suivant;
};

#define NIL (struct maillon*)0

struct liste {
    struct maillon* tete;
    struct maillon* queue;
    int nbelem;
};

extern void init_liste (struct liste*);

extern void clear_liste (struct liste*);

extern void ajout_en_tete_liste (struct liste*, double);

extern void ajout_en_queue_liste (struct liste*, double);

extern void imprimer_liste (struct liste*);

extern int recherche_liste (struct liste*, double) ;
