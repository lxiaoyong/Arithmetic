//
// Created by Liu on 2020/4/3.
//
/*
 * 使用了归并排序对链表进行了从小到大的排序
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* sortList(ListNode* head) {
    if(head==nullptr || head->next==nullptr)
        return head;
    ListNode * slow,*fast;
    slow=head; fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr ){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode *Second_head = slow->next;
    slow->next=nullptr;
    ListNode *left = sortList(head);
    ListNode *right= sortList(Second_head);

    ListNode h(0);
    ListNode * _h=&h;
    ListNode * temp_h=_h;
    while(left!= nullptr && right != nullptr){
        if(left->val<right->val){
            temp_h->next=left;
            left=left->next;
        } else{
            temp_h->next=right;
            right=right->next;
        }
        temp_h=temp_h->next;
    }
    temp_h->next=(left== nullptr?right:left);
    return _h->next;
}