#include "binary_tree.h"
int main()
{
    struct BinTreeNode *mytree;
    mytree = create_bintree();
    
    level_traverse(mytree);

    return 0;
}