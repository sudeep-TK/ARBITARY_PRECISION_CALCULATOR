#ifndef APC_H
#define APC_H

#include "common.h"

#define SUCCESS 1
#define FAILURE 0

/* Linked list functions */
int insert_last(Dlist **head, Dlist **tail, int data);
int insert_first(Dlist **head, Dlist **tail, int data);
int display(Dlist *head, Dlist *tail);

/* Operand validation */
int valid_operand(char *str);

/* Convert string to DLL */
int digit_to_list(char *str, Dlist **head, Dlist **tail);

/* Arithmetic operations */
int addition(Dlist *tail1, Dlist *tail2,
             Dlist **headR, Dlist **tailR);

/* Subtraction */
int subtraction(Dlist *head1, Dlist *tail1,
                Dlist *head2, Dlist *tail2,
                Dlist **headR, Dlist **tailR,
                int *negative);

//multiplication

int multiplication(Dlist *head1, Dlist *tail1,
                   Dlist *head2, Dlist *tail2,
                   Dlist **headR, Dlist **tailR);


//division

int division(Dlist *head1, Dlist *tail1,
             Dlist *head2, Dlist *tail2,
             Dlist **headR, Dlist **tailR);

#endif