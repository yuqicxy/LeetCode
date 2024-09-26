/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        mFound = vector<bool>((int)nums.size(), false);
        mAns = vector<vector<int>>{};
        mTrack = vector<int>();
        backtrack(nums, 0);
        return mAns;
    }

    void backtrack(vector<int>& nums, int i){
        if(mTrack.size() == nums.size()){
            mAns.push_back(mTrack);
            return;
        }
        for(int j = 0; j < nums.size(); j++){
            if(mFound[j])
                continue;
            mFound[j] = true;
            mTrack.push_back(nums[j]);
            backtrack(nums, i + 1);
            mTrack.pop_back();
            mFound[j] = false;
        }
    }
private:
    vector<bool> mFound;
    vector<vector<int>> mAns;
    vector<int> mTrack;
};
// @lc code=end

int main(){
    Solution s;
    auto num = vector<int>{1,2,3};
    auto res = s.permute(num);
    return 0;
}