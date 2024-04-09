#include "slist.hpp"

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


    return 0;
}
