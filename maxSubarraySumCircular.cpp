/*
给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。

在此处，环形数组意味着数组的末端将会与开头相连呈环状。（形式上，当0 <= i < A.length 时 C[i] = A[i]，且当 i >= 0 时 C[i+A.length] = C[i]）

此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。（形式上，对于子数组 C[i], C[i+1], ..., C[j]，不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-circular-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = nums[0], n = nums.size();
        vector<int> maxDP(nums); // 记录非环形数组最大子序和
        vector<int> minDP(nums); // 记录非环形数组最小子序和
        for(int i = 1; i < n; i++){
            maxDP[i] = std::max( maxDP[i-1] + nums[i] , nums[i] );
            minDP[i] = std::min( minDP[i-1] + nums[i] , nums[i] );
            sum += nums[i];
        }
        int maxAns = *max_element(maxDP.begin(), maxDP.end());
        int minAns = *min_element(minDP.begin(), minDP.end());
        // 最大子序和在数组中间时， 其值为maxAns（非环形数组最大子序和）；在数组两边时，为sum-minAns
        // 特殊情况，数组全为负数，sum == minAns， 此时最大子序和为数组中最大的一个数字
        return std::max(maxAns, sum == minAns? maxAns : sum - minAns);
    }
};