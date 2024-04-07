#include <linklist.h>
#include <stdio.h>

int main()
{
    create_list('A');
    create_list('B');
    create_list('C');
    create_list('D');
    print_linklist();

    delete_node(2);
    print_linklist();

    insert_node(0, 'F');
    insert_node(2, 'Z');
    print_linklist();

    if(search('A'))
        printf("the elem is found in the linklist\n");
    else
        printf("Can not find it\n");

    return 0;
}