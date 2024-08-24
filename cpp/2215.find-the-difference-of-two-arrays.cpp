/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1{nums1.begin(),nums1.end()};
        unordered_set<int> set2{nums2.begin(),nums2.end()};

        vector<vector<int>> result;
        result.push_back(implement(set1,set2));
        result.push_back(implement(set2,set1));
        return result;
    }

    vector<int> implement(unordered_set<int>& nums, unordered_set<int>& dict){
        vector<int> tmp;
        tmp.reserve(max(nums.size(),dict.size()));

        for(auto i : nums){ 
            if(dict.count(i) == 0)
                tmp.push_back(i);
        }
        return tmp;
    }
};
// @lc code=end

int main(){
    vector<int> nums1{1,2,3,3};
    vector<int> nums2{1,1,2,2};
    Solution s;
    s.findDifference(nums1,nums2);
    return 0;
}