//
// Created by Liu on 2020/4/9.
//


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* swapNode(TreeNode* node){
    if(node== nullptr) return nullptr;
    TreeNode *tempNode = node->left;
    node->left=node->right;
    node->right=tempNode;
    swapNode(node->left);
    swapNode(node->right);
    return node;
}
TreeNode* mirrorTree(TreeNode* root) {
    return swapNode(root);
}