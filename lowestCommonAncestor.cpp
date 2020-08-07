//
// Created by Liu on 2020/4/11.
//

#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool own_p_q (queue<TreeNode *>& node,TreeNode* root, TreeNode* p, TreeNode* q){
    if(!node.empty()) return false;
    if(root== nullptr) return false;
    bool current_node = (root==p || root==q);
    bool left = own_p_q( node,root->left, p,  q);
    bool right = own_p_q(node, root->right, p,  q);
    if(current_node && (left || right) ) node.push(root);
    if(left && right) node.push(root);
    return (current_node||left||right);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root== nullptr) return nullptr;
    queue<TreeNode *> node;
    own_p_q(node,root,p,q);
    return node.front();
}
/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr) return nullptr;
    if(root==p || root==q) return root;
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(left!= nullptr && right!= nullptr) return root;
    if(left == nullptr) return right;
    return left;
}*/
