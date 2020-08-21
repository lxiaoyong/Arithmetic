//
// Created on 2020/8/21.
//题目：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// 两链表走完自身后再从另一链表头开始走，便确保两链表走了相同多的节点，若有相交节点，则必相遇
ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
    if(headA== nullptr || headB== nullptr) return nullptr;
    ListNode* ha=headA,*hb=headB;
    bool a2b=false,b2a=false;
    while(ha!=hb){
        ha=ha->next;
        if(ha==nullptr && !a2b){
            ha=headB;a2b=true;
        }
        hb=hb->next;
        if(hb== nullptr && !b2a){
            hb=headA;b2a=true;
        }
    }
    return ha;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* ha=headA,*hb=headB;
    while(ha != nullptr && hb != nullptr){
        if(ha==hb) return ha;
        else{
            ha=ha->next;
            if(ha== nullptr && hb->next !=nullptr ) ha=headB;
            hb=hb->next;
            if (hb==nullptr && ha!= nullptr) hb=headA;
        }
    }
    return nullptr;
}
