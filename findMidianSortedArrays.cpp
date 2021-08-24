#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while(it1 < nums1.end() && it2 < nums2.end()){
            if(*it1 < * it2){
                nums3.push_back(*it1);
                it1++;
            }
            else{
                nums3.push_back(*it2);
                it2++;
            }
        }
        while(it1 < nums1.end()){
            nums3.push_back(*it1);
            it1++;
        }
        while(it2 < nums2.end()){
            nums3.push_back(*it2);
            it2++;
        }
        int len = nums3.size();
        if(len == 1)
            return nums3[0];
        if(len % 2 !=0)
            return nums3[len/2];
        else{double res = nums3[len/2-1] + nums3[len/2];
        return res/2;}
    }
};

int main(){
    Solution s;
    vector<int> n1{1,3};
    vector<int> n2{2};
    cout << s.findMedianSortedArrays(n1, n2);
}