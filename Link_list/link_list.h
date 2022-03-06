#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_LINK_LIST_H
#define PROJECT_LINK_LIST_H

struct SingleNode{
    int data;
    struct SingleNode *next;
};

typedef struct SLinkList
{
    struct SingleNode *head;
    struct SingleNode *tail;
} ForwardList;

ForwardList *list_new();
void list_clear(ForwardList *flist);
int list_size(ForwardList *flist);
bool list_empty(ForwardList *flist);
void list_push_front(ForwardList *flist, int value);
void list_print_debug(ForwardList *flist);
int list_front(ForwardList *flist);
int list_back(ForwardList *flist);
void list_pop_front(ForwardList *flist);
void list_pop_end(ForwardList *flist);
void list_append(ForwardList *flist, int value);
void list_insert(ForwardList *flist, int index, int value);
int list_index(ForwardList *flist, int index);
void list_delet_node(ForwardList *flist, int index);
int list_value_n_from_end(ForwardList *flist, int n);
void list_reverse(ForwardList *flist);
void list_remove(ForwardList *flist, int value);
void check_address(void *p);


#endif // PROJECT_LINK_LIST_H
