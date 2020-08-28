//
// Created on 2020/8/28.
// 题目：https://leetcode-cn.com/problems/copy-list-with-random-pointer/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
Node* copy_node(Node* head){
    Node* node=head,*h=head;
    while(node!=nullptr){
        Node* new_node=new Node(node->val);
        Node* temp=node->next;
        node->next=new_node;
        new_node->next=temp;
        node=temp;
    }
    return h;
}
Node* copyRandomList(Node* head) {
    if(head==nullptr) return head;
    Node* h=copy_node(head);
    Node *t=h,*new_head=t->next,*copy;
    while(t!=nullptr){
        copy=t->next;
        if(t->random) copy->random=t->random->next;
        t=copy->next;
    }
    t=h;
    while(t!= nullptr){
        copy=t->next;
        t->next=copy->next;
        t=t->next;
        if(t) copy->next=t->next;
    }
    return new_head;
}