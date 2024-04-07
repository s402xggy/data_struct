#include <stdio.h>
#include <stdlib.h>
struct BinTreeNode{
    unsigned char elem;
    struct BinTreeNode *ltree, *rtree;
};
struct BinTreeNode * create_bintree(void);
void pre_order(struct BinTreeNode *tree);
void mid_order(struct BinTreeNode *tree);
void back_order(struct BinTreeNode *tree);

int main()
{
    struct BinTreeNode *mytree;
    mytree = create_bintree();
    pre_order(mytree);
    printf("\n");

    mid_order(mytree);
    printf("\n");

    back_order(mytree);
    printf("\n");
    return 0;
}

struct BinTreeNode * create_bintree(void) {
   struct BinTreeNode * tree;
   unsigned char flag;
   tree = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
   printf("Please input the node elem:\n");
   while((tree->elem = getchar()) == '\n');
   printf("Do you want to insert l_tree for %c, (Y/N)?\n", tree->elem);
   while((flag = getchar()) == '\n');
   if (flag == 'Y') {
    tree->ltree = create_bintree();
   } 
   else {
    tree->ltree = NULL;
   }
   printf("Do you want to insert r_tree for %c, (Y/N)?\n", tree->elem);
   while((flag = getchar()) == '\n');
   if (flag == 'Y') {
    tree->rtree = create_bintree();
   } 
   else {
    tree->rtree = NULL;
   }
   return tree;
}



void pre_order(struct BinTreeNode *tree) {
    if (tree) {
        printf("%c ", tree->elem);
        pre_order(tree->ltree);
        pre_order(tree->rtree);
    }
}


void mid_order(struct BinTreeNode *tree) {
    if (tree) {
        mid_order(tree->ltree);
        printf("%c ", tree->elem);
        mid_order(tree->rtree);

    }
}

void back_order(struct BinTreeNode *tree) {
    if (tree) {
        back_order(tree->ltree);
        back_order(tree->rtree);
        printf("%c ", tree->elem);
    }
}