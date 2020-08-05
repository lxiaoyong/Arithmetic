//
// Created on 2020/8/5.
//题目：https://leetcode-cn.com/problems/list-of-depth-lcci/
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<ListNode*> listOfDepth(TreeNode* tree) {
    vector<ListNode*> vL;
    if(tree== nullptr) return vL;
    queue<TreeNode*> qT;
    qT.push(tree);
    while(!qT.empty()){
        int size=qT.size();
        ListNode* newHead=new ListNode(qT.front()->val);
        auto temp=newHead;
        auto qTFront=qT.front();
        if(qTFront->left) qT.push(qTFront->left);
        if(qTFront->right) qT.push(qTFront->right);
        qT.pop();
        for(int i=1;i<size;++i){
            ListNode* node=new ListNode(qT.front()->val);
            temp->next=node;
            temp=node;
            qTFront=qT.front();
            if(qTFront->left) qT.push(qTFront->left);
            if(qTFront->right) qT.push(qTFront->right);
            qT.pop();
        }
        vL.push_back(newHead);
    }
    return vL;
}