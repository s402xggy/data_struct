#include "binary_tree.h"

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

void level_traverse(struct BinTreeNode *tree) {
    struct BinTreeNode node;
    enqueue(*tree);
    while (!isempty()) {
        node = dequeue();
        printf("%c", node.elem);
        if(node.ltree)
            enqueue(*node.ltree);
        if(node.rtree)
            enqueue(*node.rtree);
    }


}