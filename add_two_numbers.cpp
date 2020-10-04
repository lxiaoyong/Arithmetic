//
// Created  on 2020/10/4.
// https://leetcode-cn.com/problems/add-two-numbers/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head_pre= new ListNode(0);
    ListNode *temp=head_pre;
    int c=0;
    int add_num=0;
    while(l1!=nullptr || l2!=nullptr){
        add_num=c;
        if(l1!=nullptr) {
            add_num+=l1->val;l1=l1->next;
        }
        if(l2!=nullptr) {
            add_num+=l2->val;l2=l2->next;
        }
        if(add_num>9){
            c=1;
            temp->next = new ListNode(add_num-10);
        }else{
            c=0;
            temp->next = new ListNode(add_num);
        }
        temp=temp->next;
    }
    if(c)
        temp->next = new ListNode(1);
    ListNode *head = head_pre->next;
    delete head_pre;
    return head;
}