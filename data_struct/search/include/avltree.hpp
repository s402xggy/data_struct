#ifndef __AVLTREE_HPP__
#define __AVLTREE_HPP__

#include <iostream>
#include <algorithm>
#include <memory>

#include "queue.hpp"
using namespace std;

/*
平衡二叉树：
    1、平衡二叉树的左右子树高度差不超过1。
    2、左右子树又分别是平衡二叉树。
最小不平衡子树：
    1、插入后，造成。

*/




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
BinTree<T> * CreateAvlSearchTree(T arr[], int n) {
    BinTree<T> *tree = nullptr;
    for (int i = 0; i < n; i++) {
        InsertAvlSearchTreeNode(tree, arr[i]);
    }
    return tree;
}


template <class T>
BinTree<T> * InsertAvlSearchTreeNode(BinTree<T> * &tree, T elem) {
    if (tree == nullptr) {
        tree = new BinTree<T>;
        tree->data = elem;
        tree->ltree = tree->rtree = nullptr;
    }
    else if (elem < tree->data)
        InsertAvlSearchTreeNode(tree->ltree, elem);
    else if (elem > tree->data)
        InsertAvlSearchTreeNode(tree->rtree, elem);
    else {
        exit(0);
    }
    return tree;
}

template <class T>
BinTree<T>* DeleteAvltree(BinTree<T> *tree , T elem) {
    if (tree == nullptr) 
        exit(0);
    if (tree->data == elem) {
        if (tree->ltree == nullptr) {
            BinTree<T> *temp = tree;
            tree = tree->ltree;
            delete temp;
        }
        else {
            BinTree<T> *temp = tree->rtree;
            while (temp->ltree)
                temp = temp->ltree;
            tree->data = temp->data;
            tree->rtree = DeleteAvltree(tree->rtree, tree->data);
        }
    }
    else if (tree->data > elem) 
        tree->ltree = DeleteAvltree(tree->ltree, elem);
    else 
        tree->rtree = DeleteAvltree(tree->rtree, elem);
    return tree;
}


template<class T>
class Avltree{
    public:
        Avltree(T arr[], int n){
            root_ = CreateAvlSearchTree(arr, n);
        };

        ~Avltree(){};

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
    while (temp) {
        if (temp->data == elem)
            return 1;
        else  if (temp->data > elem)
            temp = temp->ltree;
        else if (temp->data < elem)
            temp = temp->rtree;
    }
    return 0;
}










#endif