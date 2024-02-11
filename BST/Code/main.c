#include "bst.h"
#include <stdio.h>

int main () {
    struct bst* root = NIL ;
    double value ;
    printf("List a sequence of float ending with 0 :\n") ;
    scanf ("%lf", &value);
    while (value != 0) {
        root = add_bst (root, value);
        scanf("%lf", &value);
        }
    printf("\nList of ordered values in BST :\n") ;
    print_bst (root);
    printf("\n") ;
    clear_bst (root);
    return 0;
}
