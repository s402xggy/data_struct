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


void delete_repeat(struct node *head)
{
    int flag[10] = {0, 0, 0, 0, 0, 0, 0, 0 , 0, 0};
    struct node *p = head;
    struct node *repeat;
    flag[p->elem] = 1;

    while (p->next) {
        if (flag[p->next->elem] == 0) {
            flag[p->next->elem] = 1;
            p = p->next;
        }
        else {
            repeat = p->next;
            p->next = repeat->next;
            free(repeat);
        }
    }
}