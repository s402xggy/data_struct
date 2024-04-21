#ifndef __BSTREE_HPP__
#define __BSTREE_HPP__

#ifndef __BIN_TREE_HPP__
#define __BIN_TREE_HPP__

#include <iostream>
#include <algorithm>
#include <memory>

#include "queue.hpp"
using namespace std;

template <class T> 
struct BinTree{
    T data;
    BinTree<T> *ltree;
    BinTree<T> *rtree;
    bool lflag = false;
    bool rflag = false;
};

// 二叉树转换为二叉查找树。
/*
    1. 提供一组无序的数组
    2. 产生二叉查找树
*/
template <class T>
BinTree<T> * CreateBinSearchTree(T arr[], int n) {
    BinTree<T> *tree = nullptr;
    for (int i = 0; i < n; i++) {
        tree = InsertBinSearchTreeNode(tree, arr[i]);
    }
    return tree;
}


template <class T>
BinTree<T> * InsertBinSearchTreeNode(BinTree<T> * tree, T elem) {
    if (tree == nullptr) {
        tree = new BinTree<T>;
        tree->data = elem;
        tree->ltree = tree->rtree = nullptr;
    }
    else if (elem < tree->data)
        tree->ltree = InsertBinSearchTreeNode(tree->ltree, elem);
    else if (elem > tree->data)
        tree->rtree = InsertBinSearchTreeNode(tree->rtree, elem);
    else {
        exit(0);
    }
    return tree;
}


/*
    删除一个搜索二叉树的节点，采用替换该节点数据的方式。
    中序遍历，选择该节点的前驱点或者该节点的后继点替换。
    前驱点：为该节点的左子树的最右节点。
    后继点：为该节点的右子树的最左节点。
    此案例采用后继点替换。
*/
template <class T>
BinTree<T>* DeleteBstree(BinTree<T> *tree , T elem) {
    if (tree == nullptr) 
        exit(0);
    if (tree->data == elem) {
        if (tree->rtree == nullptr) {
            BinTree<T> *temp = tree;
            tree = tree->ltree;
            delete temp;
        }
        else {
            BinTree<T> *temp = tree->rtree;
            while (temp->ltree)
                temp = temp->ltree;
            tree->data = temp->data;
            tree->rtree = DeleteBstree(tree->rtree, tree->data);
        }
    }
    else if (tree->data > elem) 
        tree->ltree = DeleteBstree(tree->ltree, elem);
    else 
        tree->rtree = DeleteBstree(tree->rtree, elem);
    return tree;
}


template<class T>
class Bstree{
    public:
        Bstree(T arr[], int n){
            root_ = CreateBinSearchTree(arr, n);
        };

        ~Bstree(){};

        void PrintBtree(void (*func)(BinTree<T> *)) {
            func(root_);
        }

        int Depth(int (*func)(BinTree<T> *)) {
            return func(root_);
        } 
        
        int LeafNum(int (*func)(BinTree<T> *)) {
            return func(root_);
        }

        int NodeNum(int (*func)(BinTree<T> *)) {
            return func(root_);
        }

        void MidOrderThread(void (*func)(BinTree<T>*, BinTree<T> * &)) {
            BinTree<T> *pre = nullptr;
            func(root_, pre);
            pre->rtree = nullptr;
            pre->rflag = true;
        }

        void PrintMidOrderThrad(void (*func)(BinTree<T> *)) {
            func(root_);
        }

        int BsearchTreeFindElem(int (*func)(BinTree<T> *, T elem1), T elem2) {
            return func(root_, elem2);
        }
       
        void BsearchTreeDelete(BinTree<T> * (*func)(BinTree<T> *, T elem1), T elem2) {
            func(root_, elem2);
        }

    private:
        BinTree<T> * CreateBtree();
        BinTree<T> * FillBlankCreatBtree();
    private:
        BinTree<T> *root_;
        std::string fill_blank_str_;
};

/*
    二叉树的遍历：先序遍历， 中序遍历， 后序遍历
        先序遍历： 先访问根节点，在访问左子树，然后右子树。
        中序遍历： 先访问左子树，在访问根节点，然后右子树。
        后序遍历： 先访问左子树，在访问右子树，然后根节点。
*/ 

// 先序遍历
template <class T>
void PreOrder(BinTree<T> * tree) {
    cout << tree->data << " ";
    if (tree->ltree != nullptr)
        PreOrder(tree->ltree);
    if (tree->rtree != nullptr)
        PreOrder(tree->rtree);
}

// 中序遍历
template <class T>
void MidOrder(BinTree<T> *tree) {
    if (tree->ltree != nullptr)
        MidOrder(tree->ltree);
    cout << tree->data << " ";
    if(tree->rtree != nullptr)
        MidOrder(tree->rtree);
}
// 后序遍历
template <class T>
void LastOrder(BinTree<T> *tree) {
    if (tree->ltree != nullptr)
        LastOrder(tree->ltree);
    if(tree->rtree != nullptr)
        LastOrder(tree->rtree);
    cout << tree->data << " "; 

}

// 层次遍历，按照层次的顺序进行遍历
template <class T>
void LevelTraverse(BinTree<T> *tree) {
    Queue<BinTree<T> *> queue(100);
    BinTree<T> *res; 
    queue.Enqueue(tree);
    while (!queue.IsEmpty()) {
        res = queue.Dequeue();
        if (res->ltree != nullptr)
            queue.Enqueue(res->ltree);
        if (res->rtree != nullptr)
            queue.Enqueue(res->rtree);
        cout << res->data << " ";
    }
}

            
template <class T>
int BtreeDepth(BinTree<T> *tree) {
    unsigned int l_depth;
    unsigned int r_depth;

    if (tree == nullptr)
        return 0;
    else {
        l_depth = BtreeDepth(tree->ltree);
        r_depth = BtreeDepth(tree->rtree);

        return (l_depth > r_depth) ? (l_depth + 1) : (r_depth + 1);
    }
}

template <class T>
int BtreeLeafNum(BinTree<T> *tree) {
    if (tree == nullptr)
        return 0;
    else if (tree->ltree == nullptr && tree->rtree == nullptr)
        return 1;
    else 
        return BtreeLeafNum(tree->ltree) + BtreeLeafNum(tree->rtree);

}

template <class T>
int BtreeNodeNum(BinTree<T> *tree) {
    if (tree == nullptr)
        return 0;
    else {
        return BtreeNodeNum(tree->ltree) + BtreeNodeNum(tree->rtree) + 1;
    }
}




template <class T>
int SearchBstree(BinTree<T> *tree, T elem) {
    BinTree<T> *temp = tree;
    // while (temp) {
    //     if (temp->data == elem)
    //         return 1;
    //     else  if (temp->data > elem)
    //         temp = temp->ltree;
    //     else if (temp->data < elem)
    //         temp = temp->rtree;
    // }
    if (temp == nullptr) 
        return 0;
    if (temp->data == elem) 
        return 1;
    else if (temp->data < elem) 
        return SearchBstree(temp->rtree, elem);
    else if (temp->data > elem) 
        return SearchBstree(temp->ltree, elem);
    
}




#endif









#endif
