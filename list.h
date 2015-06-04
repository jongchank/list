//
// Created by Jong-Chan Kim on 15. 6. 1..
//

#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

typedef struct node {
    struct node *next;
    int val;
} node_t;

typedef struct head {
    struct node *next;
} head_t;

void show(head_t *headp);
int search(head_t *headp, int val);
int insert(head_t *headp, int index, int val);
int remove(head_t *headp, int index);
int len(head_t *headp);
void sort(head_t *headp);

#endif //LINKEDLIST_LIST_H
