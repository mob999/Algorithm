/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};  
        vector<string> res;
        if(digits == "") return res;
        func(res, "", digits, table, 0);
        return res;
    }
    void func(vector<string>& res, string str, string& digits, unordered_map<char,string>& m, int k){
        if(str.size() == digits.size()){
            res.push_back(str);
            return;
        }
        auto temp = m[digits[k]];
        for(auto w: temp){
            str += w;
            func(res, str, digits, m, k+1);
            str.pop_back();
        }
    }
};