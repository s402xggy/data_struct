#include <stdio.h>
#include <string.h>

#define SIZE 100
//空队列：head == tail
//假溢出：空间未全部使用,为了避免出现假溢出，使用循环队列
//一个不大于MAX的数与MAX取余，仍然是他本神。
//判断队列为满：tail + 1 == head 



char queue[SIZE];
int head = 0, tail = 0;
void head_enqueue(char c);
char head_dequeue();
void tail_enqueue(char c);
char tail_dequeue();

int is_empty();
int is_full(void);
int is_palindorm(char *pt);

int main()
{
    char str[100];
    printf("Please enter a string: ");
    gets(str);

    if(is_palindorm(str))
        printf("str is a palindrom\n");
    else
        printf("str is not a palindrom\n");

    


    return 0;
}
void head_enqueue(char c)
{
    head = (head - 1 + SIZE) % SIZE;
    queue[head] = c;
}
char head_dequeue()
{
    char c = queue[head];
    head = (head + 1) % SIZE;
    return c;

}
void tail_enqueue(char c)
{
    queue[tail] = c;
    tail = (tail + 1) % SIZE;
}
char tail_dequeue()
{
    tail = (tail - 1 + SIZE) % SIZE;
    return queue[tail];
}

int is_empty()
{
    return tail == head;
}

int is_full(void)
{
    return ((tail + 1) % SIZE) == head;
}



int is_palindorm(char *pt)
{
    char c1, c2;
    for(int i = 0; i < strlen(pt); i++)
        if(!is_full())
            tail_enqueue(pt[i]);
    
    while (!is_empty())
    {
        c1 = head_dequeue();
        if(!is_empty())
            c2 = tail_dequeue();
        else 
            break;
        if(c1 == c2)
            continue;
        else
            return 0;
    }       
    return 1;


    
}