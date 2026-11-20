
#include "apc.h"
#include <stdlib.h>

int multiplication(Dlist *head1, Dlist *tail1,
                   Dlist *head2, Dlist *tail2,
                   Dlist **headR, Dlist **tailR)
{
    Dlist *temp1;
    Dlist *temp2;
    Dlist *resultPos;
    Dlist *shift;
    Dlist *temp;

    int len1 = 0;
    int len2 = 0;
    int product;
    int carry;
    int sum;
    int i;

    /* Count digits in first number */
    temp1 = head1;
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    /* Count digits in second number */
    temp2 = head2;
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    /* Create result list with zeros */
    for (i = 0; i < len1 + len2; i++)
    {
        if (insert_last(headR, tailR, 0) == FAILURE)
            return FAILURE;
    }

    /* Start from the last digit of the second number */
    temp2 = tail2;
    shift = *tailR;

    while (temp2 != NULL)
    {
        temp1 = tail1;
        resultPos = shift;
        carry = 0;

        /* Multiply digit by digit */
        while (temp1 != NULL && resultPos != NULL)
        {
            product = (temp1->data * temp2->data)
                      + resultPos->data + carry;

            resultPos->data = product % 10;
            carry = product / 10;

            temp1 = temp1->prev;
            resultPos = resultPos->prev;
        }

        /* Process remaining carry */
        while (carry != 0 && resultPos != NULL)
        {
            sum = resultPos->data + carry;

            resultPos->data = sum % 10;
            carry = sum / 10;

            resultPos = resultPos->prev;
        }

        /* Move to the next digit */
        temp2 = temp2->prev;

        /* Shift one position left */
        if (temp2 != NULL)
            shift = shift->prev;
    }

    /* Remove leading zeros */
    while (*headR != NULL &&
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
