//
// Created by Liu on 2020/4/13.
//
#include <set>
using namespace std;

/*
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 nullptr。
 * */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// 双指针
ListNode *detectCycle(ListNode *head) {
    ListNode* slow=head,*fast=head;
    while(fast!= nullptr && fast->next!= nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            fast=head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return nullptr;
}
/*
ListNode * detectCycle(ListNode *head) {
    set<ListNode*> nodes;
    ListNode *_h=head;
    int t=0;    //计数
    while(_h!=nullptr){
        nodes.insert(_h);
        ++t;
        // nodes存储的指针大小小于t时，说明已存在该指针，存在回路
        if(nodes.size()<t){
            return _h;
        }
        _h=_h->next;
    }
    return nullptr;
}*/
