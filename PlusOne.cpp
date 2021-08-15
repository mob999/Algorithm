/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;

vector<int> plusOne(vector<int>& digits){
    for(int i = digits.size()-1; i >= 0; i--){
        digits[i]++;
        if(digits[i]%10 != 0)
            return digits;
        digits[i] = 0;
    }

    vector<int> arr(digits.size()+1, 0);
    arr[0] = 1;   
    return arr;   

   
}

int main(){
    vector<int> di{9,9,9,9,9};
    auto res =plusOne(di);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}