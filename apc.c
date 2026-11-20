#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

/* Insert at last */
int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode;

    newnode = malloc(sizeof(Dlist));

    if(newnode == NULL)
    {
        return FAILURE;
    }

    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
        return SUCCESS;
    }

    newnode->prev = *tail;
    (*tail)->next = newnode;
    *tail = newnode;

    return SUCCESS;
}

/* Insert at first */
int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode;

    newnode = malloc(sizeof(Dlist));

    if(newnode == NULL)
    {
        return FAILURE;
    }

    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
        return SUCCESS;
    }

    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;

    return SUCCESS;
}

/* Display DLL */
int display(Dlist *head, Dlist *tail)
{
    Dlist *temp = head;

    if(temp == NULL)
    {
        return FAILURE;
    }

    printf("NULL->");

    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return SUCCESS;
}

/* Validate operand */
int valid_operand(char *str)
{
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}

/* Convert string to DLL */
int digit_to_list(char *str, Dlist **head, Dlist **tail)
{
    int i = 0;
    int digit;

    while(str[i] != '\0')
    {
        digit = str[i] - '0';

        if(insert_last(head, tail, digit) == FAILURE)
        {
            return FAILURE;
        }

        i++;
    }

    return SUCCESS;
}