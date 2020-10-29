//
// Created  on 2020/10/29.
// https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void get_path_sum(TreeNode* node,int one_path_sum,int& nums_sum){
    if(node==nullptr) return;
    one_path_sum*=10;
    one_path_sum +=node->val;
    if(node->left==nullptr && node->right==nullptr){
        nums_sum+=one_path_sum;
        return;
    }
    get_path_sum(node->left,one_path_sum,nums_sum);
    get_path_sum(node->right,one_path_sum,nums_sum);
}
int sumNumbers(TreeNode* root) {
    if(root==nullptr) return 0;
    int nums_sum=0;
    get_path_sum(root,0,nums_sum);
    return nums_sum;
}