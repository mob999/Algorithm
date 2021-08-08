#ifndef SELECTSORT_CPP
#define SELECTSORT_CPP
#include<bits\stdc++.h>
template<typename T>
void swap(T& a,T& b){
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
void selectSort(std::vector<T>& arr){
    for(decltype(arr.size()) i = 0;i < arr.size();i++){
        T minNum=arr[i];
        int minNumPos=0;
        int flag =  0;
        for(auto j = i;j < arr.size();j++){
            if(arr[j]<minNum){
                minNum=arr[j];
                minNumPos=j;
                flag=1;
            }
        }
        if(flag){
            swap(arr[i],arr[minNumPos]);
        }
    }
}
#endif