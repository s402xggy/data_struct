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
    p->pre = NULL;
    if(head == NULL)
        head = p;
    else {
        p->pre = tail;
        tail->next = p;
    }
    tail = p;
}

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
        p->pre = NULL;
        head->pre = p;
        head = p;
    }
    else
    {
        while (i < (pos - 1))
        {
            pre = pre->next;
            i++;
        }
        p->elem = elem;
        if(p->next == NULL) {
            p->pre = tail;
            p->next = NULL;
            tail->next = p;
            tail = p;
        }
        else {
            p->next = pre->next;
            p->pre = pre;
            p->next->pre = p;
            pre->next = p;
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
        head = head->next;
        head->pre = NULL;
        free(p);
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
        if(p->next != NULL)
            pre->next->pre = pre;
        // if(p->next == NULL)
        else 
            tail = pre;
        free(p);

    }

    
}

void print_linklist(void)
{
    struct node *p;
    for(p = head; p; p = p->next)
        printf("%3d", p->elem);
    printf("\n");
}

int search(unsigned int elem)
{
    struct node *p;
    for(p = head; p; p = p->next)
        if(p->elem == elem)
            return 1;
    return 0;
}
