/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(unsigned i = 0; i < prices.size(); ++i){
            minPrice = min(minPrice,prices[i]);
            maxPro = max(maxPro,prices[i] - minPrice);
        }
        return maxPro;
    }
};
// @lc code=end
