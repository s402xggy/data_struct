#include "binary_tree.h"
int main()
{
    struct BinTreeNode *mytree;
    mytree = create_bintree();
    
    level_traverse(mytree);

    printf("depth = %d\n", depth(mytree));
    printf("\n");

    printf("leaf_num = %d\n", leaf_num(mytree));
    printf("\n");


    printf("node_num = %d\n", node_num(mytree));
    printf("\n");
    return 0;
}