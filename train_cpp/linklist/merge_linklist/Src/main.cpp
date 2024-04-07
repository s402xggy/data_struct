#include "link_list_base.hpp"
#include <iostream>

int main(){
    LinkList link_list1;
    LinkList link_list2;

    InitLinkList(&link_list1);
    InitLinkList(&link_list2);

    AddLinkListNode(&link_list1, 1);
    AddLinkListNode(&link_list1, 9);
    AddLinkListNode(&link_list1, 13);
    AddLinkListNode(&link_list1, 27);

    AddLinkListNode(&link_list2, 3);
    AddLinkListNode(&link_list2, 5);
    AddLinkListNode(&link_list2, 14);
    AddLinkListNode(&link_list2, 81);
    AddLinkListNode(&link_list2, 88);
    AddLinkListNode(&link_list2, 95);
    AddLinkListNode(&link_list2, 99);
    printf("hello world!!!\n");
    PrintLinkList(MergeLinkList(&link_list1, &link_list2));


    return 0;
}
