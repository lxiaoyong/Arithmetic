//
// Created  on 2020/8/4.
//
// 题目：https://leetcode-cn.com/problems/validate-binary-search-tree/
#include <climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool LDR_IsValidBST(TreeNode* root,long long& pre){
    if(root==nullptr) return true;
    if(!LDR_IsValidBST(root->left,pre)) return false;
    if( pre >= root->val) return false; // 中序遍历，前一个值应比后一个小
    pre=root->val;
    return LDR_IsValidBST(root->right,pre);
}
bool isValidBST(TreeNode* root) {
    long long  ptr=LLONG_MIN;
    return LDR_IsValidBST(root,ptr);
}
