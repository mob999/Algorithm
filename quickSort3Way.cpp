#ifndef QUICKSORT3WAY_CPP
#define QUICKSORT3WAY_CPP
#include<bits\stdc++.h>
template<typename T>
class Quick3Way{
    private:
        static void sort(std::vector<T>&, int, int);
    public:
        static void sort(std::vector<T>&);
};

template<typename T>
void swap(T&, T&);

template<typename T>
void Quick3Way<T>::sort(std::vector<T>& arr, int low,  int high){
    if(high <= low) return;
    int lt = low, i = low + 1, gt = high;
    T partVal = arr[low];
    while(i <= gt){
        if(arr[i] < partVal)
            swap(arr[lt++], arr[i++]);
        else if(arr[i] > partVal)
            swap(arr[gt--], arr[i]);
        else i++;
    }
    sort(arr, low, lt-1);
    sort(arr, gt+1, high);
}

template<typename T>
void Quick3Way<T>::sort(std::vector<T>& arr){
    sort(arr, 0, arr.size()-1);
}

template<typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
#endif  