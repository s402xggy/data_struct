#include <linklist.h>
#include <stdio.h>
extern struct node *head;
extern struct node *tail;


int main()
{
    create_list(1);
    create_list(2);
    create_list(1);
    create_list(4);
    create_list(5);
    create_list(4);
    print_linklist(head);

    delete_repeat(head);
    print_linklist(head);

    return 0;
}


