//
// Created on 2020/8/24.
//题目：https://leetcode-cn.com/problems/linked-list-cycle/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
bool hasCycle(ListNode *head) {
    ListNode* slow=head,*fast=head;
    while(fast!= nullptr && fast->next!= nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) return true;
    }
    return false;
}