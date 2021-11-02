/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        std::vector<int> result(2,1);
        if(rowIndex == 1) return result;
        for(unsigned i = 2; i <= rowIndex; ++i){
            int size = result.size();
            for(unsigned j = 0;j < size - 1; ++j){
                result[j] = result[j] + result[j+1];
            }
            result.insert(result.begin(),1);
        }
        return result;
    }
};
// @lc code=end