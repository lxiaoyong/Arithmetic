//
// Created  on 2020/8/19.
//题目：https://leetcode-cn.com/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1== nullptr) return l2;
    if(l2== nullptr) return l1;
    ListNode* head;
    if(l1->val<l2->val){
        head=l1;l1=l1->next;
    }else{
        head=l2;l2=l2->next;
    }
    ListNode* current_node=head;
    while(l1 != nullptr && l2!= nullptr){
        if(l1->val<l2->val) {
            current_node->next=l1;
            l1=l1->next;
        }else{
            current_node->next=l2;
            l2=l2->next;
        }
        current_node=current_node->next;
    }
    if(l1!= nullptr) current_node=l1;
    if(l2!= nullptr) current_node=l2;
    return head;
}