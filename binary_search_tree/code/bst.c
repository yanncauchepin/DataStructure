// bst.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

static struct bst* new_node (double value) {
    struct bst* node;
    node = malloc (sizeof (struct bst));
    node->value = value;
    node->right = NIL ;
    node->left = NIL;
    return node;
}

struct bst* add_bst (struct bst* bst, double value) {
    if (bst == NIL)
        return new_node (value);
    else {
        if (bst->value > value)
            bst->left = add_bst (bst->left, value);
        else
            bst->right = add_bst (bst->right, value);
        return bst;
    }
}

bool research_bst (struct bst* bst, double value) {
    if (bst==NIL)
      return false ;
    else if (bst->value==value)
      return true ;
    else {
        if (bst->value > value)
            research_bst (bst->left, value);
        else
            research_bst (bst->right, value);
    }
}

int number_nodes_bst (struct bst* bst) {
    if (bst == NIL)
      return 0 ;
    else
        return (1 + number_nodes_bst(bst->left) +number_nodes_bst(bst->right)) ;
}

int height_bst (struct bst* bst) {
    if (bst == NIL)
      return 0 ;
    else if ((bst->left==NIL) && (bst->right==NIL))
      return 0 ;
    else {
        if (height_bst(bst->left) > height_bst(bst->right))
            return height_bst(bst->left) + 1 ;
        else
            return height_bst(bst->right) +1 ;
    }
}

void print_bst (struct bst* bst) {
    if (bst != NIL) {
        print_bst(bst->left) ;
        printf("%lf  ", bst->value) ;
        print_bst(bst->right) ;
    }
}

void print_indented_bst (struct bst* bst, int deep) {
    if (bst != NIL) {
        print_indented_bst(bst->left, deep+1) ;
        for (int i=0 ; i<deep ; i++)
            printf("\t") ;
        printf("%lf\n", bst->value) ;
        print_indented_bst(bst->right, deep+1) ;
    }
}

void clear_bst (struct bst* bst) {
    if (bst != NIL) {
        clear_bst(bst->left) ;
        clear_bst(bst->right) ;
        free(bst) ;
    }
}
