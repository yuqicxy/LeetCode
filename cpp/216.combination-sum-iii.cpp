/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */
#include <vector>
#include <iostream>
#include <ostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> prev;
        combination(1,9,k,n,prev,ans);
        return ans;
    }

    void combination(int start, int end, int k, int n,vector<int> &prev,vector<vector<int>> &ans){
        if(start > n) return;
        for(auto i = start; i < end + 1; ++i){
            prev.push_back(i);
            if(prev.size() == k && i == n)
                ans.push_back(prev);
            else
                combination(i + 1, end, k, n - i, prev, ans);
            prev.pop_back();
        }
    }
};
// @lc code=end

std::ostream& operator<<(std::ostream &ss, const vector<int>& nums){
    ss << "[";
    for(auto num : nums){
        ss << num << ",";
    }
    ss <<"\b"<<"]";
    return ss;
}

ostream& operator<<(ostream &ss, const vector<vector<int>>& nums){
    ss << "[";
    for(auto num : nums){
        ss << num << ",";
    }
    ss << "\b" <<"]";
    return ss;
}

int main(){
    Solution s;

    auto ans = s.combinationSum3(3,7);
    cout << ans << endl;

}

