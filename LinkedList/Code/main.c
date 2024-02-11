/* main.c */
#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"

int main () {
    struct list list ;
    init_list (&list);
    double value ;
    printf("List a sequence of float ending with 0 :\n") ;
    scanf ("%lf", &value);
    while (value != 0) {
        add_to_head_list (&list, value);
        scanf("%lf", &value);
        }
    printf("\nList of values in linked list :\n") ;
    print_list(&list) ;
    printf("\n");
    clear_list (&list) ;
    return 0 ;
}
