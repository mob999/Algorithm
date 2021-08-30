/*
异或运算介绍
异或（xor）是一个数学运算符。它应用于逻辑运算。异或的数学符号为“⊕”，计算机符号为“xor”。
二进制下异或运算法则：
1 xor 1=0
0 xor 0=0
1 xor 0=1
0 xor 1=1
因此十进制下相同数字异或结果为0，数字a与0异或结果仍为原来的数字a。
另外有：

a ⊕ a = 0
a ⊕ b = b ⊕ a
a ⊕ b ⊕ c = a ⊕ (b ⊕ c) = (a ⊕ b) ⊕ c;
a ⊕ b ⊕ a = b.
因此本题中异或全部的元素的结果就是那个只出现1次的元素。

作者：belinda
链接：https://leetcode-cn.com/problems/single-number/solution/rang-ren-tou-tu-de-jie-fa-by-belinda/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<vector>
using std::vector;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(auto x:nums) // 遍历数组
        res ^= x;    // 由于相同数字的异或结果为0， 0与某数字的异或结果为该数字
                     // 所以数组中所有元素的异或结果为只出现一次的数字
    return res;
}