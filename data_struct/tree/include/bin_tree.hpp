#ifndef __BIN_TREE_HPP__
#define __BIN_TREE_HPP__

#include <iostream>
using namespace std;

template <class T> 
struct BinTree{
    T data;
    BinTree<T> *ltree;
    BinTree<T> *rtree;
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



template<class T>
class Btree{
    public:
        Btree():root_(nullptr){CreateBtree();};
        ~Btree(){};

        void PrintBtree(void (*func)(BinTree<T> * tree)) {
            func(root_);
        }

    private:
        // 创建二叉树
        BinTree<T> * CreateBtree() {
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
    private:
        BinTree<T> *root_;
};











#endif
