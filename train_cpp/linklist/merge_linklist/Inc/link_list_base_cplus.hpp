#ifndef DATA_STRUCT_LINKLIST_LINK_LIST_BASE_CPLUS_HPP__
#define DATA_STRUCT_LINKLIST_LINK_LIST_BASE_CPLUS_HPP__

struct Data{
    int data;
    Data  *next;
};

class LinkList{
    public:
        LinkList(){head = nullptr; tail = nullptr;};
        void AddLinkListNode(int elem);
        void DeleteNode(int pos);
        void InseartNode(int pos, int elem);
        void PrintLinkList();
    private:
        Data *head;
        Data *tail;
};





#endif