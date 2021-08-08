#ifndef SHELLSORT_CPP
#define SHELLSORT_CPP
#include<vector>
template<typename T>
void swap(T& a,T& b){
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
void shellSort(std::vector<T>& arr){
    auto n = arr.size();
    decltype(n) h = 1;
    while (h < n/3){
        h = 3*h + 1;
    }
    while(h >= 1){
        for(auto i = h;i < n;i++){
            for(auto j = i;j >= h &&arr[j] < arr[j-h];j-=h){
                swap(arr[j],arr[j-1]);
            }
        }
        h /= 3;
    }   
}
#endif