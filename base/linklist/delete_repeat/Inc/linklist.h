#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
//链表的基本操作
//1、创建链表：
//          1）创建节点
//          2）节点链接在一起。
struct node
{
    unsigned int elem;
    struct node * next;
};

void create_list(unsigned int elem);

void insert_node(int pos, unsigned int elem);

void delete_node(int pos);

void print_linklist(struct node *linklist_head);




int search(unsigned int elem);

void delete_repeat(struct node *head);


#endif