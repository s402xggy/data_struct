#ifndef __AVLTREE_HPP__
#define __AVLTREE_HPP__

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
BinTree<T> * CreateAvlSearchTree(T arr[], int n) {
    BinTree<T> *tree = nullptr;
    for (int i = 0; i < n; i++) {
        tree = InsertAvlSearchTreeNode(tree, arr[i]);
    }
    return tree;
}

/*
    最坏情况下的二叉搜索树： （只有左左子树或只有右子树）
    查找最多从根节点到叶子节点。
    总结：二叉树的性能取决于二叉搜索树的高度。
    因此可将二叉搜索树改变为左右子树一样高（理想情况下）,一般情况下左右子树的高度差不超过1
    平衡二叉树：
        1、左右子树的高度差不超过1
        2、左右子树又分别是平衡二叉树。

*/

/*
    LL型：从失衡点到新插入节点的前两个路径，如果是左子树，左子树。
        处理：右旋。
    RR型：从失衡点到新插入节点的前两个路径，如果是右子树，右子树。
        处理：左旋。
    LR型：

    RL型：

    
*/

template <class T>
BinTree<T> * InsertAvlSearchTreeNode(BinTree<T> * tree, T elem) {
    if (tree == nullptr) {
        tree = new BinTree<T>;
        tree->data = elem;
        tree->ltree = tree->rtree = nullptr;
    }
    else if (elem < tree->data) {
        tree->ltree = InsertAvlSearchTreeNode(tree->ltree, elem);
        // 检查是否平衡。
        if (GetAvlTreeHeight(tree->ltree) - GetAvlTreeHeight(tree->rtree) > 1) {
            // LL型
            if (tree->ltree->data > elem) {
                tree = LL_Rtation(tree);
            }
            // LR型
            if (tree->ltree->data < elem) {
                tree = LR_Rtation(tree);
                tree = LL_Rtation(tree);

            }
        }

    }
    else if (elem > tree->data) {
        tree->rtree = InsertAvlSearchTreeNode(tree->rtree, elem);
        if (GetAvlTreeHeight(tree->rtree) - GetAvlTreeHeight(tree->ltree) > 1) {
            // RR型
            if (tree->rtree->data < elem) {
                tree = RR_Rtation(tree);
            }
            // RL型
            if (tree->rtree->data > elem) {
                tree = RL_Rtation(tree);
                tree = RR_Rtation(tree);
            }

        }
    }
    else {
        exit(0);
    }
    return tree;
}

template <class T>
int GetAvlTreeHeight(BinTree<T> *tree) {
    if (tree == nullptr) 
        return 0;
    return std::max(GetAvlTreeHeight(tree->ltree) , GetAvlTreeHeight(tree->rtree)) + 1;
}


template <class T>
BinTree<T> *LL_Rtation(BinTree<T> *tree) {
    BinTree<T> *temp = tree->ltree;
    tree->ltree = temp->rtree;
    temp->rtree = tree;
    return temp;
}

template <class T>
BinTree<T> *RR_Rtation(BinTree<T> *tree) {
    BinTree<T> *temp = tree->rtree;
    tree->rtree = temp->ltree;
    temp->ltree = tree;
    return temp;
}

template <class T>
BinTree<T> *LR_Rtation(BinTree<T> *tree) {
    tree->ltree = RR_Rtation(tree->ltree);
    tree = LL_Rtation(tree);
    return tree;
}

template <class T>
BinTree<T> *RL_Rtation(BinTree<T> *tree) {
    tree->rtree = LL_Rtation(tree->rtree);
    tree = RR_Rtation(tree);
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
BinTree<T>* DeleteAvltree(BinTree<T> *tree , T elem) {
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
int SearchAvltree(BinTree<T> *tree, T elem) {
    BinTree<T> *temp = tree;
    if (temp == nullptr) 
        return 0;
    if (temp->data == elem) 
        return 1;
    else if (temp->data < elem) 
        return SearchAvltree(temp->rtree, elem);
    else if (temp->data > elem) 
        return SearchAvltree(temp->ltree, elem);
    
}














#endif