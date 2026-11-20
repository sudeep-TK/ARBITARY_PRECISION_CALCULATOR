
#include <stdio.h>
#include "apc.h"

int main(void)
{
    int choice;
    int negative = 0;

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    printf("Enter first operand: ");
    char num1[1000];
    scanf("%999s", num1);

    printf("Enter second operand: ");
    char num2[1000];
    scanf("%999s", num2);

    if (valid_operand(num1) == FAILURE ||
        valid_operand(num2) == FAILURE)
    {
        printf("Invalid operand\n");
        return FAILURE;
    }

    if (digit_to_list(num1, &head1, &tail1) == FAILURE ||
        digit_to_list(num2, &head2, &tail2) == FAILURE)
    {
        printf("List creation failed\n");
        return FAILURE;
    }

    printf("\nChoose operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid choice\n");
        return FAILURE;
    }

    switch (choice)
    {
        case 1:
            if (addition(tail1, tail2,
                         &headR, &tailR) == FAILURE)
            {
                printf("Addition failed\n");
                return FAILURE;
            }
            break;

        case 2:
            if (subtraction(head1, tail1, head2, tail2,
                            &headR, &tailR,
                            &negative) == FAILURE)
            {
                printf("Subtraction failed\n");
                return FAILURE;
            }
            break;

        case 3:
            if (multiplication(head1, tail1, head2, tail2,
                               &headR, &tailR) == FAILURE)
            {
                printf("Multiplication failed\n");
                return FAILURE;
            }
            break;

        case 4:
            if (division(head1, tail1, head2, tail2,
                         &headR, &tailR) == FAILURE)
            {
                printf("Division failed\n");
                return FAILURE;
            }
            break;

        default:
            printf("Invalid choice\n");
            return FAILURE;
    }

    printf("Result: ");

    if (negative)
        printf("-");

    display(headR, tailR);
    printf("\n");

    return SUCCESS;
}
