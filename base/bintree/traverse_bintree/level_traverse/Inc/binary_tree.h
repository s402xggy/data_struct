#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#include <stdlib.h>
#include <stdio.h>

struct BinTreeNode{
    unsigned char elem;
    struct BinTreeNode *ltree, *rtree;
};

struct BinTreeNode * create_bintree(void);
void pre_order(struct BinTreeNode *tree);
void mid_order(struct BinTreeNode *tree);
void back_order(struct BinTreeNode *tree);
void back_order(struct BinTreeNode *tree);
#include "queue.h"

void level_traverse(struct BinTreeNode *tree);


#endif