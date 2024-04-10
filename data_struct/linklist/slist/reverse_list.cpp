#include <iostream>
#include "slist.hpp"

/*
    链表的逆序输出
   
*/
Node<int> * ReverseList(Slist<int> &list);


int main() {
    Slist<int> list1;
    list1.InsertAtTail(1);
    list1.InsertAtTail(2);
    list1.InsertAtTail(3);
    list1.InsertAtTail(4);
    list1.InsertAtTail(5);
    list1.InsertAtTail(6);
    list1.InsertAtTail(7);
    list1.InsertAtTail(8);
    list1.InsertAtTail(9);
    list1.InsertAtTail(0);
    list1.PrintSlist();
    Node<int> *low = ReverseList(list1);
    while (low) {
        cout << low->data << " ";
        low = low->next;
    }
    cout << endl;
}

Node<int> * ReverseList(Slist<int> &list) {
    Node<int> *head = list.GetHead();
    Node<int> *p = nullptr;
    Node<int> *n = nullptr;
    p = head->next;
    head->next = nullptr;
    while (p->next != nullptr) {
        n = p->next;
        p->next = head;
        head = p;
        p = n;
    }
    p->next = head;
    head = p;
    return head;
}
