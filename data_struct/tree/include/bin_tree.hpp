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
        InsertBinSearchTreeNode(tree, arr[i]);
    }
    return tree;
}


template <class T>
BinTree<T> * InsertBinSearchTreeNode(BinTree<T> * &tree, T elem) {
    if (tree == nullptr) {
        tree = new BinTree<T>;
        tree->data = elem;
        tree->ltree = tree->rtree = nullptr;
    }
    else if (elem < tree->data)
        InsertBinSearchTreeNode(tree->ltree, elem);
    else if (elem > tree->data)
        InsertBinSearchTreeNode(tree->rtree, elem);
    else {
        exit(0);
    }
    return tree;
}

/*
    二叉树：
        特点： 1、有且只有一个根节点。
              2、除了根节点以外，存在左子树T1和右子树T2（其中T1 T2都是二叉树）
        有五种形态： 空二叉树、 只有根、 根加左子树、 根加右子树、 左右子树都存在

    二叉树的深度：
        即一共有多少层。
        1、二叉树为空 深度为0；
        2、一般情况下的深度 = 二叉树中左右子树最大深度加1；
    二叉树的叶子数：
        1、二叉树为空，叶子数为0
        2、二叉树只有根节点，无左右子树，叶子树为1
        3、一般情况：为左子数的叶子树 + 右子树的叶子树。
    二叉树的节点树：
        1、二叉树为空： 节点树为0；
        2、 一般情况： 左子树的节点个数+右子树的节点个数 + 1。
*/

template<class T>
class Btree{
    public:
        Btree():root_(nullptr){CreateBtree();};
        Btree(std::string str):fill_blank_str_(str), root_(nullptr){
            std::reverse(fill_blank_str_.begin(), fill_blank_str_.end());
            FillBlankCreatBtree();
        };
        Btree(T arr[], int n){
            root_ = CreateBinSearchTree(arr, n);
        };

        ~Btree(){};

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
        // BinTree<T> * SearchThreadTree(BinTree<T> * (*func)(BinTree<T> *, T data), T data) {
        //     return func(root_, data);
        // }

        // BinTree<T> * PrenodeThreadTree(BinTree<T> * tree) {
        //     BinTree<T> * node;
        //     if (tree->lflag == true) 
        //         return tree->ltree;
        //     else {
        //         node = tree->ltree;
        //         while (node->rflag == 0)
        //            node = node->rtree; 
        //         return node;
        //     }
        // }

        // BinTree<T> * SuccnodeThreadTree(BinTree<T> * tree) {
        //     BinTree<T> * node;
        //     if (tree->rflag == true) 
        //         return tree->rtree;
        //     else {
        //         node = tree->rtree;
        //         while (node->lflag == 0)
        //            node = node->ltree; 
        //         return node;
        //     }
        // }

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

// 创建二叉树
template <class T>
BinTree<T> * Btree<T>::CreateBtree() {
    BinTree<T> *node = new BinTree<T>;
    node->ltree = nullptr;
    node->rtree = nullptr;
    if (root_ == nullptr) {
        root_ = node;
    } 
    cout << "请输入节点的元素： " << endl;
    T data;
    cin >> data;
    node->data = data;
    cout << "是否想要为节点 " << node->data << " 插入左子树： (Y/N)";
    char flag;
    cin >> flag;
    cin.ignore();
    if (flag == 'Y') 
        node->ltree = CreateBtree();
    else 
        node->ltree = nullptr;
    cout << "是否想要为节点 " << node->data << " 插入右子树： (Y/N)";
    cin >> flag;
    cin.ignore();
    if (flag == 'Y') 
        node->rtree = CreateBtree();
    else 
        node->rtree = nullptr;
    return node;

};

/*
    补空法创建二叉树：

*/
template <class T>
BinTree<T> * Btree<T>::FillBlankCreatBtree() {
    BinTree<T> *node;
    if (fill_blank_str_.back() == '#') {
        fill_blank_str_.pop_back();
        node = nullptr;
    } else {
        node = new BinTree<T>;
        if (root_ == nullptr)
            root_ = node;
        node->data = fill_blank_str_.back();
        fill_blank_str_.pop_back();
        node->ltree = FillBlankCreatBtree();
        node->rtree = FillBlankCreatBtree();
    }
    return node;
}

/*
    线索化的方式： 先序，中序，后序线索化。
    线索化的目的：快速的找到某一节点的前驱点和后继点（不同线索化的方式，某一节点的
    前驱和后继是不同的）。二叉树进行线索化分析后得到，中序线索化是最优的。
*/

template <class T>
void InOrderThread(BinTree<T> *tree, BinTree<T> * &pre) {
    if (tree == nullptr)
        return ;

    InOrderThread(tree->ltree, pre); 
    if (tree->ltree == nullptr) {
        tree->lflag = true;
        tree->ltree = pre;
    }
    else {
        tree->lflag = false;
    }

    if (pre) {
        if (pre->rtree == nullptr) {
            pre->rtree = tree;
            pre->rflag = true;
        }
        else 
            pre->rflag = false;
    }
    pre = tree;

    InOrderThread(tree->rtree, pre);
}

template<class T>
void TraverseInorderThread(BinTree<T> *tree) {
    while (tree) {
        while (tree->lflag == false) 
            tree = tree->ltree;
        std::cout << tree->data << " ";
        while (tree->rflag == true && tree->rtree != nullptr) {
            tree = tree->rtree;
            std::cout << tree->data << " ";
        }     
        tree = tree->rtree;
    }
}


// template<class T>
// BinTree<T> * SearchInorderThread(BinTree<T> *tree, T data) {
//     while (tree) {
//         while (tree->lflag == false) 
//             tree = tree->ltree;
//         if (tree->data = data)
//             return tree;
//         while (tree->rflag == true && tree->rtree != nullptr) {
//             tree = tree->rtree;
//             if (tree->data == data) 
//                 return tree;
//         }     
//         tree = tree->rtree;
//     }
// }

// 查找二叉搜索树中的元素。

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
