/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() < 2)
            return cost.back();
        int dp0 = cost[0];
        int dp1 = cost[1];
        for(int i = 2; i < cost.size(); ++i){
            int tmp = dp1;
            dp1 = min(dp1, dp0) + cost[i];
            dp0 = tmp;
        }
        return min(dp1, dp0);
    }
};
// @lc code=end
#include <iostream>
int main(){
    Solution s;
    vector cost{10,15,20};
    cout << s.minCostClimbingStairs(cost) << endl;
    cost = {1,100,1,1,1,100,1,1,100,1};
    cout << s.minCostClimbingStairs(cost) << endl;
}