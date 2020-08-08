//
// Created  on 2020/8/8.
//
//题目：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 改进
// start 和 end 表示在中序遍历表中子树的范围
TreeNode* helpBuildTree(vector<int> &preorder,vector<int>& inorder,int root,int start,int end){
    if(preorder.empty() || inorder.empty()) return nullptr;
    if(start>end) return nullptr;
    int rootVal=preorder[root];
    auto *rootNode=new TreeNode(rootVal);
    if(start==end) return rootNode;
    int index=start;
    while(inorder[index]!=rootVal) ++index;
    rootNode->left=helpBuildTree(preorder,inorder,root+1,start,index-1);
    // 在前序遍历表中右子树的根节点= root(原根节点)+index-start(中序表中计算的左子树个数)+1
    rootNode->right=helpBuildTree(preorder,inorder,root+index-start+1,index+1,end);
    return rootNode;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helpBuildTree(preorder,inorder,0,0,inorder.size()-1);
}

// 第一版

TreeNode* buildTree_1(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty() || inorder.empty()) return nullptr;
    int rootVal=preorder[0];
    auto *root=new TreeNode(rootVal);
    if(preorder.size()==1) return root;
    vector<int> leftPreorder,rightPreorder,leftInorder,rightInorder;

    auto index=inorder.begin();
    while(*index!=rootVal) ++index;
    int leftTreeSize=index-inorder.begin();

    for(int i=1;i<=leftTreeSize;++i)
        leftPreorder.push_back(preorder[i]);
    for(int i=1+leftTreeSize;i<preorder.size();++i)
        rightPreorder.push_back(preorder[i]);
    leftInorder.insert(leftInorder.end(),inorder.begin(),index);
    rightInorder.insert(rightInorder.end(),index+1,inorder.end());
    root->left=buildTree_1(leftPreorder,leftInorder);
    root->right=buildTree_1(rightPreorder,rightInorder);
    return root;
}