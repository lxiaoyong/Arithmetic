//
// Created  on 2020/8/2.
//
//题目：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root==nullptr) return result;
    queue<TreeNode*> qTree;
    qTree.push(root);
    while(!qTree.empty()){
        int size=qTree.size();
        vector<int> v;
        for(int i=0;i<size;++i){
            v.push_back(qTree.front()->val);
            if(qTree.front()->left!=nullptr) qTree.push(qTree.front()->left);
            if(qTree.front()->right!=nullptr) qTree.push(qTree.front()->right);
            qTree.pop();
        }
        result.push_back(v);
    }
    return result;
}