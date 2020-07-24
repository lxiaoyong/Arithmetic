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
bool isPalindrome(ListNode* head) {
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
}

