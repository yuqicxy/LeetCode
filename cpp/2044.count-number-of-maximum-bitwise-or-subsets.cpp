/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */
#include <vector>
#include <iostream>

using namespace std;

class RecursionSolution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int count = 0;
        int maxVal = 0;
        countMax(nums,count, maxVal, 0, 0);
        return count;
    }

    void countMax(vector<int> &nums, int &ans, int &maxVal, int currVal, int i){
        for(int j = i; j < nums.size(); ++j){
            int val = (currVal | nums[j]);
            if(val == maxVal){
                ans += 1;
            }else if(val > maxVal){
                ans = 1;
                maxVal = val;
            }
            countMax(nums, ans, maxVal, val, j + 1);
        }
    }
};

#include <unordered_map>

// @lc code=start
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        unordered_map<int,int> dp{{0,1}}; //默认值， 一个元素都不选的情况下， max为0 数量为1
        for (auto &&num : nums)
        {
            max |= num;
            auto tmp = dp;
            for (auto &&[key, count] : tmp)
            {
                /**
                 *  组合中全部加上当前num，并计算可能值 并加上dp[i]所有中组合的数量
                 */
                dp[key | num] += count;    
            }
        }
        return dp[max];
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{3,1};
    cout << s.countMaxOrSubsets(nums) << endl;
    nums = {2,2,2};
    cout << s.countMaxOrSubsets(nums) << endl;
}