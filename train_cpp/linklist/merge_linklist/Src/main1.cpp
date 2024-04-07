#include "link_list_base_cplus.hpp"

int main(){
    LinkList link_list;
    link_list.AddLinkListNode(1);
    link_list.AddLinkListNode(2);
    link_list.AddLinkListNode(3);
    link_list.AddLinkListNode(4);
    link_list.AddLinkListNode(5);
    link_list.PrintLinkList();

    link_list.DeleteNode(0);
    link_list.PrintLinkList();

    link_list.DeleteNode(3);
    link_list.PrintLinkList();

    link_list.DeleteNode(1);
    link_list.PrintLinkList();

    link_list.InseartNode(0, 1);
    link_list.PrintLinkList();

    link_list.InseartNode(2, 3);
    link_list.PrintLinkList();

    link_list.InseartNode(4, 3);
    link_list.PrintLinkList();

    link_list.InseartNode(4, 5);
    link_list.PrintLinkList();

    return 0;
}