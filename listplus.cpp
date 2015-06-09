#include <stdio.h>
#include <stdlib.h>
#include "listplus.h"

Node::Node(int _val)
{
   this->val = _val;
}

List::List()
{
    this->next = NULL;
}

void List::show()
{
    Node *p;
    int i;
    printf("----------\n");
    i = 0;
    for (p = this->next; p != NULL; p = p->next) {
        printf("[%d]: %d\n", i, p->val);
        i++;
    }
    printf("----------\n");
    return;
}

int List::search(int val)
{
    Node *p;
    int i;

    i = 0;
    for (p = this->next; p != NULL; p = p->next) {
        if (p->val == val) {
            return i;
        }
        i++;
    }
    return -1;
}

int List::insert(int index, int val)
{
    Node *p;
    int i;

    if (index == 0) {
        Node *newp = new Node(val);
        newp->next = this->next;
        this->next = newp;
        return 0;
    }
    else {
        i = 0;
        for (p = this->next; p != NULL; p = p->next) {
            if (i == index - 1) {
                Node *newp = new Node(val);
                newp->next = p->next;
                p->next = newp;
                return 0;
            }
            i++;
        }
    }
    return -1;
}

int List::remove(int index)
{
    if (index == 0) {
        if (this->next != NULL) {   /* if there is any existing node */
            Node *tmp;
            tmp = this->next;
            this->next = this->next->next;
            delete tmp;
            return 0;
        }
    }
    else {
        int i = 0;
        Node *p, *prev_p;
        prev_p = NULL;
        for (p = this->next; p != NULL; p = p->next) {
            if (i == index) {
                prev_p->next = p->next;
                delete p;
                return 0;
            }
            i++;
            prev_p = p;
        }
    } return -1;
}

int List::len() {
    int c;
    Node *p;

    c = 0;
    for (p = this->next; p != NULL; p = p->next) {
        c++;
    }
    return c;
}

void List::sort()
{
    int count, i, j;
    Node *leftp, *rightp, *leftp_prev;

    count = this->len();
    if (count < 2) {
        return;
    }
    /* we can assume that count >= 2 */
    for (i = count - 1; i > 0; i--) {
        leftp_prev = NULL;
        leftp = this->next;
        rightp = leftp->next;
        for (j = 0; j < i; j++) {
            if (leftp->val > rightp->val) {
                if (leftp_prev == NULL) {
                    /* In case of the first node */
                    Node *tmp;
                    tmp = rightp->next;
                    rightp->next = leftp;
                    this->next = rightp;
                    leftp->next = tmp;
                }
                else {
                    /* In case of other nodes */
                    Node *tmp;
                    tmp = rightp->next;
                    rightp->next = leftp;
                    leftp_prev->next = rightp;
                    leftp->next = tmp;
                }
                /*
                 * Here, leftp is actually pointing to the right node, and rightp is pointing to
                 * the left node
                 */
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
