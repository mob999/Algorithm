#ifndef MAXPQOA_CPP
#define MAXPQOA_CPP
#include "sqList.cpp"

template<typename T>
class MaxPQOA{
private:
    SqList<T> val;
public:
    MaxPQOA(unsigned max=DEFAULT_SIZE);
    MaxPQOA(std::istream&);
    MaxPQOA(const std::vector<T>&);
    void insert(const T&);
    T max();
    T delMax();
    bool empty();
    unsigned size();
    friend void traverse(MaxPQOA<T>& pq, std::ostream& os=std::cout){
        for(auto i = pq.val.begin(); i < pq.val.end(); i++){
            os << *i << ' ';
        }
    }
};

template<typename T>
MaxPQOA<T>::MaxPQOA(unsigned max):val(max){}

template<typename T>
MaxPQOA<T>::MaxPQOA(std::istream& is):val(){
    T data;
    while(is >> data){
        insert(data);
    }
}

template<typename T>
MaxPQOA<T>::MaxPQOA(const std::vector<T>& arr):val(){
    for(auto i : arr){
        insert(i);
    }
}

template<typename T>
void MaxPQOA<T>::insert(const T& data){
    if(size() == 0 ){
        val.pushBack(data);
        return;
    }
    unsigned i = 0;
    for(i = 0; val[i] < data && i < size(); i++);
    val.insert(data, i);   
}

template<typename T>
T MaxPQOA<T>::max(){
    if(empty()){
        std::cout<< "PQ Empty!";
        exit(0);
    }
    return val[size()-1];
}

template<typename T>
T MaxPQOA<T>::delMax(){
    if(empty()){
        std::cout<< "PQ Empty!";
        exit(0);
    }
    T del = val[size()-1];
    val.erase(size()-1);
    return del;
}

template<typename T>
bool MaxPQOA<T>::empty(){
    return val.empty();
}

template<typename T>
unsigned MaxPQOA<T>::size(){
    return val.size();
}
#endif

#define MAIN
int main(){
    MaxPQOA<int> pq(std::vector<int>{1,2,3});
    pq.insert(10);
    pq.insert(20);
    pq.insert(15);
    traverse(pq);
    pq.delMax();
    traverse(pq);
}