/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/
#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::cin;
using std::cout;
using std::string;

string longestCommonPrefix(vector<string>& strs) {
    if(!strs.size()){
        return "";
    }
    unsigned cur = 0;
    unsigned min = 99999;
    string res;
    for(auto i: strs){
        if(i.size() < min)
            min = i.size();
    }
    for(;cur < min; cur++){
        auto temp = strs[0][cur];
        for(auto i: strs){
            if(i[cur] != temp)
                return res;
        }
        res += temp;
    }
    return res;
}

int main(){
    vector<string> s{"flower","flow","flight"};

}
