//
// Created  on 2020/8/1.
//
// 题目：https://leetcode-cn.com/problems/check-balance-lcci/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
int computeSubtreeDepth(TreeNode *root){
    if(root== nullptr) return 0;
    return max(computeSubtreeDepth(root->left),computeSubtreeDepth(root->right))+1;
}
bool isBalanced(TreeNode* root) {
    if(root== nullptr) return true;
    return abs(computeSubtreeDepth(root->left)-computeSubtreeDepth(root->right))<= 1 &&
        isBalanced(root->left) && isBalanced(root->right);
}*/


int computeSubtreeDepth(TreeNode *root){
    if(root== nullptr) return 0;
    return max(computeSubtreeDepth(root->left),computeSubtreeDepth(root->right))+1;
}
bool isBalanced(TreeNode* root) {
    if(root== nullptr) return true;
    if(!isBalanced(root->left) || !isBalanced(root->right)) return false;
    int leftDepth=computeSubtreeDepth(root->left);
    int rightDepth=computeSubtreeDepth(root->right);
    return abs(leftDepth - rightDepth) <= 1;
}
