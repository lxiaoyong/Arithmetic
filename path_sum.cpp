//
// Created  on 2020/8/26.
//  https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void dfs_pathSum(vector<vector<int>>& result,vector<int>& v,TreeNode* node,int add,int sum){
    add+=node->val;
    v.push_back(node->val);
    if(node->left==nullptr && node->right== nullptr ) {
        if(add==sum) result.push_back(v);
        v.pop_back();
        return;
    }
    if(node->left) dfs_pathSum(result,v,node->left,add,sum);
    if(node->right) dfs_pathSum(result,v,node->right,add,sum);
    v.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    if(root==nullptr) return result;
    vector<int >v;int add=0;
    dfs_pathSum(result,v,root,add,sum);
    return result;
}