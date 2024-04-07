#include <stdio.h>
#include <string.h>
#define SIZE 100
//空队列：head == tail
//假溢出：空间未全部使用,为了避免出现假溢出，使用循环队列
//一个不大于MAX的数与MAX取余，仍然是他本神。
//判断队列为满：tail + 1 == head 



int queue[SIZE];
int head = 0, tail = 0;
void enqueue(int c);
int dequeue();
int isempty();
int is_full(void);
int screct[100];

int main()
{
    char ch_num[100];
    int num[100];
    int n = 0;
    printf("Please enter a code: ");
    gets(ch_num);
    for(int i = 0; i < strlen(ch_num); i++)
    {
        enqueue(ch_num[i] - '0');
    }
    printf("%s",ch_num);
    printf("\n");

    while (!isempty())
    {
       num[n++] = dequeue();
       if(!isempty())
       {
        int n_temp = dequeue();
        if(!is_full())
            enqueue(n_temp);
       }
    }
    for(int j = 0; j < strlen(ch_num); j++)
    {
        printf("%d",num[j]);
    }
    printf("\n");

    

    
    



    return 0;
}

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