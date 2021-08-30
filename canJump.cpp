/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 贪心算法
        // 计算每个位置可以跳跃到的最远位置
        // 若最远位置大于等于数组末位置，则可以到达最后一个下标
        int len = nums.size();
        if(len <= 1)
            return true;
        int maxDis = nums[0];
        for(int i = 1; i < len-1; i++){
            if(i <= maxDis)
                maxDis = std::max(maxDis, nums[i] + i);
        }
        return maxDis >= len -1;
    }
};