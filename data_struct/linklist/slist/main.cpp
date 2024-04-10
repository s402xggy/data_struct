#include "slist.hpp"
#include "loop_list.hpp"
#include "dul_list.hpp"

void ReversePrint(Dlist<int> &dlist);
int main() {
    Slist<char> slist;
    slist.InsertAtTail('X');
    slist.InsertAtTail('G');
    slist.InsertAtTail('G');
    slist.InsertAtTail('L');
    slist.PrintSlist();

    slist.DeleteNode(2);
    slist.PrintSlist();
    slist.Insert('Y', 0);
    slist.PrintSlist();
    slist.Insert('Q', 1);
    slist.Insert('Q', 0);

    slist.PrintSlist();

    // 循环链表实现功能测试
    LoopList<char> loop_list;
    loop_list.InsertAtTail('x');
    loop_list.InsertAtTail('g');
    loop_list.InsertAtTail('g');
    loop_list.InsertAtTail('h');
    loop_list.InsertAtTail('e');
    loop_list.InsertAtTail('l');
    loop_list.InsertAtTail('l');
    loop_list.InsertAtTail('o');
    loop_list.PrintSlist();
    loop_list.Insert('q', 8);
    loop_list.PrintSlist();
    loop_list.Insert('w', 0);
    loop_list.PrintSlist();
    loop_list.DeleteNode(3);
    loop_list.PrintSlist();

    // 双向链表测试
    Dlist<int> dlist;
    dlist.InsertAtTail(1);
    dlist.InsertAtTail(2);
    dlist.InsertAtTail(3);
    dlist.InsertAtTail(4);
    dlist.InsertAtTail(5);
    dlist.InsertAtTail(6);
    dlist.InsertAtTail(7);
    dlist.InsertAtTail(8);
    dlist.InsertAtTail(9);
    dlist.InsertAtTail(10);
    dlist.PrintSlist();
    ReversePrint(dlist);

    return 0;
}

void ReversePrint(Dlist<int> &dlist) {
    Dnode<int> *head = dlist.GetTail();
    while (head) {
        cout << head->data << " ";
        head = head->pre;
    }
    cout << endl;
}