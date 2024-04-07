#include <stdio.h>
#include <stdlib.h>
struct BinTreeNode{
    unsigned char elem;
    struct BinTreeNode *ltree, *rtree;
};
struct BinTreeNode * create_bintree(void);


int main()
{
    struct BinTreeNode *mytree;
    mytree = create_bintree();

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