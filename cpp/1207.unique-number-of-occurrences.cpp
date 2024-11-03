/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mFreq;
        for(auto num : arr)
            mFreq[num]++;
        unordered_set<int> mUnique;
        for(auto item : mFreq){
            if(!mUnique.insert(item.second).second)
                return false;
        }
        return true;
    }
};
// @lc code=end

#include <iostream>

int main(){
    Solution s;
    vector nums{1,2,2,1,1,3};
    cout << s.uniqueOccurrences(nums) << endl;
    nums = {1,2};
    cout << s.uniqueOccurrences(nums) << endl;
    nums = {-3,0,1,-3,1,1,1,-3,10,0};
    cout << s.uniqueOccurrences(nums) << endl;
    return 0;
}