//
// Created by Liu on 2020/4/1.
//

#include <vector>
#include <stack>
using namespace std;

//给定一个 "二叉搜索树" ，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//使用栈
int kthSmallest_stack(TreeNode * root,int k){
    stack<TreeNode *> s;
    while(true){
        // 因是搜索树，故left总是更小的数
        while(root!= nullptr){
            s.push(root);
            root=root->left;
        }
        root = s.top(); //第 n 次循环的top 既是树中的第n小的数
        s.pop();
        --k;
        if(k==0)
            return root->val;
        root = root->right; // 若root->right!=nullptr，由二叉搜索树的性质可知其值比此时栈中的top的值更小
    }
}

// 使用递归
/*
 * 由于是给定二叉搜索树，当我们中序遍历树时，用一个vector来存储中序编列的结果
 * vector的第k-1个元素即是所求的解
 * */

void m(TreeNode * root,vector<int> &v,int &k){
    if(v.size()==k)  return;  //当vector的大小达到k时，即最后一个元素为所求
    //中序遍历
    if(root->left!=nullptr) {
        m(root->left, v, k);
    }
    v.push_back(root->val);
    if(root->right!=nullptr) {
        m(root->right, v, k);
    }
}
int kthSmallest(TreeNode* root, int k) {
    vector<int> v;
    m(root,v,k);
    return v[k-1];
}