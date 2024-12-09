/*
 * @lc app=leetcode id=3152 lang=cpp
 *
 * [3152] Special Array II
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//Time exceed solution
class MySolution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> parity(nums.size() - 1 , false);
        for(int i = 0; i < nums.size() - 1; ++i)
            parity[i] = static_cast<bool>((nums[i] + nums[i + 1])%2);
        vector<bool> ans(queries.size(), true);
        for(int q = 0; q < queries.size(); ++q){
            for(int i = queries[q][0]; i < queries[q][1]; ++i){
                if(!parity[i]){
                    ans[q] = false;
                    break;
                }
            }
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ps{0};
        for(int i = 0; i < nums.size() - 1; ++i)
            ps.push_back(ps.back() + (nums[i] % 2 == nums[i + 1] % 2));
        vector<bool> ans;
        for(const auto& query: queries)
            ans.push_back(ps[query[0]] == ps[query[1]]);
        return ans;
    }
};
// @lc code=end

ostream& operator<<(ostream& ss, const vector<bool>& result){
    ss<<"[";
    ss<<boolalpha;
    for(auto b : result){
        ss << b << ",";
    }
    ss<<noboolalpha;
    ss<<"\b" << "]";
    return ss;
}

int main(){
    Solution s;
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0,4}};
    cout << s.isArraySpecial(nums,queries) << endl; //[false]
    nums = {4,3,1,6}; 
    queries = {{0,2},{2,3}};
    cout << s.isArraySpecial(nums,queries) << endl; //[false, true]
    nums = {1, 8};
    queries = {{1,1}};
    cout << s.isArraySpecial(nums,queries) << endl; //[true]
    nums = {1, 8};
    queries = {{0,0}};
    cout << s.isArraySpecial(nums,queries) << endl; //[true]
    nums = {9,7,4};
    queries = {{1,1}};
    cout << s.isArraySpecial(nums,queries) << endl; //[true]
}
