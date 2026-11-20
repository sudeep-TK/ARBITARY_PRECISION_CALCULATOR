#ifndef COMMON_H
#define COMMON_H

//double linked list
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Dlist;
#endif
