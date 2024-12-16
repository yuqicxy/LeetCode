/*
 * @lc app=leetcode id=3264 lang=cpp
 *
 * [3264] Final Array State After K Multiplication Operations I
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int, int>> h(nums.size());
        for(int i = 0; i < nums.size(); ++i)
            h[i] = {nums[i], i};
        make_heap(h.begin(), h.end(),greater<>{});
        while(k--){
            pop_heap(h.begin(),h.end(),greater<>{});
            h.back().first = multiplier * h.back().first;
            nums[h.back().second] = h.back().first;
            push_heap(h.begin(), h.end(),greater<>{});
        }
        return nums;
    }
};
// @lc code=end

ostream& operator<<(ostream& ss, vector<int> nums){
    ss << "[";
    for(auto num : nums){
        ss << num << ",";
    }
    ss<<"\b]";
    return ss;
}

int main(){
    Solution s;
    vector nums{2,1,3,5,6};
    cout << s.getFinalState(nums, 5, 2) << endl; //Output: [8,4,6,5,6]
    nums = {1,2};
    cout << s.getFinalState(nums, 3, 4) << endl; //Output: [16,8]
}