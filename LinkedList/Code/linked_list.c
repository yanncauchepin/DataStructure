// linked_list.c

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void init_list (struct list* list) {
    list->nbelem = 0;
    list->head = NIL;
    list->tail = NIL;
}

void add_to_head_list (struct list* list, double value) {
    struct node* node = (struct node*) malloc (sizeof (struct node));
    node->ref = value;
    node->next = list->head;
    list->nbelem += 1;
    list->head = node;
    // Case of first insert
    if (list->tail == NIL)
        list->tail = node;
}

void add_sorted_list  (struct list* list, double value) {
    struct node *node_succ, *node_pred;
    node_succ = list->head;
    node_pred = node_succ ;
    while ((node_succ != NIL) && (node_succ->ref<value)) {
        node_pred=node_succ ;
        node_succ=node_succ->next ;
    }
    struct node* node_insert;
    node_insert = (struct node*) malloc (sizeof (struct node));
    node_insert->ref = value;
    node_insert->next = node_succ ;
    if (node_pred != NIL)
        node_pred->next = node_insert ;
    else
        list->head= node_insert ;
    list->nbelem += 1;
    // Case of adding at the end of the list
    if (node_succ == NIL)
        list->tail = node_insert;
}

void add_to_tail_list (struct list* list, double value) {
    struct node *node_insert, *node_pred;
    node_insert = (struct node*) malloc (sizeof (struct node));
    node_insert->ref = value;
    node_insert->next = NIL;
    if (list->nbelem == 0) {
        list->head = node_insert;
        list->tail = node_insert;
    } else {
        node_pred = list->tail;
        node_pred->next = node_insert;
        list->tail = node_insert;
    }
    list->nbelem += 1;
}

int search_in_list (struct list* list, double value) {
    struct node *node ;
    node = list->head;
    while ((node != NIL) && (node->ref!=value)) {
        node = node->next;
    }
    return (node != NIL && node->ref == value);
}

void print_list (struct list* list) {
    struct node* node;
    printf ("[ ");
    node = list->head;
    while (node != NIL) {
        printf ("%lf ", node->ref);
        node = node->next;
    }
    printf ("]");
}

void clear_list (struct list* list) {
    struct node *node_pred, *node_succ;
    node_pred = list->head;
    while (node_pred != NIL) {
        node_succ = node_pred->next;
        free(node_pred);
        node_pred = node_succ;
    }
}
