#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};


void traverse(TreeNode* root) {
    if (root == nullptr)
        return;
    std::cout << root->val << " ";

    traverse(root->left);

    traverse(root->right);
}

// 翻转二叉树，将所有树的左右子树互相交换。
void Reserve(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    Reserve(root->left);
    Reserve(root->right);
}





int main() {

}