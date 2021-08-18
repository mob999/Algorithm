/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。
*/

#include<string>
#include<iostream>
using std::string;
using std::cout;

int lengthOfLastWord(string s) {
    int len = s.size() - 1;
    int res = 0;
    if(len == -1)
        return 0;
    while(len >= 0 && s[len] == ' '){
        len--;
    }
    while(len >= 0 && s[len] !=' '){
        res++;
        len--;
    }
    return res;
}


int main(){
    string s("Today is a nice day     ");
    cout << lengthOfLastWord(s);
}