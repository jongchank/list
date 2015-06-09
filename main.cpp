#include <stdio.h>
#include "list.h"
#include "listplus.h"

int main(void)
{
    #if 0
    head_t head = {NULL};

    printf("%d\n", insert(&head, 0, 1));
    printf("%d\n", insert(&head, 0, 2));
    printf("%d\n", insert(&head, 0, 3));
    printf("%d\n", insert(&head, 0, 4));
    printf("--> %d\n", search(&head, 1));
    show(&head);
    sort(&head);
    show(&head);
    #endif

    List list = List();

    list.insert(0, 1);
    list.insert(0, 2);
    list.insert(0, 3);
    list.show();
    list.remove(2);
    list.show();
    list.sort();
    list.show();

    return 0;
}
