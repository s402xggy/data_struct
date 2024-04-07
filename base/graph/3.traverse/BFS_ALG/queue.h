#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#define SIZE 512
extern int queue[SIZE];
void enqueue(int c);
int dequeue();
int isempty();
int is_full(void);













#endif
