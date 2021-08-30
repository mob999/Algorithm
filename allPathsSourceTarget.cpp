/*
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些节点，空就是没有下一个结点了。

译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a 。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-paths-from-source-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> stk;
    void dfs(vector<vector<int>>& graph, int from, int to){
        if(from == to){
            ans.push_back(stk);
            return;
        }
        for(auto& y: graph[from]){
            stk.push_back(y);
            dfs(graph, y, to);
            stk.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stk.push_back(0);
        dfs(graph, 0, graph.size()-1);
        return ans;
    }
};