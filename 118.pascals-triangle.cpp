/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        results.push_back({1});
        if(numRows == 1) return results;
        results.push_back({1,1});
        if(numRows == 2) return results;
        for(unsigned i = 3; i <= numRows; ++i){
            vector<int> result = results.back();
            int size = result.size();
            for(unsigned j = 0;j < size - 1; ++j){
                result[j] = result[j] + result[j+1];
            }
            result.insert(result.begin(),1);
            results.push_back(result);
        }
        return results;
    }
};
// @lc code=end

