#include <iostream>
#include "slist.hpp"

/*
    合并两个有序链表
    list1 = 1 9 13 27 
    list2 = 3 5 14 81 88 95 99 
*/

Node<int> *  MergeSlist(Slist<int> & list1, Slist<int> & list2);
int main() {
    Slist<int> list1;
    Slist<int> list2;
    list1.InsertAtTail(1);
    list1.InsertAtTail(4);
    list1.InsertAtTail(9);
    list1.InsertAtTail(27);
    list1.InsertAtTail(40);


    list1.PrintSlist();
    list2.InsertAtTail(3);
    list2.InsertAtTail(5);
    list2.InsertAtTail(56);
    list2.InsertAtTail(81);
    list2.InsertAtTail(88);
    list2.InsertAtTail(95);
    list2.InsertAtTail(99);
    list2.PrintSlist();
    Node<int> * res = MergeSlist(list1, list2);
    while (res)
    {
        cout << res->data << " ";
        res = res->next;
    }
    cout << endl;
    
    
}

Node<int> *  MergeSlist(Slist<int> & list1, Slist<int> & list2) {
    Node<int> * pre1 = list1.GetHead();
    Node<int> * pre2 = list2.GetHead();
    Node<int> *head = nullptr, *tail = nullptr;
    while (pre1 && pre2) {
        // 判断是否为第一次进入，第一次则让头指针和尾指针指向最小的节点。
        if (pre1->data < pre2->data) {
            if (head == nullptr) {
                head = tail = pre1;
                // 此时元素较小的链表更新为下一个节点
                pre1 = pre1->next;
            }
            else {
                // 尾指针当前节点的尾节点指向data小的节点
                tail->next = pre1;
                // 尾指针指向data小的节点。
                tail = pre1;
                // 此时元素较小的链表更新为下一个节点
                pre1 = pre1->next;
            }
        }
        else if (pre1->data >= pre2->data){
            if (head == nullptr) {
                head = tail = pre2;
                pre2 = pre2->next;
            }
            else {
                tail->next = pre2;
                tail = pre2;
                pre2 = pre2->next;
            }
        }
    }
    if (pre1 == nullptr) {
        tail->next = pre2;
        tail = list2.GetTail();
    }
    else if (pre2 == nullptr) {
        tail->next = pre1;
        tail = list1.GetTail();
    }
        
    return head;       

}