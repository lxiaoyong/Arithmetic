//
// Created  on 2020/8/22.
//题目:https://leetcode-cn.com/problems/symmetric-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool _isSymmetric(TreeNode* left,TreeNode* right) {
    if(left== nullptr && right== nullptr) return true;
    if(left== nullptr || right== nullptr || left->val!=right->val) return false;
    return _isSymmetric(left->left,right->right) && _isSymmetric(left->right,right->left);
}
bool isSymmetric(TreeNode* root) {
    if(root== nullptr) return true;
    return _isSymmetric(root->left,root->right);
}