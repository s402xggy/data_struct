#include <iostream>
#include "bstree.hpp"
// 二叉查找树，二叉搜索树， 二叉排序。
/*
    左子树 < 根 < 右子树。
    中序遍历出来为一个排序数。
*/


const int SIZE = 10;

int main() {
    int arr[SIZE] = {37, 22, 11, 82, 67, 9, 45, 91, 33, 52};
    // 创建二叉搜索树。
    Bstree<int> btree(arr, SIZE);
    btree.PrintBtree(MidOrder<int>);
    cout << endl;

    int x = 33;
    int flag = btree.BsearchTreeFindElem(SearchBstree<int>, x);
    if (flag == 0) {
        cout << "在二叉搜索树中没有找到元素： " << x << endl;
    }
    else 
        cout << "在二叉搜索树中找到元素： " << x << endl;

    btree.BsearchTreeDelete(DeleteBstree<int> , 9);
    btree.PrintBtree(MidOrder<int>);
    cout << endl;
    return 0;
}