#include "link_list_base.hpp"
#include <iostream>
void InitLinkList(LinkList *linklist){
    linklist->head = nullptr;
    // linklist->head->next = nullptr;
    linklist->tail = linklist->head;
}

void AddLinkListNode(LinkList *linklist, int elem){
    struct Node *p = new Node;
    p->elem = elem;
    p->next = nullptr;
    if (linklist->head == nullptr){
        linklist->head = p;
        linklist->tail = p;
    }
    else {
        linklist->tail->next = p;
        linklist->tail = p;
    }
}

void InsertNode(LinkList *linklist, int elem, int pos){
    struct Node *p = new Node;
    p->elem = elem;
    p->next = nullptr;
    int i = 0;
    struct Node *pre;
    pre = linklist->head;
    if (pos == 0){
        p->next = linklist->head;
        linklist->head = p;
    }
    else {
        while(i < (pos - 1)) {
            pre = pre->next;
            i++;
        }
        if (pre->next == nullptr) {
            linklist->tail->next = p;
            linklist->tail = p;
        }
        else {
            p->next = pre->next;
            pre->next = p;
        }
    }
}

void DeleteNode(LinkList *linklist, int pos){
    int i = 0;
    struct Node *pre = linklist->head;
    struct Node *pos_node;
    if (pos == 0) {
        linklist->head = linklist->head->next;
        delete pre;
    } 
    else {
        while (i < (pos - 1)) {
            pre = pre->next;
            i++;
        }
        if (pre->next == linklist->tail) {
            delete pre->next;
            pre->next = nullptr;
            linklist->tail = pre;
        }
        else {
            pos_node = pre->next;
            pre->next = pos_node->next;
            delete pos_node;
        }
    }

}

void PrintLinkList(LinkList *linklist){
    struct Node *node = linklist->head;
    while (node != nullptr) {
        std::cout << node->elem << "\t";
        node = node->next;
    }
    std::cout << std::endl;
}

LinkList * MergeLinkList(LinkList *linklist1, LinkList *linklist2)
{
    Node *p = linklist1->head;
    Node *q = linklist2->head;

    while (p != nullptr && q != nullptr) {
        if (p->elem <= q->elem) {
            while (p->next->elem <= q->elem) {
                p = p->next;
            }
            Node *node = p->next;
            p->next = q;
            p = node;
        }
        else {
            while (p->next->elem > q->elem) {
                q = q->next;
            }
            Node *node = q->next;
            q->next = p;
            q = node;
        }
    }
    return p ? linklist1: linklist2;
}