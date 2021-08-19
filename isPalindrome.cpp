/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
*/  
#include<string>
#include<iostream>
using std::string;    

bool isPalindrome(string s) {
    int begin = 0, end = s.size()-1;
    while(begin < end){
        while(begin<end && !isalnum(s[begin])) begin += 1;
        while(begin<end && !isalnum(s[end])) end -= 1;
        if(tolower(s[begin]) != tolower(s[end]))
            return false;
        begin += 1;
        end -= 1;
    }
    return true;
}

int main(){
    std::cout << isPalindrome("A man, a plan, a canal: Panama");
}