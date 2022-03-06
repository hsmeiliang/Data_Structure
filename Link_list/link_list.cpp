#include "link_list.h"

ForwardList *list_new()
{
    ForwardList *flist = (ForwardList *) malloc(sizeof(ForwardList));
    check_address(flist);

    flist->head = 0;
    flist->tail = 0;

    return flist;
}

void list_clear(ForwardList *flist)
{
    struct SingleNode *current = flist->head;
    struct SingleNode *next;

    while(current != 0)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(flist);
}

int list_size(ForwardList *flist)
{
    int size = 0;
    struct SingleNode *current = flist->head;
    while(current != 0)
    {
        size++;
        current = current->next;
    }
    return size;
}

bool list_empty(ForwardList *flist)
{
    return flist->head == 0;
}

void list_push_front(ForwardList *flist, int value)
{
    struct SingleNode *head = flist->head;
    struct SingleNode *node = (struct SingleNode *)malloc(sizeof(struct SingleNode));
    check_address(node);

    node->data = value;
    node->next = head;
    flist->head = node;

    if(flist->tail == 0) //insert node is first node
    {
        flist->tail = node;
    }
}

void list_print_debug(ForwardList *flist)
{
    struct SingleNode *current = flist->head;
    printf("head: %p\n", flist->head);
    printf("tail: %p\n", flist->tail);

    printf("link list:\n");
    while(current != 0)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n\n");
}

int list_front(ForwardList *flist)
{
    if(list_empty(flist))
    {
        printf("empty");
        exit(EXIT_FAILURE);
    }
    return flist->head->data;
}

int list_back(ForwardList *flist)
{
    if(list_empty(flist))
    {
        printf("empty");
        exit(EXIT_FAILURE);
    }
    return flist->tail->data;
}

void list_pop_front(ForwardList *flist)
{
    if(list_empty(flist))
    {
        printf("empty");
        exit(EXIT_FAILURE);
    }

    struct SingleNode *temp = flist->head;
    flist->head = flist->head->next;

    if(flist->tail == temp)
        flist->tail = flist->head;

    free(temp);
}

void list_append(ForwardList *flist, int value)
{
    struct SingleNode *node = (struct SingleNode *)malloc(sizeof(struct SingleNode));
    check_address(node);

    node->data = value;
    node->next = 0;
    if(list_empty(flist))
    {
        flist->head = node;
        flist->tail = node;
    }
    else
    {
        flist->tail->next = node;
        flist->tail = node;
    }

}

void list_pop_end(ForwardList *flist)
{
    if(flist->tail == 0)
    {
        printf("empty");
        exit(EXIT_FAILURE);
    }

    if(flist->head == flist->tail)
    {
        free(flist->head);
        flist->head = 0;
        flist->tail = 0;
    }
    else
    {
        struct SingleNode *current = flist->head;
        struct SingleNode *before = flist->head;

        while(current != flist->tail)
        {
            before = current;
            current = current->next;
        }
        free(current);
        before->next = 0;
        flist->tail = before;

    }
}

void list_insert(ForwardList *flist, int index, int value)
{
    struct SingleNode *current = flist->head;
    struct SingleNode *before = flist->head;
    struct SingleNode *node = (struct SingleNode *)malloc(sizeof(struct SingleNode));
    check_address(node);
    node->data = value;

    int count = 0;
    while(index > count && current != 0)
    {
        count++;
        before = current;
        current = current->next;
    }

    if(count < index)
    {
        free(node);
        printf("out of range\n");
        exit(EXIT_FAILURE);
    }

    if(index == 0 && flist->head == 0)
    {
        node->next = 0;
        flist->head = node;
        flist->tail = node;
    }
    else if(index == 0)
    {
        node->next = flist->head;
        flist->head = node;
    }
    else if(current == flist->tail)
    {
        node->next = current;
        before->next = node;
    }
    else if(current == 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        node->next = before->next;
        before->next = node;
    }
}

int list_index(ForwardList *flist, int index)
{
    struct SingleNode *current = flist->head;

    int count = 0;
    while(index > count && current != 0)
    {
        count++;
        current = current->next;
    }

    if(count < index || current == 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    return current->data;
}

void list_delet_node(ForwardList *flist, int index)
{
    if(list_empty(flist))
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    struct SingleNode *current = flist->head;
    struct SingleNode *before = flist->head;

    int count = 0;
    while(index > count && current != 0)
    {
        count++;
        before = current;
        current = current->next;
    }

    if(count < index)
    {
        printf("out of range\n");
        exit(EXIT_FAILURE);
    }

    if(index == 0)
    {
        flist->head = flist->head->next;
        if(flist->tail == current)
        {
            flist->tail = flist->head;
        }
    }
    else
    {
        before->next = current->next;
        if(flist->tail == current)
            flist->tail = before;
    }
    free(current);
}

int list_value_n_from_end(ForwardList *flist, int n)
{
    struct SingleNode *first = flist->head;
    struct SingleNode *match = flist->head;

    for(int i = 0; i <n ; i++)
    {
        if(first)
        {
            first = first->next;
        }
        else
        {
            printf("out of range\n");
            exit(EXIT_FAILURE);
        }
    }
    while(first)
    {
        first = first->next;
        match = match->next;
    }
    return match->data;
}

void list_reverse(ForwardList *flist)
{
    struct SingleNode *pre = NULL;
    struct SingleNode *current = flist->head;
    struct SingleNode *next;

    flist->tail = flist->head;

    while(current)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    flist->head = pre;
}

void list_remove(ForwardList *flist, int value)
{
    struct SingleNode *current = flist->head;
    struct SingleNode *pre = NULL;

    while(current)
    {
        if(current->data == value)
        {
            if(pre)
            {
                pre->next = current->next;
                flist->tail = current == flist->tail ? pre : flist->tail;
            }
            else
            {
                flist->head = current->next;
                flist->tail = current == flist->tail ? NULL : flist->tail;
            }
            free(current);
            break;
        }
        pre = current;
        current = current->next;
    }
}

void check_address(void *p)
{
    if(p == NULL)
    {
        printf("error mem\n");
        exit(EXIT_FAILURE);
    }
}

