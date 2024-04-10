#include <iostream>
#include "slist.hpp"

/*
    删除链表中出现过的元素。(元素范围为0-10)
    list1 = 1 1 4 3 4 5 1 6 7 6
    如何标记某个数字已经出现：
        使用辅助数组：下表表示要检索的内容
                    元素内容表示状态（是否出现）
    
*/

void DeleteRepeat(Slist<int> &list);

int main() {
    Slist<int> list1;
    list1.InsertAtTail(1);
    list1.InsertAtTail(4);
    list1.InsertAtTail(9);
    list1.InsertAtTail(1);
    list1.InsertAtTail(3);
    list1.InsertAtTail(3);
    list1.InsertAtTail(4);
    list1.InsertAtTail(5);
    list1.InsertAtTail(4);
    list1.InsertAtTail(7);
    list1.InsertAtTail(1);




    list1.PrintSlist();
    DeleteRepeat(list1);
    list1.PrintSlist();

}

void DeleteRepeat(Slist<int> &list) {
    int flag[10] = {0};
    Node<int> *p = list.GetHead();

    flag[p->data] = 1;
    while (p->next) {
        if (flag[p->next->data] == 0) {
            flag[p->next->data] = 1;
            p = p->next;
        } else {
            Node<int> *q = p->next;
            p->next = p->next->next;
        }

    }

}


