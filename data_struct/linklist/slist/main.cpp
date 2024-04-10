#include "slist.hpp"
#include "loop_list.hpp"
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






    return 0;
}
