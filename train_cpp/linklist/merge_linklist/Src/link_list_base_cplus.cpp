#include "link_list_base_cplus.hpp"
#include <iostream>

void LinkList::AddLinkListNode(int elem){
    Data *p = new Data;
    p->data = elem;
    p->next = nullptr;
    if (head == nullptr) {
        head = p;
        tail = p;
    }
    else {
        tail->next = p;
        tail = p;
    }
}

void LinkList::DeleteNode(int pos){
    Data *pre = new Data;
    Data *pos_node;
    pre = head;
    int i = 0;
    if (pos == 0) {
        pos_node = head;
        head = head->next;
        delete pos_node;
    }
    else {
        while (i < (pos - 1)) {
            pre = pre->next;
            i++;
        }
        if (pre->next == tail) {
            pos_node = tail;
            tail = pre;
            tail->next = nullptr;
            delete pos_node;
        }
        else {
            pos_node = pre->next;
            pre->next = pos_node->next;
            delete pos_node;
        }
    }
}

void LinkList::InseartNode(int pos, int elem){
    Data *p = new Data;
    p->data = elem;
    p->next = nullptr;
    Data *pre = head;
    
    int i = 0;
    if (pos == 0) {
        p->next = pre;
        head = p;
    }
    else {
        while (i < (pos - 1)) {
            pre = pre->next;
            i++;
        }
        if (pre == tail) {
            pre->next = p;
            tail = p;
        }
        else {
            p->next = pre->next;
            pre->next = p;
        }

    }
}

void LinkList::PrintLinkList(){
    Data *p = head;
    while (p)
    {
        std::cout << p->data << "\t";
        p = p->next;
    }
    std::cout << std::endl;
}
