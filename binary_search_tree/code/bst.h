// bst.h

#if ! defined (BST_H)
#define BST_H 1

#include <stdbool.h>

#define NIL (struct bst*)0

struct bst {
    struct bst* left ;
    double value ;
    struct bst* right ;
} ;

struct bst* add_bst (struct bst*, double) ;

bool research_bst (struct bst*, double) ;

int number_nodes_bst (struct bst*) ;

int height_bst (struct bst*) ;

void print_bst (struct bst*) ;

void print_indented_bst (struct bst*, int) ;

void clear_bst (struct bst*) ;

#endif
