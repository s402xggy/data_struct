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
    if(head == NULL)
        head = p;
    else 
        tail->next = p;
    tail = p;

}
//


void insert_node(int pos, unsigned int elem)
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
        if(p->next == NULL)
            tail = p;
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
        if(p->next == NULL)
            tail = pre;
        free(p);

    }

    
}

void print_linklist(struct node *linklist_head)
{
    struct node *p;
    for(p = linklist_head; p; p = p->next)
        printf("%5d", p->elem);
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


int find_mid(struct node *head){
    struct node *p = head;
    struct node *q = head;
    int i = 0;
    while(p != NULL && p->next != NULL)
    {
        p = p->next->next;
        q = q->next;
        i++;
    }
    return q->elem;

}

int find_last_nth(struct node *head, int last_n){
    struct node *p = head;
    struct node *q = head;
    for (int i = 0; i < last_n - 1; i++) {
        p = p->next;
    }
    while (p->next != NULL) {
        p = p->next;
        q = q->next;
    }
    return q->elem;
}

