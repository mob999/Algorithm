#include<bits\stdc++.h>
using namespace std;
bool twoSum(vector<int> arr){
    sort(arr.begin(),arr.end());
    for(auto i : arr){
        if (binary_search(arr.begin(),arr.end(),-i)){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> a{3,1,2,4,5,7,9,11,-10};
    vector<int> b{2,1,5,6,0,14,-2};
    for(auto i : a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<(twoSum(a)?"存在":"不存在")<<endl;
    for(auto i : b){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<(twoSum(b)?"存在":"不存在")<<endl;
}