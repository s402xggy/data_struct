#include <stdio.h>
#include <stdlib.h>


struct BinTreeNode{
    unsigned char elem;
    struct BinTreeNode *ltree, *rtree;
    int lflag, rflag;
};

struct BInTreeNode *pre = NULL;
struct BinTreeNode * create_bintree(void); //ask_method 
void pre_order(struct BinTreeNode *tree);
void mid_order(struct BinTreeNode *tree);
void back_order(struct BinTreeNode *tree);
struct BinTreeNode * Create_BinTree(); //fill black methd;
void In_order_Thread(struct BinTreeNode *tree);
int main()
{
    struct BinTreeNode *mytree;
    printf("Please input a preorder binary tree(with fill blank #): \n");
    mytree = Create_BinTree();
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


struct BinTreeNode * Create_BinTree() {
    char ch;
    struct BinTreeNode *tree;
    scanf("%c", &ch);
    if(ch == '#') {
        tree = NULL;
    }
    else {
       tree = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
       tree->elem = ch;
       tree->ltree = Create_BinTree();
       tree->rtree = Create_BinTree();
    }
    return tree;
}


// void In_order_Thread(struct BinTreeNode *tree){
//     if (tree != NULL) {
//         //1.Do_Inorder_Thread to ltree
//         In_order_Thread(tree->ltree);

//         //2.Deal with current node 
//         if (!tree->ltree) {
//             tree->lflag = 1;
//             //current node's ltree points to the pre oode
//             tree->ltree = pre;
//         }
//         else 
//             tree->lflag = 0;

//         if (pre) {
//             if(!pre->r_tree) {
//                 pre->rflag = 1;
//                 pre->rtree = tree;
//             }
//             else 
//                 pre->rflag = 0;

//         }
//         pre = tree;


//         //3.DO_Inorder_Thread to rtree 
//         In_order_Thread(tree->rtree);
//     }

// }
