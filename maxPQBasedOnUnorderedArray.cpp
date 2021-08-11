#ifndef MAXPQUA_CPP
#define MAXPQUA_CPP
#include<vector>
#include "quickSort.cpp"
template<typename T>
class MaxPQUA{
private:
    std::vector<T> val;
    bool isSorted;
public:
    MaxPQUA();
    MaxPQUA(std::istream&);
    MaxPQUA(const std::vector<T>&);
    void insert(T);
    T max();
    T delMax();
    bool empty();
    unsigned size();
};

template<typename T>
MaxPQUA<T>::MaxPQUA():isSorted(false){ }

template<typename T>
MaxPQUA<T>::MaxPQUA(std::istream& is):isSorted(false){
    T data;
    while(is >> data){
        val.push_back(data);
    }
}

template<typename T>
MaxPQUA<T>::MaxPQUA(const std::vector<T>& arr):isSorted(false){
    for(auto i : arr){
        val.push_back(i);
    }
}

template<typename T>
void MaxPQUA<T>::insert(T key){
    if(key < val[val.size()-1])
        isSorted = false;
    val.push_back(key);
}

template<typename T>
T MaxPQUA<T>::max(){
    if(empty()){
        exit(0);
    }
    if(isSorted){
        return val[val.size()-1];
    }
    Quick<T>::sort(val);
    isSorted = true;
    return val[val.size()-1];
}

template<typename T>
T MaxPQUA<T>::delMax(){
    if(empty()){
        exit(0);
    }
    T res;
    if(isSorted){
        res = val[val.size()-1];
        val.erase(val.end()-1);
        return res;
    }
    Quick<T>::sort(val);
    isSorted = true;
    res = val[val.size()-1];
    val.erase(val.end()-1);
    return res;
}

template<typename T>
bool MaxPQUA<T>::empty(){
    return val.empty();
}

template<typename T>
unsigned MaxPQUA<T>::size(){
    return val.size();
}

#endif
