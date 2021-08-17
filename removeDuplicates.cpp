/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<vector>
#include<iostream>
using std::vector;
using std::cout;

int removeDuplicates(vector<int>& nums) {
    auto len = nums.size();
    if(len == 0){
        return 0;
    }
    /* 双指针， 快慢指针 */
    int fast =1, slow =1;
    while(fast < len){
        if(nums[fast] != nums[fast-1]){ // 当快指针走到的位置指向的数不重复时
            nums[slow] = nums[fast];    // 将快指针指向的数拷贝到慢指针的位置
            slow++;                     // 慢指针向前进位
        }
        fast++;
    } 
    return slow;
}


int main(){
    vector<int> nums{0,0,0,0,3};
    auto len = removeDuplicates(nums);
    for(decltype(len) i = 0; i < len; i++){
        cout << nums[i] << ' ';
    }
}