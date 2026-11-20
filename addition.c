#include "apc.h"
#include <stdlib.h>

/* Addition */
int addition(Dlist *tail1, Dlist *tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int carry = 0;
    int sum;
    int digit;

    while(temp1 != NULL || temp2 != NULL || carry != 0)
    {
        sum = carry;

        if(temp1 != NULL)
        {
            sum = sum + temp1->data;
            temp1 = temp1->prev;
        }

        if(temp2 != NULL)
        {
            sum = sum + temp2->data;
            temp2 = temp2->prev;
        }

        digit = sum % 10;
        carry = sum / 10;

        if(insert_first(headR, tailR, digit) == FAILURE)
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}