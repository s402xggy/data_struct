#include "link_list_base.hpp"
#include <iostream>

int main(){
    LinkList link_list;
    InitLinkList(&link_list);
    AddLinkListNode(&link_list, 'A');
    AddLinkListNode(&link_list, 'B');
    AddLinkListNode(&link_list, 'C');
    AddLinkListNode(&link_list, 'D');
    AddLinkListNode(&link_list, 'E');
    AddLinkListNode(&link_list, 'F');
    PrintLinkList(&link_list);

    DeleteNode(&link_list, 3);
    PrintLinkList(&link_list);

    DeleteNode(&link_list, 0);
    PrintLinkList(&link_list);

    DeleteNode(&link_list, 3);
    PrintLinkList(&link_list);

    InsertNode(&link_list, 'Y', 0);
    PrintLinkList(&link_list);

    InsertNode(&link_list, 'Q', 1);
    PrintLinkList(&link_list);

    InsertNode(&link_list, 'I', 5);
    PrintLinkList(&link_list);

    InsertNode(&link_list, 'L', 6);
    PrintLinkList(&link_list);

    InsertNode(&link_list, 'U', 7);
    PrintLinkList(&link_list);

    return 0;
}
