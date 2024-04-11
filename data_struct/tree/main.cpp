#include "bin_tree.hpp"

int main() {
    Btree<char> btree;
    btree.PrintBtree(PreOrder<char>);
    cout << endl;
    btree.PrintBtree(MidOrder<char>);
    cout << endl;
    btree.PrintBtree(LastOrder<char>);
    cout << endl;

    btree.PrintBtree(LevelTraverse<char>);
    cout << endl;
    cout << "该二叉树的深度为: " << btree.Depth(BtreeDepth<char>) << endl; 
    cout << "该二叉树的叶子数为： " << btree.LeafNum(BtreeLeafNum<char>) << endl;
    cout << "该二叉树的节点树为： " << btree.NodeNum(BtreeNodeNum<char>) << endl;
    return 0;
}