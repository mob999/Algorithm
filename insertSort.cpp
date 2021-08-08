#ifndef INSERTSORT_CPP
#define INSERTSORT_CPP
#include<bits\stdc++.h>
template<typename T>
void swap(T& a,T& b){
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
void insertSort(std::vector<T>& arr){
    for(decltype(arr.size()) i = 1; i < arr.size(); i++){
        for(auto j = i;j > 0&& arr[j] < arr[j-1]; j--){
            swap(arr[j],arr[j-1]);
        }
    }
}
#endif