/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result(spells.size(),0);
        sort(potions.begin(),potions.end());
        for(size_t i = 0;i < spells.size(); ++i){
            float val = success / float(spells[i]);
            result[i] = binarySearch(potions, spells[i], success);
        }
        return result;
    }

    int binarySearch(vector<int> & potions,int multiply, long long val){
        int upper = potions.size() - 1;
        int lower = 0;
        int mid = 0;
        while(lower <= upper){
            mid = (upper - lower) / 2 + lower;
            if((long long)potions[mid] * (long long)multiply >= val)
                upper = mid - 1;
            else
                lower = mid + 1;
        }
        return (int)potions.size() - (1 + upper);
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> spells;
    vector<int> potions;
    spells = {5,1,3};
    potions = {1,2,3,4,5};
    // [4,0,3]
    auto res = s.successfulPairs(spells,potions,7);
    spells = {3,1,2};
    potions = {8,5,8};
    // [2,0,2]
    auto res2 = s.successfulPairs(spells,potions,16);
}

