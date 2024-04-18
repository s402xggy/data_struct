#include "bin_tree.hpp"
// #include "in_order_thread.hpp"
int main() {
    // Btree<char> btree;
    // btree.PrintBtree(PreOrder<char>);
    // cout << endl;
    // btree.PrintBtree(MidOrder<char>);
    // cout << endl;
    // btree.PrintBtree(LastOrder<char>);
    // cout << endl;

    // btree.PrintBtree(LevelTraverse<char>);
    // cout << endl;         
    // cout << "该二叉树的深度为: " << btree.Depth(BtreeDepth<char>) << endl; 
    // cout << "该二叉树的叶子数为： " << btree.LeafNum(BtreeLeafNum<char>) << endl;
    // cout << "该二叉树的节点树为： " << btree.NodeNum(BtreeNodeNum<char>) << endl;

    // 输入前序遍历的二叉树（补空法）ABD##E##CF#G###
    cout << "请输入前序遍历的二叉树(补空法): ";
    std::string str;
    std::getline(std::cin, str);
    Btree<char> fill_blank(str);
    // 输出前序遍历的结果
    fill_blank.PrintBtree(PreOrder<char>);
    cout << endl;
    fill_blank.PrintBtree(MidOrder<char>);
    cout << endl;
    fill_blank.PrintBtree(LastOrder<char>);
    cout << endl;
    // 中序线索化二叉树
    fill_blank.MidOrderThread(InOrderThread<char>);
    // 遍历线索二叉树。
    fill_blank.PrintMidOrderThrad(TraverseInorderThread<char>);
    cout << endl;

    return 0;
}