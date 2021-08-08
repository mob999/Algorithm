#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP
#include<bits\stdc++.h>
template<typename T>
class Quick
{
private:
    static int partition(std::vector<T>&, int, int);
    static void sort(std::vector<T>&, int, int);
public:
    static void sort(std::vector<T>&);
};
#ifndef SWAP
#define SWAP
template<typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
#endif
template<typename T>
int Quick<T>::partition(std::vector<T>& arr, int low, int high){
    T partVal = arr[low];
    while(low<high){
        while(low < high && arr[high] >= partVal)
            --high;
        arr[low] = arr[high];
        while(low < high && arr[low] <= partVal)
            ++low;
        arr[high] = arr[low];
    }
    arr[low] = partVal;
    return low;
}
template<typename T>
void Quick<T>::sort(std::vector<T>& arr, int low, int high){
    if(low < high){
        int partLoc = partition(arr, low, high);
        sort(arr, low ,partLoc - 1);
        sort(arr, partLoc + 1, high);
    }
}
template<typename T>
void Quick<T>::sort(std::vector<T>& arr){
    sort(arr, 0, arr.size()-1);
}
#endif