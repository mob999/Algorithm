#include<iostream>
using std::cout;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto p1 = l1, p2 = l2;
    ListNode* l3 = new ListNode(-1);
    auto p3 = l3;
    while(p1 && p2){
        if(p1->val <= p2->val){
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    while(p1){
        p3->next = p1;
        p3 = p1;
        p1 = p1->next;
    }
    while(p2){
        p3->next = p2;
        p3 = p2;
        p2 = p2->next;
    }
    return l3->next;
}

ListNode* mergeTwoListsRecursion(ListNode* l1, ListNode* l2){
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    if(l1->val <= l2->val){
        l1->next = mergeTwoListsRecursion(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoListsRecursion(l1, l2->next);
        return l2;
    }
}

int main(){
    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(2,n1);
    ListNode* n3 = new ListNode(1,n2);
    ListNode* m1 = new ListNode(3);
    ListNode* m2 = new ListNode(2,m1);
    ListNode* m3 = new ListNode(1,m2);
    auto n = mergeTwoListsRecursion(n3,m3);
    while(n){
        cout << n->val << ' ';
        n = n->next;
    }
}