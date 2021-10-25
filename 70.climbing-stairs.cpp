/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int oneStepBefore = 2;
        int twoStepsBefore = 1;
        int allways = 0;
        if(n == 0) return allways;
        if(n == 1) return twoStepsBefore;
        if(n == 2) return oneStepBefore;
        for(int i = 3; i <= n ; ++i){
            allways = oneStepBefore + twoStepsBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = allways;
        }
        return allways;
    }
};
// @lc code=end

