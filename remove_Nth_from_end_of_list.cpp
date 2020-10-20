//
// Created by 刘晓涌 on 2020/10/20.
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next==nullptr) return nullptr;
    ListNode *temp = head;
    while(n!=-1 && temp!=nullptr){
        temp=temp->next;
        --n;
    }
    if(n==0 && temp==nullptr){
        ListNode* new_head = head->next;
        delete head;
        return new_head;
    }
    ListNode* pre_del_node = head;
    while(temp!=nullptr){
        pre_del_node = pre_del_node->next;
        temp=temp->next;
    }
    ListNode * del_node = pre_del_node->next;
    pre_del_node->next = del_node->next;
    delete del_node;
    return head;
}