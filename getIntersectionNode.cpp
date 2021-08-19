/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

图示两个链表在节点 c1 开始相交：



题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<unordered_set>
using std::unordered_set;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> seen;
        auto p1 =headA, p2 = headB;
        while(p1){
            seen.insert(p1);
            p1 = p1->next;
        }
        while(p2){
            if(seen.count(p2))
                return p2;
            p2 = p2->next;
        }
        return nullptr;
    }
    ./*
思路和算法

使用双指针的方法，可以将空间复杂度降至 O(1)O(1)。

只有当链表 \textit{headA}headA 和 \textit{headB}headB 都不为空时，两个链表才可能相交。因此首先判断链表 \textit{headA}headA 和 \textit{headB}headB 是否为空，如果其中至少有一个链表为空，则两个链表一定不相交，返回 \text{null}null。

当链表 \textit{headA}headA 和 \textit{headB}headB 都不为空时，创建两个指针 \textit{pA}pA 和 \textit{pB}pB，初始时分别指向两个链表的头节点 \textit{headA}headA 和 \textit{headB}headB，然后将两个指针依次遍历两个链表的每个节点。具体做法如下：

每步操作需要同时更新指针 \textit{pA}pA 和 \textit{pB}pB。

如果指针 \textit{pA}pA 不为空，则将指针 \textit{pA}pA 移到下一个节点；如果指针 \textit{pB}pB 不为空，则将指针 \textit{pB}pB 移到下一个节点。

如果指针 \textit{pA}pA 为空，则将指针 \textit{pA}pA 移到链表 \textit{headB}headB 的头节点；如果指针 \textit{pB}pB 为空，则将指针 \textit{pB}pB 移到链表 \textit{headA}headA 的头节点。

当指针 \textit{pA}pA 和 \textit{pB}pB 指向同一个节点或者都为空时，返回它们指向的节点或者 \text{null}null。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB){
        if(!headA || !headB)
            return nullptr;
        auto p1 = headA, p2 = headB;
        while(p1 != p2){
            p1 = p1?p1->next:headB;
            p2 = p2?p2->next:headA;
        }
        return p1;
    }
};