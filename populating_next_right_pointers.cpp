//
// Created on 2020/10/15.
// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
void  subtree_connect(Node* root){
    if(root->left==nullptr) return;
    root->left->next = root->right;
    if(root->next) root->right->next = root->next->left;
    else root->right->next=nullptr;
    subtree_connect(root->left);
    subtree_connect(root->right);
}
Node* connect(Node* root) {
    if(root!=nullptr){
        root->next=nullptr;
        subtree_connect(root);
    }
    return root;
}