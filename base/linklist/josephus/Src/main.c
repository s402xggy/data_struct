#include <linklist.h>
#include <stdio.h>
#include <stdlib.h>

extern struct node *head;

int main()
{
    int n, k, m;
    printf("Please enter the number of person: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        create_list(i);
    }
    print_linklist();
    struct node *pre = head;


    printf("Please enter the start num: ");
    scanf("%d", &k);
    
    while (--k)
    {
        pre = pre->next;
    }
    // printf("pre->elem = %d\n", pre->elem);
    printf("Please enter the m: ");
    scanf("%d", &m);
    struct node *temp;
    if (m == 1) {
        for (int i = 0; i < n; i++) {
            printf("%3d", pre->elem);
            pre = pre->next;
        }
        printf("\n");

    }
    else {
        while(n --)
        {
            for(int i = 1; i < m - 1; i++)
                pre = pre->next;
            temp = pre->next->next;
            printf("%3d", pre->next->elem);
            free(pre->next);
            pre->next = temp;
        }
    }
    return 0;
}