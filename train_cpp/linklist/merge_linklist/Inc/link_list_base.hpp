#ifndef DATA_STRUCT_LINKLIST_LINK_LIST_BASE_HPP__
#define DATA_STRUCT_LINKLIST_LINK_LIST_BASE_HPP__

struct Node{
    int elem;
    Node * next;
};

struct LinkList{
    Node *head;
    Node *tail;
};

void InitLinkList(LinkList *linklist);
void AddLinkListNode(LinkList *linklist, int elem);
void InsertNode(LinkList *linklist, int elem, int pos);
void DeleteNode(LinkList *linklist, int pos);
void PrintLinkList(LinkList *linklist);
LinkList * MergeLinkList(LinkList *linklist1, LinkList *linklist2);

















#endif