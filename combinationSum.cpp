#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }

    void dfs(vector<int>& candidates, int index, int curTarget){
        if(curTarget <= 0)
            return;
        if(curTarget == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] <= curTarget){
                path.push_back(candidates[i]);
                dfs(candidates, i, curTarget-candidates[i]);
                path.pop_back();
            }
        }
        
        
    }
};

int main(){
    Solution s;
    vector<int> c{2,3,4,7};
    auto res = s.combinationSum(c, 7);
    getchar();
}