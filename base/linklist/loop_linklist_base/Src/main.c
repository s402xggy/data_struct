#include <linklist.h>
#include <stdio.h>

int main()
{
    create_list(1);
    create_list(2);
    create_list(3);
    create_list(4);
    create_list(5);
    create_list(6);
    create_list(7);

    print_linklist();

    insert_node(0, 11);
    print_linklist();


    insert_node(1, 31);
    print_linklist();

    delete_node(0);
    print_linklist();


    delete_node(4);
    print_linklist();

    
    return 0;
}