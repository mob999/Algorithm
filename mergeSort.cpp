#include<bits\stdc++.h>
template<typename T>
class Merge{
    private:
        static void merge(std::vector<T>&,int,int,int,std::vector<T> aux);
    public:
        static void sort(std::vector<T>& arr, int, int,std::vector<T> aux);
        static void sort(std::vector<T>& arr);
};
template<typename T>
void Merge<T>::merge(std::vector<T>& arr,int low,int high,int mid,std::vector<T> aux){
    int i = low;
    int j = mid+1;
    for(int k = 0; k <= high; k++){
        aux.push_back(arr[k]);
    }
    for(int k = low; k<=high; k++){
        if(i > mid)
            arr[k] = aux[j++];
        else if(j > high)
            arr[k] = aux[i++];
        else if(aux[j] < aux[i])
            arr[k] = aux[j++];
        else 
            arr[k] = aux[i++];
    }
}
template<typename T>
void Merge<T>::sort(std::vector<T>& arr, int low, int high,std::vector<T> aux){
    if(high <= low)
        return;
    int mid = low + (high-low)/2;
    sort(arr, low, mid,aux);
    sort(arr, mid+1, high,aux);
    merge(arr, low, high, mid,aux);
}
template<typename T>
void Merge<T>::sort(std::vector<T>& arr){
    std::vector<T> aux;
    sort(arr,0,arr.size()-1,aux);
}
int  main(){
    std::vector<int> arr{5,2,3,4,56,12,4};
    Merge<int>::sort(arr);
    for(auto i:arr){
        std::cout<<i<<" ";
    }
}