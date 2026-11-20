
#include "apc.h"
#include <stdlib.h>

/* Compare two numbers */
static int compare_numbers(Dlist *head1, Dlist *head2)
{
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;
    int len1 = 0, len2 = 0;

    /* Skip leading zeros */
    while(temp1 != NULL && temp1->data == 0 &&
          temp1->next != NULL)
    {
        temp1 = temp1->next;
    }

    while(temp2 != NULL && temp2->data == 0 &&
          temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    /* Count digits */
    while(temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    if(len1 > len2)
        return 1;

    if(len1 < len2)
        return -1;

    /* Compare digits from left to right */
    temp1 = head1;
    temp2 = head2;

    while(temp1 != NULL && temp1->data == 0 &&
          temp1->next != NULL)
    {
        temp1 = temp1->next;
    }

    while(temp2 != NULL && temp2->data == 0 &&
          temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data > temp2->data)
            return 1;

        if(temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;
}

/* Subtraction */
int subtraction(Dlist *head1, Dlist *tail1,
                Dlist *head2, Dlist *tail2,
                Dlist **headR, Dlist **tailR,
                int *negative)
{
    Dlist *temp1;
    Dlist *temp2;
    Dlist *temp;

    int digit1, digit2;
    int diff;
    int borrow = 0;
    int cmp;

    /* Compare operands */
    cmp = compare_numbers(head1, head2);

    /* Equal operands */
    if(cmp == 0)
    {
        *negative = 0;
        return insert_first(headR, tailR, 0);
    }

    /* Select larger magnitude */
    if(cmp < 0)
    {
        temp1 = tail2;
        temp2 = tail1;
        *negative = 1;
    }
    else
    {
        temp1 = tail1;
        temp2 = tail2;
        *negative = 0;
    }

    /* Subtract from right to left */
    while(temp1 != NULL || temp2 != NULL)
    {
        digit1 = 0;
        digit2 = 0;

        if(temp1 != NULL)
        {
            digit1 = temp1->data;
            temp1 = temp1->prev;
        }

        if(temp2 != NULL)
        {
            digit2 = temp2->data;
            temp2 = temp2->prev;
        }

        /* Apply previous borrow */
        digit1 = digit1 - borrow;

        if(digit1 < digit2)
        {
            digit1 = digit1 + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        diff = digit1 - digit2;

        if(insert_first(headR, tailR, diff) == FAILURE)
        {
            return FAILURE;
        }
    }

    /* Remove leading zeros */
    while(*headR != NULL &&
          (*headR)->data == 0 &&
          *headR != *tailR)
    {
        temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }

    return SUCCESS;
}
