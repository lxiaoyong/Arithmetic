//
// Created  on 2020/8/7.
//
//题目：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root==p || root==q) return root;
    TreeNode *left= nullptr,*right= nullptr;
    if(p->val<root->val || q->val<root->val)
        left=lowestCommonAncestor(root->left,p,q);
    if(p->val>root->val || q->val>root->val)
        right=lowestCommonAncestor(root->right,p,q);
    if(left!= nullptr && right!= nullptr) return root;
    if(left== nullptr) return right;
    if(right== nullptr) return left;
    return root;
}