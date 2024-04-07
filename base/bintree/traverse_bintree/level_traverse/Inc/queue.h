#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "binary_tree.h"
#include <stdio.h>
#define SIZE 512
//空队列：head == tail
//假溢出：空间未全部使用,为了避免出现假溢出，使用循环队列
//一个不大于MAX的数与MAX取余，仍然是他本神。
//判断队列为满：tail + 1 == head 



struct BinTreeNode queue[SIZE];
extern int head, tail;
void enqueue(struct BinTreeNode tree);
struct BinTreeNode dequeue();
int isempty();
int is_full(void);



#endif