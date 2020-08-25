// Created  on 2020/7/24.
//
// 题目：https://leetcode-cn.com/problems/palindrome-linked-list/
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverse_list(ListNode* head){
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* cur=head,* new_head=head->next,*temp=head->next->next;
    cur->next= nullptr;
    new_head->next=cur;
    while(temp!= nullptr){
        cur=new_head;
        new_head=temp;
        temp=temp->next;
        new_head->next=cur;
    }
    return new_head;
}
bool isPalindrome(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return true;
    ListNode* slow=head,*fast=head,*pre_slow= nullptr;
    while(fast!=nullptr && fast->next!= nullptr){
        fast=fast->next->next;
        pre_slow=slow;
        slow=slow->next;
    }
    bool palindrome=true;
    ListNode* reverse_list_head=reverse_list(slow);
    ListNode* temp=reverse_list_head;
    fast=head;pre_slow->next= nullptr;
    while(fast!=nullptr){
        if(fast->val==temp->val){
            fast=fast->next;temp=temp->next;
        }else{
            palindrome=false;
            break;
        }
    }
    reverse_list_head=reverse_list(reverse_list_head);
    pre_slow->next=reverse_list_head;
    return palindrome;
}
/*bool isPalindrome(ListNode* head) {
    ListNode *pl=head;
    vector<int> nums;
    while(pl!=NULL){
        nums.push_back(pl->val);
        pl=pl->next;
    }
    int len=nums.size();
    bool flag=true;
    for(int i=0;i<len/2;++i){
        if(nums[i]!=nums[len-i-1]){
            flag=false;break;
        }
    }
    return flag;
}*/

