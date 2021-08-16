/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* head= nullptr, * tail= nullptr;// 定义结果链表的头尾节点， 初始值均为空
    int carry = 0;// 定义加法运算的进位值， 初始值为0
    while(l1 || l2){
        auto n1 = l1?l1->val:0;// 暂时存储两个运算数
        auto n2 = l2?l2->val:0;// 若当前结点为空， 将运算数当作0进行处理
        auto sum = n1 + n2 + carry;// 两数位之和， 值为当前位之和加上前一位的进位值
        if(!head){ // 初始化头尾结点， 其值应为sum对10取模
            head = tail = new ListNode(sum % 10);
        }
        else{// 创建新结点， 其值也为sum对10取模
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;// 进位值为sum/10的整数部分
        l1 = l1?l1->next:l1;
        l2 = l2?l2->next:l2;
    }
    if(carry > 0){// 若两个链表均遍历完， 进位值仍不为零， 说明要新增一位
        tail->next = new ListNode(carry);
    }
    return head;
}

int main(){
    ListNode* p1= new ListNode(3);
    ListNode* p2= new ListNode(4,p1);
    ListNode* p3= new ListNode(2,p2);
    ListNode* p4= new ListNode(4);
    ListNode* p5= new ListNode(6,p4);
    ListNode* p6= new ListNode(5,p5);
    ListNode* p =addTwoNumbers(p3, p6);
    while(p){
        std::cout<<p->val<< " ";
        p = p->next;
    }
}