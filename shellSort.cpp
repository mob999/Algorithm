#include<vector>
#include<iostream>
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
int main(){
    std::vector<int> arr{8,7,6,5,4,3,2,1};
    shellSort(arr);
    for(auto i:arr){
        std::cout<<i<<" ";
    }
    system("pause");
}  