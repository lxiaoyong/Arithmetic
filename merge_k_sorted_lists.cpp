//
// Created  on 2020/11/7.
//
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* merge_two_lists(ListNode* first,ListNode* second){
    auto pre_head = new ListNode(-1);
    ListNode* pre = pre_head;
    while(first!=nullptr && second!=nullptr){
        if(first->val < second->val){
            pre->next=first;
            pre=first;
            first=first->next;
        }else{
            pre->next=second;
            pre=second;
            second=second->next;
        }
    }
    if(first!=nullptr) pre->next=first;
    else pre->next=second;
    auto head = pre_head->next;
    delete pre_head;
    return head;
}
ListNode* merge(std::vector<ListNode*>& lists,int left,int right){
    if(left==right-1) return lists[left];
    int mid = left+(right-left)/2;
    return merge_two_lists(merge(lists,left,mid),merge(lists,mid,right));
}
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    int size = lists.size();
    if(size==0) return nullptr;
    return merge(lists,0,size);
}
/*
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    int size = lists.size();
    if(size==0 ) return nullptr;
    if(size==1) return lists[0];
    auto *pre = new ListNode(-1);
    ListNode *pre_head = pre;
    int nullptr_size = 0;
    int k=0;
    for(ListNode* &ptr:lists)
        if(ptr!=nullptr) ++k;
    while(nullptr_size!=k){
        for(int i=0;i<size;++i){
            if(lists[i]!=nullptr){
                ListNode* min = lists[i];
                int t=i;
                for(int j=0;j<size;++j)
                    if(lists[j]!=nullptr && j!=i  && lists[j]->val < min->val){
                        min = lists[j];
                        t=j;
                    }
                pre->next = min;
                pre=min;
                lists[t] = lists[t]->next;
                if(lists[t]==nullptr) ++nullptr_size;
                break;
            }
        }
    }
    ListNode *head = pre_head->next;
    delete pre_head;
    return head;
}*/
