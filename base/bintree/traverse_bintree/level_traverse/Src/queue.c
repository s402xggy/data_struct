#include "queue.h"
int head = 0, tail = 0;

void enqueue(struct BinTreeNode tree)
{
    queue[tail] = tree;
    tail = (tail + 1) % SIZE;

}

struct BinTreeNode dequeue()
{
    struct BinTreeNode ch;
    ch = queue[head];
    head = (head + 1) % SIZE;
    return ch;
}



int isempty()
{
    return tail == head;
}

int is_full(void)
{
    return ((tail + 1) % SIZE) == head;
}