#include<bits\stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    void swap(ListNode*& pre,ListNode*& n1, ListNode*& n2){
        n1->next = n2->next;
        n2->next = n1;
        pre->next = n2;
        pre = n1;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* vitualHead =new ListNode(-1, head);
        auto cur = head;
        auto pre = vitualHead;
        while(cur && cur->next){
            auto n1 = cur, n2 = cur->next;
            swap(pre, n1, n2);
            cur = cur->next;
        }
        return vitualHead->next;
        
    }
};
int main(){
    ListNode* n1=new ListNode(1);
    ListNode* n2=new ListNode(2, n1);
    ListNode* n3=new ListNode(3, n2);
    ListNode* n4=new ListNode(4, n3);
    Solution s;
    auto n = s.swapPairs(n4);
    while(n){
        cout << n->val;
        n = n->next;
    }
}