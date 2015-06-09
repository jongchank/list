#ifndef LINKEDLIST_LISTPLUS_H
#define LINKEDLIST_LISTPLUS_H

class Node {
private:
    Node *next;
public:
    Node(int _val);
    int val;
    friend class List;
};

class List {
private:
    Node *next;
public:
    List();
    void show();
    int search(int val);
    int insert(int index, int val);
    int remove(int index);
    int len();
    void sort();
};

#endif //LINKEDLIST_LISTPLUS_H
