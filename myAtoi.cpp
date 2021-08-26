#include<string>
#include<iostream>
class Solution{
public:
    int myAtoi(std::string s){
        if(!pretreat(s))
            return 0;
        long long cnt = 1;
        for(int i = left; isdigit(s[i]); i++){
            if(postive*cnt > INT_MAX)
                return INT_MAX;
            if(postive*cnt < INT_MIN)
                return INT_MIN;
            cnt *= 10;
        }
        for(int i = left; isdigit(s[i]); i++){
            if(postive *res > INT_MAX)
                return INT_MAX;
            if(postive*res < INT_MIN) 
                return INT_MIN;
            cnt /= 10;
            res += cnt*(s[i]-'0');    
        }
        if(postive*res > INT_MAX) return INT_MAX;
        if(postive*res < INT_MIN) return INT_MIN;
        return postive*res;
    }
private:
    long long res = 0;
    int postive;
    int left;
    int right;
    bool removeOthersPre(std::string& s){
        left = 0;
        right = s.size()-1;
        while(left <= right){
            if(s[left] == '+' || s[left] == '-' || isdigit(s[left]))
                break;
            if(s[left] == ' ')
                left++;
            else return false;
        }
        return true;
    }
    bool isPostive(const std::string& s){
        if(s[left] == '+' ){
            left++;
            return true;
        }
        if(s[left] == '-'){
            left++;
            return false;
        }
        return true;
        
    }
    void removePreZero(std::string& s){
        for(int i = left ; s[i] == '0'; i++,left++);
    }
    bool pretreat(std::string& s){
        if(!removeOthersPre(s))
            return false;
        postive = isPostive(s)?1:-1;
        removePreZero(s);
        return true;
    }
};

int main(){
    Solution s;
    std::cout << s.myAtoi("00000"); 
}