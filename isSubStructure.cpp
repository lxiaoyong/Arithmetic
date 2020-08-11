//
// Created  on 2020/8/11.
//
//题目：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool hasSubStructure(TreeNode*A,TreeNode*B){
    if(B== nullptr) return true;
    if(A== nullptr) return false;
    if(A->val==B->val){
        if(hasSubStructure(A->left,B->left) && hasSubStructure(A->right,B->right))
            return true;
    }
    return false;
}
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(A== nullptr || B== nullptr) return false;
    if(hasSubStructure(A,B)) return true;
    if(isSubStructure(A->left,B)) return true;
    return isSubStructure(A->right, B);
}