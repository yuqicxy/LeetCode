/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // iterative method
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        results.push_back(vector<int>());

        for(unsigned i = 0; i < nums.size(); ++i){
            int tmp = nums[i];
            int resultNum = results.size();
            for(unsigned j = 0; j < resultNum; ++j)
            {   
                results[j].push_back(tmp);
                results.push_back(results[j]);
                results[j].pop_back();
            }
        }
        return results;
    }

    // recursive method
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> results;
    //     vector<int> lastResult;
    //     pick(nums,0,lastResult,results);
    //     return results;
    // }
    //
    // void pick(vector<int>& nums,int i,vector<int> lastResult,vector<vector<int>> &results){
    //     results.push_back(lastResult);
    //     for(int j = i; j < nums.size(); ++j){
    //         lastResult.push_back(nums[j]);
    //         pick(nums,j + 1,lastResult,results);
    //         lastResult.pop_back();
    //     }
    // }
};
// @lc code=end

