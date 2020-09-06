//
// Created  on 2020/9/6.
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void dfs(TreeNode* node,int &k,int &result){
    if(node){
        dfs(node->right,k,result);
        --k;
        if(k==0 ) result=node->val;
        dfs(node->left,k,result);
    }
}
int kthLargest(TreeNode* root, int k) {
    int result=0;
    dfs(root,k,result);
    return result;
}