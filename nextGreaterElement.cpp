/*
给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<bits\stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> stk;
        unordered_map<int, int> map;
        stk.push_back(nums2[0]);
        auto it = nums2.begin()+1;
        while(it < nums2.end()){
            if(!stk.empty() && *it < stk.back())
                stk.push_back(*it++);
            else if(!stk.empty() && *it > stk.back()){
                while(!stk.empty() && *it > stk.back()){
                    map.insert({stk.back(),*it});
                    stk.pop_back();
                }
            }
            else if(stk.empty())
                stk.push_back(*it++);
            else{
                while(!stk.empty())
                    stk.pop_back();
            }
        }
        for(auto& x: nums1){
            if(map[x] == 0)
                res.push_back(-1);
            else res.push_back(map[x]);
        }

        return res;
    }
};
int main(){
    Solution s;
    unordered_map<int, int> map;
    map.insert()
}