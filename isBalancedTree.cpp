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

int computeSubtreeDepth(TreeNode *root){
    if(root== nullptr) return 0;
    int leftDepth=0,rightDepth=0;
    if(root->left!= nullptr){
        ++leftDepth;
        leftDepth+=computeSubtreeDepth(root->left);
    }
    if(root->right!= nullptr){
        ++rightDepth;
        rightDepth+=computeSubtreeDepth(root->right);
    }
    return max(leftDepth,rightDepth);
}

bool isBalanced(TreeNode* root) {
    if(root== nullptr) return true;
    if(!isBalanced(root->left)) return false;
    if(!isBalanced(root->right)) return false;
    int leftDepth=0,rightDepth=0;
    if(root->left!= nullptr){
        ++leftDepth;
        leftDepth+=computeSubtreeDepth(root->left);
    }
    if(root->right!= nullptr){
        ++rightDepth;
        rightDepth+=computeSubtreeDepth(root->right);
    }
    return abs(leftDepth - rightDepth) <= 1;
}
