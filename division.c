
#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

/* Compare two positive numbers */
static int compare_division(Dlist *head1, Dlist *head2)
{
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;
    int len1 = 0;
    int len2 = 0;

    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    if (len1 > len2)
        return 1;

    if (len1 < len2)
        return -1;

    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
            return 1;

        if (temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;
}

/* Check whether a number is zero */
static int is_zero(Dlist *head)
{
    while (head != NULL)
    {
        if (head->data != 0)
            return 0;

        head = head->next;
    }

    return 1;
}

/* Free a linked list */
static void free_list(Dlist *head)
{
    Dlist *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* Remove leading zeros */
static void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while (*head != NULL &&
           (*head)->data == 0 &&
           *head != *tail)
    {
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

/* Division function */
int division(Dlist *head1, Dlist *tail1,
             Dlist *head2, Dlist *tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp;
    Dlist *remainderHead = NULL;
    Dlist *remainderTail = NULL;
    Dlist *newHead;
    Dlist *newTail;

    int quotientDigit;
    int negative = 0;

    (void)tail1;

    /* Check division by zero */
    if (is_zero(head2))
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    /* Process dividend digits from left to right */
    temp = head1;

    while (temp != NULL)
    {
        /* Bring down the next digit */
        if (insert_last(&remainderHead, &remainderTail,
                        temp->data) == FAILURE)
        {
            free_list(remainderHead);
            return FAILURE;
        }

        remove_leading_zeros(&remainderHead, &remainderTail);

        quotientDigit = 0;

        /* Repeatedly subtract the divisor */
        while (compare_division(remainderHead, head2) >= 0)
        {
            newHead = NULL;
            newTail = NULL;
            negative = 0;

            if (subtraction(remainderHead, remainderTail,
                            head2, tail2,
                            &newHead, &newTail,
                            &negative) == FAILURE)
            {
                free_list(remainderHead);
                return FAILURE;
            }

            /* Replace old remainder with new remainder */
            free_list(remainderHead);

            remainderHead = newHead;
            remainderTail = newTail;

            remove_leading_zeros(&remainderHead, &remainderTail);

            quotientDigit++;
        }

        /* Store the quotient digit */
        if (insert_last(headR, tailR, quotientDigit) == FAILURE)
        {
            free_list(remainderHead);
            return FAILURE;
        }

        temp = temp->next;
    }

    /* Remove leading zeros from quotient */
    remove_leading_zeros(headR, tailR);

    free_list(remainderHead);

    return SUCCESS;
}
