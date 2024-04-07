#include "linklist.h"
#include <stdlib.h>
//          1）创建节点,分配内存，填充数值。
struct node *head = NULL;
struct node *tail = NULL;




void create_list(unsigned int elem)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->elem = elem;
    p->next = NULL;
    if(head == NULL) {
        head = p;
    }
    else 
        tail->next = p;
    tail = p;
    tail->next = head;

}
//


void insert_node(int pos, int elem)
{
    struct node *pre;
    pre = head;
    int i = 0;
    struct node *p = (struct node *)malloc(sizeof(struct node));

    if(pos == 0)
    {
        p->elem = elem;
        p->next = head;
        head = p;
        tail->next = head;
    }
    else
    {
        while (i < (pos - 1))
        {
            pre = pre->next;
            i++;
        }
        p->elem = elem;
        p->next = pre->next;
        pre->next = p;
        if(p->next == head)
        {
            tail = p;
        }
    }

}


void delete_node(int pos)
{
    int i = 0;
    struct node *pre, *p;
    p = head;
    pre = head;
    if(pos == 0)
    {
        head = p->next;
        free(p);
        tail->next = head;
    }
    else
    {
        while (i < (pos - 1))
        {
            pre = pre->next;
            i++;
        }
        p = pre->next;
        pre->next = p->next;
        if(p->next == head)
            tail = pre;
        free(p);

    }

    
}

void print_linklist(void)
{
    struct node *p;
    p = head;
    do {
         printf("%5d", p->elem);
         p = p->next;
    }while(p != head);
    printf("\n");
}

int search(unsigned int elem)
{
    struct node *p;
    p = head;
    do {
     if(p->elem == elem)
            return 1;
    }while (p != head);
    return 0;

   
}
