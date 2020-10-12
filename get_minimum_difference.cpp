//
// Created  on 2020/10/12.
// https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void pt_dfs(TreeNode* root,int &pre_node_val,int &min_diff){
    if(root!=nullptr){
        pt_dfs(root->right,pre_node_val,min_diff);
        if(pre_node_val==-1){
            pre_node_val=root->val;
        }else{
            min_diff=std::min(min_diff,pre_node_val-root->val);
            pre_node_val=root->val;
        }
        pt_dfs(root->left,pre_node_val,min_diff);
    }
}
int getMinimumDifference(TreeNode* root) {
    int min_diff = INT_MAX,pre_node_val = -1;
    pt_dfs(root,pre_node_val,min_diff);
    return min_diff;
}