#ifndef LINKLIST_HPP
#define LINKLIST_HPP
#include<iostream>
template<typename T>
class LinkList
{
protected:
    /* data */
    struct Node
    {
        T val;
        Node* next;
        Node() = default;
        Node(T v,Node* n=nullptr):val(v),next(n){ }
    };
    Node* head_;
    unsigned size_;
    
public:
    LinkList(/* args */);
    LinkList(std::istream& is);
    ~LinkList();
    unsigned size() { return this->size_;}
    bool insert(T val,unsigned pos);
    bool deletes(unsigned pos);
    bool push_back(T val);
    void print(std::ostream& os);
};
#endif