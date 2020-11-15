//
// Created on 2020/11/15.
// https://leetcode-cn.com/problems/odd-even-linked-list/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* first_end = head;
    ListNode* second_start = head->next, *second_end = second_start;
    ListNode* cur = second_end->next;
    while(cur!=nullptr){
        first_end->next = cur;
        first_end = first_end->next;
        second_end->next = cur->next;
        second_end = second_end->next;
        if(second_end) cur=second_end->next;
        else break;
    }
    first_end->next = second_start;
    return head;
}