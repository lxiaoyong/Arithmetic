//
// Created on 2020/8/30.
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
void mid_dfs(Node* node,Node*& pre,Node*& head){
    if(node== nullptr) return;
    mid_dfs(node->left,pre,head);
    if(pre== nullptr) {
        head=node;pre=node;
    }else{
        pre->right=node;
        node->left=pre;
    }
    pre=node;
    mid_dfs(node->right,pre,head);
}
Node* treeToDoublyList(Node* root) {
    if(root== nullptr) return root;
    Node* pre= nullptr;
    Node* head;
    mid_dfs(root,pre,head);
    head->left=pre;
    pre->right=head;
    return head;
}