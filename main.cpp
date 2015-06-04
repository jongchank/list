#include <stdio.h>
#include "list.h"

int main(void)
{
    head_t head = {NULL};

    printf("%d\n", insert(&head, 0, 1));
    printf("%d\n", insert(&head, 0, 2));
    printf("%d\n", insert(&head, 0, 3));
    printf("%d\n", insert(&head, 0, 4));
    printf("--> %d\n", search(&head, 1));
    show(&head);
    sort(&head);
    show(&head);

    return 0;
}
