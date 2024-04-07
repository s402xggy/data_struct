#include "queue.h"

//空队列：head == tail
//假溢出：空间未全部使用,为了避免出现假溢出，使用循环队列
//一个不大于MAX的数与MAX取余，仍然是他本神。
//判断队列为满：tail + 1 == head 

int queue[SIZE];
int head = 0, tail = 0;
void enqueue(int c)
{
    queue[tail] = c;
    tail = (tail + 1) % SIZE;

}

int dequeue()
{
    int ch = queue[head];
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