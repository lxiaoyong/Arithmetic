//
// Created on 2020/10/13.
// https://leetcode-cn.com/problems/swap-nodes-in-pairs/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* swapPairs(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* A = head->next;
    head->next = swapPairs(A->next);
    A->next=head;
    return A;
}