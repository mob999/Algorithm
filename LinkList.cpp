#include"LinkList.h"
template<typename T>
LinkList<T>::LinkList(/* args */)
{
    head_=new Node;
    head_->next=nullptr;
    size_=0;
}

template<typename T>
LinkList<T>::~LinkList()
{
    Node* p=head_;
    while(p){
        Node* del=p;
        p=p->next;
        delete del;
        
    }
}

template<typename T>
bool LinkList<T>::insert(T val,unsigned pos){
    if(pos<0||pos>size()){
        return false;
    }
    if(pos==0){
        Node* q=new Node(val,head_->next);
        head_->next = q;
        size_++;
        return true;
    }
    Node* p=head_->next;
    for(auto i = 0;i<pos-1;i++){
        p=p->next;
    }
    Node* q=new Node(val,p->next);
    p->next = q;
    size_++;
    return true;
}
template<typename T>
void LinkList<T>::print(std::ostream& os){
    Node* p=head_->next;
    while(p){
        os<<p->val;
        p=p->next;
    }
}
template<typename T>
bool LinkList<T>::push_back(T val){
    Node* rear=head_;
    while(rear->next){
        rear=rear->next;
    }
    Node* n=new Node(val);
    rear->next= n;
    size_++;
    return true;
}
template<typename T>
LinkList<T>::LinkList(std::istream& is){
    T val;
    head_=new Node;
    head_->next=nullptr;
    size_=0;
    while(is>>val){
        push_back(val);
    }
}
template<typename T>
bool LinkList<T>::deletes(unsigned pos){
    if(pos<0||pos>=size()){
        return false;
    }
    Node* p=head_->next;
    for(auto i = 0;i< pos-1;i++){
        p=p->next;
    }
    Node* del=p->next;
    p->next=del->next;
    delete del;
    del=nullptr;
    size_--;
    return true;
}