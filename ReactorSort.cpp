#ifndef REACTORSORT_CPP
#define REACTORSORT_CPP
#include<vector>
#include<iostream>
template<typename T>
class BinaryReactor{
public:
    static void sort(std::vector<T>&);
private:
    static void sink(std::vector<T>& arr,unsigned index, unsigned n);
};
template<typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
void BinaryReactor<T>::sort(std::vector<T>& arr){
    int n = arr.size()-1;
    for(int k = n/2; k >= 1; k--){
        sink(arr, k, n);
    }
    while(n > 1){
        /* 
         * 一段不优雅的特判 
         * 出现此类问题的原因未知
        */
        // TODO Make it clear
        if(n == 2 && arr[1] < arr[2]){
            break;
        }
        swap(arr[1], arr[n--]);
        sink(arr, 1, n);
    }
}

template<typename T>
void BinaryReactor<T>::sink(std::vector<T>& arr,unsigned index, unsigned n){
    while(2*index <= n-1){
        auto son = 2*index;
        if(son < arr.size() && arr[son] < arr[son+1])
            son++;
        if(arr[index] >= arr[son])
            break;
        swap(arr[index], arr[son]);
        index = son;
    }
}

int main(){
    std::vector<int> ve{0,9,8,7,6,5,5,4,1,3};
    BinaryReactor<int>::sort(ve);
    for(auto i: ve){
        std::cout << i << ' ';
    }
}
#endif