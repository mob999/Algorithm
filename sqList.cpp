#ifndef SQLIST_CPP
#define SQLIST_CPP
#define DEFAULT_SIZE 1000
#include<vector>
#include<iostream>
template<typename T>
class SqList{
private:
    T* val;
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
    T* begin();
    T* end();
    friend void print(const SqList<T>& list, std::ostream& os = std::cout){
        for(unsigned i = 0; i < list.curSize_; i++){
            os << list.val[i]<< " ";
        }
    }
};

template<typename T>
SqList<T>::SqList(const std::vector<T>& arr, unsigned maxSize):curSize_(arr.size()), maxSize_(maxSize){
    val = new T[maxSize];
    for(unsigned i = 0; i < curSize_; i++){
        val[i] = arr[i];
    }
}

template<typename T>
SqList<T>::SqList(unsigned maxSize):curSize_(0), maxSize_(maxSize){
    val = new T[maxSize];
}

template<typename T>
SqList<T>::SqList(const T* arr, unsigned length, unsigned maxSize):curSize_(length), maxSize_(maxSize){
    val = new T[maxSize];
    for(unsigned i = 0; i < curSize_; i++){
        val[i] = arr[i];
    }
}

template<typename T>
SqList<T>::SqList(unsigned n, T data, unsigned maxSize):curSize_(n), maxSize_(maxSize) {
    val = new T[maxSize];
    for(unsigned i = 0; i <curSize_; i++){
        val[i] = data;
    }
}
template<typename T>
SqList<T>::SqList(std::istream& is,  unsigned maxSize):curSize_(0), maxSize_(maxSize){
    T data;
    unsigned cnt = 0;
    val = new T[maxSize_];
    while(std::cin >> data && cnt <= maxSize_){
        pushBack(data);
    }
}
template<typename T>
SqList<T>::~SqList(){
    delete[] val;
}

template<typename T>
void SqList<T>::pushBack(const T& data){
    if(curSize_ >= maxSize_){
        std::cout << "List Overflow!";
        exit(0);
    }
    val[curSize_++] = data;
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
            val[i] = val[i - 1];
        }
        val[0] = data;
        curSize_++;
        return;
    }
    if(pos == curSize_ ){
        pushBack(data);
        return;
    }
    for(unsigned i = curSize_ - 1; i >= pos; i--){
        val[i + 1] =val[i]; 
    }
    val[pos] = data;
    curSize_++;
}

template<typename T>
unsigned SqList<T>::size(){
    return curSize_;
}

#endif
int main(){
    SqList<int> sq(std::cin);
    std::cout << sq.size()<< std::endl;
    print(sq);
    sq.pushBack(4);
    print(sq);
    sq.insert(0,0);
    print(sq);
    sq.insert(5,5);
    print(sq);
    sq.insert(100,4);
    print(sq);
}
