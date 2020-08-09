//
// Created on 2020/8/9.
//
//题目： https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/submissions/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* reverseList(ListNode* head) {
    ListNode* cur=nullptr,*pre=head,*_next=head;
    while(_next != nullptr){
        _next=_next->next;
        pre->next=cur;
        cur=pre;
        pre=_next;
    }
    return cur;
}
