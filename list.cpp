#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void show(head_t *head)
{
    node_t *p;
    int i;
    printf("----------\n");
    i = 0;
    for (p = head->next; p != NULL; p = p->next) {
        printf("[%d]: %d\n", i, p->val);
        i++;
    }
    printf("----------\n");
    return;
}

int search(head_t *headp,   int val)
{
    node_t *p;
    int i;

    i = 0;
    for (p = headp->next; p != NULL; p = p->next) {
        if (p->val == val) {
            return i;
        }
        i++;
    }
    return -1;
}

int insert(head_t *headp, int index, int val) {
    node_t *p;
    int i;

    if (index == 0) {
        node_t *newp = (node_t *)malloc(sizeof(node_t));
        newp->val = val;
        newp->next = headp->next;
        headp->next = newp;
        return 0;
    }
    else {
        i = 0;
        for (p = headp->next; p != NULL; p = p->next) {
            if (i == index - 1) {
                node_t *newp = (node_t *)malloc(sizeof(node_t));
                newp->val = val;
                newp->next = p->next;
                p->next = newp;
                return 0;
            }
            i++;
        }
    }
    return -1;
}

int remove(head_t *headp, int index)
{
    if (index == 0) {
        if (headp->next != NULL) {   /* if there is any existing node */
            node_t *tmp;
            tmp = headp->next;
            headp->next = headp->next->next;
            free(tmp);
            return 0;
        }
    }
    else {
        int i = 0;
        node_t *p, *prev_p;
        prev_p = NULL;
        for (p = headp->next; p != NULL; p = p->next) {
            if (i == index) {
                prev_p->next = p->next;
                free(p);
                return 0;
            }
            i++;
            prev_p = p;
        }
    } return -1;
}

int len(head_t *headp) {
    int c;
    node_t *p;

    c = 0;
    for (p = headp->next; p != NULL; p = p->next) {
        c++;
    }
    return c;
}

void sort(head_t *headp)
{
    int count, i, j;
    node_t *leftp, *rightp, *leftp_prev;

    count = len(headp);
    if (count < 2) {
        return;
    }
    /* we can assume that count >= 2 */
    for (i = count - 1; i > 0; i--) {
        leftp_prev = NULL;
        leftp = headp->next;
        rightp = leftp->next;
        for (j = 0; j < i; j++) {
            if (leftp->val > rightp->val) {
                if (leftp_prev == NULL) {
                    node_t *tmp;
                    tmp = rightp->next;
                    rightp->next = leftp;
                    headp->next = rightp;
                    leftp->next = tmp;
                }
                else {
                    node_t *tmp;
                    tmp = rightp->next;
                    rightp->next = leftp;
                    leftp_prev->next = rightp;
                    leftp->next = tmp;
                }
                /* leftp and rightp swapped */
                leftp_prev = rightp;
                leftp = rightp->next;
                rightp = leftp->next;
            }
            else {
                leftp_prev = leftp;
                leftp = leftp->next;
                rightp = rightp->next;
            }
        }
    }
    return;
}
