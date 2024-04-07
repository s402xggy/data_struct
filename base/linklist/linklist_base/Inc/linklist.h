#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
//链表的基本操作
//1、创建链表：
//          1）创建节点
//          2）节点链接在一起。
struct node
{
    unsigned char elem;
    struct node * next;
};

void create_list(unsigned char elem);

void insert_node(int pos, char elem);

void delete_node(int pos);

void print_linklist(void);


int search(unsigned char elem);








#endif