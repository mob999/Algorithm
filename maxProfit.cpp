/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<vector>
#include<iostream>
#include<algorithm>
using std::vector;


int maxProfit(vector<int>& prices){
    prices.push_back(0);
    vector<int> p; // 维护一个单调栈
    int maxAns = 0;
    for(int i = 0; i <prices.size(); i++){
        while(!p.empty() && p.back() > prices[i]){ // 当当前元素小于栈顶元素时， 
                                                //开始弹栈， 直到当前元素不小于栈顶元素
            maxAns = std::max(p.back()-p.front(), maxAns); // 更新最大收益
            p.pop_back();
        }
    p.push_back(prices[i]);
    }
    return maxAns;
}
/*
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
    int maxProfit2(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int maxAns = 0;
        vector<int> st;
        prices.push_back(0);
        for(int i = 0; i< prices.size(); i++){   
            int temp = 0;         
            if(!st.empty() && prices[i] <= st.back()){               
                temp = std::max(temp, st.back() - st.front());
                while(!st.empty())
                    st.pop_back();
            }
            st.push_back(prices[i]);
            maxAns += temp;
        }
        return maxAns;
    }

int main(){
    vector<int> prices{7,1,5,3,6,4};
    auto a = maxProfit2(prices);
    std::cout << a;
}