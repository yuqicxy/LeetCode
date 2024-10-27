/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string &mateched = strs.front();
        for(int i = 1; i < strs.size(); ++i){
            int sz = min(mateched.size(), strs[i].size());
            if(sz < 1) return "";
            int j = 0;
            for(;j < sz; ++j){
                if(mateched[j] != strs[i][j]){
                    break;
                }
            }
            mateched = mateched.substr(0,j);
        }
        return mateched;
    }
};
// @lc code=end

