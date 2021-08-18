/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/

#include<vector>
#include<iostream>

using std::vector;
using std::cout;

int maxSubArray(vector<int>& nums){
    int pre = 0, maxAns = nums[0]; // pre用于记录前驱总和， maxAns记录连续子序列最大值
    for(const auto& x: nums){
        pre = x>(pre+x)?x:(pre+x); // 若前驱总和与当前数之和大于当前数， 则前驱总和更新为与当前数之和
                                   // 若前驱总和与当前数之和小于当前数， 则从当前数开始重新计算前驱总和
        maxAns = maxAns>pre?maxAns:pre; // 对连续子序列最大值更新
    }
    return maxAns;
}

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
}
