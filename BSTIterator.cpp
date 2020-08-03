//
// Created on 2020/8/3.
//
// 题目：https://leetcode-cn.com/problems/binary-search-tree-iterator/
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class BSTIterator {
private:
    stack<TreeNode *> stackTree;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* t=root;
        while (t){
            stackTree.push(t);
            t=t->left;
        }
    }
    /** @return the next smallest number */
    int next() {
        TreeNode* t=stackTree.top();
        int min=t->val;
        stackTree.pop();
        t=t->right;
        if(t){
            stackTree.push(t);
            t=t->left;
            while(t){
                stackTree.push(t);t=t->left;
            }
        }
        return min;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stackTree.empty();
    }
};