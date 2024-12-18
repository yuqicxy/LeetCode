/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int N = prices.size();
        stack<int> monoticStk;
        for(int i = 0; i < N; ++i){
            while(!monoticStk.empty() && prices[monoticStk.top()] >= prices[i]){
                prices[monoticStk.top()] = prices[monoticStk.top()] - prices[i];
                monoticStk.pop();
            }
            monoticStk.push(i);
        }
        return prices;
    };
};
// @lc code=end

ostream& operator<<(ostream& ss, vector<int> nums){
    ss << "[";
    for(auto num : nums)
        ss << num << ",";
    ss<<"\b]";
    return ss;
}

int main(){
    Solution s;
    vector prices{8,4,6,2,3};
    cout << s.finalPrices(prices) << endl;
    prices = {1,2,3,4,5};
    cout << s.finalPrices(prices) << endl;
    prices = {8,7,4,2,8,1,7,7,10,1};
    cout << s.finalPrices(prices) << endl;
    return 0;
}