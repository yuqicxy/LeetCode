/*
 * @lc app=leetcode id=1785 lang=cpp
 *
 * [1785] Minimum Elements to Add to Form a Given Sum
 */

#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        auto leftSum = accumulate(begin(nums),end(nums), static_cast<long long>(goal), minus<long long>());
        return (abs(leftSum) + limit - 1) / limit;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums {1,-1,1};
    cout << s.minElements(nums, 3, -4) << endl;
    nums = {1,-10,9,1};
    cout << s.minElements(nums, 100, 0) << endl;
    nums = {-1,0,1,1,1};
    cout << s.minElements(nums, 1, 771843707) << endl;
}