#ifndef SQLIST_CPP
#define SQLIST_CPP
#define DEFAULT_SIZE 1000
#include<vector>
#include<iostream>
template<typename T>
class SqList{
private:
    T* value;
    unsigned curSize_;
    unsigned maxSize_;
public:
    SqList(const std::vector<T>&, unsigned maxSize=DEFAULT_SIZE);
    SqList(unsigned maxSize=DEFAULT_SIZE);
    SqList(const T*, unsigned length, unsigned maxSize=DEFAULT_SIZE);
    SqList(unsigned n, T data, unsigned maxSize=DEFAULT_SIZE);
    SqList(std::istream&,unsigned maxSize=DEFAULT_SIZE);
    ~SqList();
    
    void pushBack(const T& data);
    void insert(const T& data, unsigned pos);
    T erase(unsigned pos);
    unsigned size();
    bool empty();
    T* begin();
    T* end();
    friend void print(const SqList<T>& list, std::ostream& os = std::cout){
        for(unsigned i = 0; i < list.curSize_; i++){
            os << list.value[i]<< " ";
        }
        os << '\n';
    }
    T& operator [](size_t index){
        if(index < 0 || index >= curSize_ ){
            std::cout << "Index Overflow";
        }
        return value[index];
    }
};

template<typename T>
SqList<T>::SqList(const std::vector<T>& arr, unsigned maxSize):curSize_(arr.size()), maxSize_(maxSize){
    value = new T[maxSize];
    for(unsigned i = 0; i < curSize_; i++){
        value[i] = arr[i];
    }
}

template<typename T>
SqList<T>::SqList(unsigned maxSize):curSize_(0), maxSize_(maxSize){
    value = new T[maxSize];
}

template<typename T>
SqList<T>::SqList(const T* arr, unsigned length, unsigned maxSize):curSize_(length), maxSize_(maxSize){
    value = new T[maxSize];
    for(unsigned i = 0; i < curSize_; i++){
        value[i] = arr[i];
    }
}

template<typename T>
SqList<T>::SqList(unsigned n, T data, unsigned maxSize):curSize_(n), maxSize_(maxSize) {
    value = new T[maxSize];
    for(unsigned i = 0; i <curSize_; i++){
        value[i] = data;
    }
}
template<typename T>
SqList<T>::SqList(std::istream& is,  unsigned maxSize):curSize_(0), maxSize_(maxSize){
    T data;
    unsigned cnt = 0;
    value = new T[maxSize_];
    while(is >> data && cnt <= maxSize_){
        pushBack(data);
        cnt++;
    }
}

template<typename T>
SqList<T>::~SqList(){
    delete[] value;
}


template<typename T>
void SqList<T>::pushBack(const T& data){
    if(curSize_ >= maxSize_){
        std::cout << "List Overflow!";
        exit(0);
    }
    value[curSize_++] = data;
}

template<typename T>
void SqList<T>::insert(const T& data, unsigned pos){
    if(curSize_ >= maxSize_){
        std::cout << "List Overflow!";
        exit(0);
    }
    if(pos < 0 || pos > curSize_){
        std::cout << "Input Postion Wrong Index!";
        exit(0);
    }
    if(pos == 0){
        for(unsigned i = curSize_ ; i > 0;i--){
            value[i] = value[i - 1];
        }
        value[0] = data;
        curSize_++;
        return;
    }
    if(pos == curSize_ ){
        pushBack(data);
        return;
    }
    for(unsigned i = curSize_ - 1; i >= pos; i--){
        value[i + 1] =value[i]; 
    }
    value[pos] = data;
    curSize_++;
}

template<typename T>
T SqList<T>::erase(unsigned pos){
    if(empty()){
        std::cout << "List Empty!";
        exit(0);
    }
    if(pos < 0|| pos >= curSize_){
        std::cout << "Postion Out Of Limit!";
        exit(0);
    }
    T del = value[pos];
    for(auto i = pos; i < curSize_; i++){
        value[i] = value[i+1];
    }
    curSize_--;
    return del;
}

template<typename T>
unsigned SqList<T>::size(){
    return curSize_;
}

template<typename T>
bool SqList<T>::empty(){
    return curSize_==0;
}

template<typename T>
T* SqList<T>::begin(){
    return value;
}

template<typename T>
T* SqList<T>::end(){
    return value + curSize_;
}

#endif
