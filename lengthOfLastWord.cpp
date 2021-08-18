#include<string>
#include<iostream>
using std::string;
using std::cout;
int lengthOfLastWord(string s) {
    if(s.empty()){
        return 0;
    }
    int curLen = 0;
    bool flag = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ' && flag == true){
            curLen++;
        }
        else if(s[i] != ' ' && flag == false){
            flag = true;
            curLen = 1;
        }
        else{
            flag = false;
        }
    }
    return curLen;
}

int main(){
    string s("Today is a nice day     ");
    cout << lengthOfLastWord(s);
}