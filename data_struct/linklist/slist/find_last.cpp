#include <iostream>
#include "slist.hpp"

/*
    寻找链表中倒数第n个元素
    方法，使用快慢指针：
            1.快指针先走n-1步，
            2.快慢指针同时走    
*/
void FindLast(Slist<int> &list, Node<int> * &low, int n);


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
    Node<int> *low;
    FindLast(list1, low, 1);
    cout << low->data << endl;
    FindLast(list1, low, 2);
    cout << low->data << endl;
    FindLast(list1, low, 3);
    cout << low->data << endl;
    FindLast(list1, low, 4);
    cout << low->data << endl;
    FindLast(list1, low, 5);
    cout << low->data << endl;


}

void FindLast(Slist<int> &list, Node<int> * &low, int n) {
    Node<int> *fast = list.GetHead();
    low = list.GetHead();
    int i = 0;
    while (i < n - 1) {
        fast = fast->next;
        i++;
    }
    while (fast->next != nullptr)
    {
        fast = fast->next;
        low = low->next;
    }
}

