#include <stdio.h>
#define SIZE 100
//空队列：head == tail
//假溢出：空间未全部使用,为了避免出现假溢出，使用循环队列
//一个不大于MAX的数与MAX取余，仍然是他本神。
//判断队列为满：tail + 1 == head 



char queue[SIZE];
int head = 0, tail = 0;
void enqueue(char c);
char dequeue();
int isempty();
int is_full(void);


int main()
{

    char c = 'A';
    for (size_t i = 0; i < 3; i++)
    {
        if(!is_full())
        enqueue(c);
        c++;
    }
    for(size_t i = 0; i < 3; i++)
    {
        printf("%c",dequeue());
    }
    printf("\n");



    return 0;
}

void enqueue(char c)
{
    queue[tail] = c;
    tail = (tail + 1) % SIZE;

}

char dequeue()
{
    char ch = queue[head];
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