#include<vector>
#include<iostream>
using std::vector;
using std::cout;

int searchInsert(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return 0;
    int low = 0, high = nums.size() - 1;
    int mid = (low + high) / 2;
    while(low <= high){
        
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else if(nums[mid] > target){
            high = mid -1;
        }
        mid = low + (high - low) / 2;
    }
    return nums[mid]>target?mid:mid+1;
}

int main(){
    vector<int> a1{1,3,5,6};
    cout << searchInsert(a1,0);
}