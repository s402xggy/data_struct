#ifndef DATA_STRUCT_LINKLIST_LINK_LIST_BASE_HPP__
#define DATA_STRUCT_LINKLIST_LINK_LIST_BASE_HPP__

struct Node{
    char elem;
    Node * next;
};

struct LinkList{
    Node *head;
    Node *tail;
};

void InitLinkList(LinkList *linklist);
void AddLinkListNode(LinkList *linklist, char elem);
void InsertNode(LinkList *linklist, char elem, int pos);
void DeleteNode(LinkList *linklist, int pos);
void PrintLinkList(LinkList *linklist);

















#endif