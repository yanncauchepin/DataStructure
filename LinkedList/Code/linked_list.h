// liste.h

#if ! defined (LINKED_LIST_H)
#define LINKED_LIST_H 1

struct node {
    double ref;
    struct node* next;
};

#define NIL (struct node*)0

struct list {
    struct node* head;
    struct node* tail;
    int nbelem;
};

extern void init_list (struct list*);

extern void add_to_head_list (struct list*, double);

extern void add_sorted_list (struct list*, double) ;

extern void add_to_tail_list (struct list*, double);

extern int search_in_list (struct list*, double) ;

extern void print_list (struct list*);

extern void clear_list (struct list*);

#endif
