/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */
#include<vector>
#include<iostream>
using namespace std;

class InitialSolution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int N = prices.size();
        vector<vector<int>> dp(N, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < N; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp.back().front();
    }
};

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int N = prices.size();
        vector<int> curr = {0, -prices[0]};
        for(int i = 1; i < N; ++i){
            curr = {
                max(curr[0], curr[1] + prices[i] - fee),
                max(curr[1], curr[0] - prices[i])
            };
        }
        return curr[0];
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout << s.maxProfit(prices, fee) << endl; //8

    prices = {1,3,7,5,10,3};
    fee = 3;
    cout << s.maxProfit(prices, fee) << endl; //6
    return 0;
}