/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;
// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char, int> vowelsMask{{'a', 1}, {'e', 2},{'i', 4}, {'o', 8},{'u', 16}};
        int mask = 0;
        vector<int> stores(32,-1);
        int ans = 0;
        for(int  i = 0; i < s.size(); ++i){
            auto itr = vowelsMask.find(s[i]);
            if(itr != vowelsMask.end())
                mask ^= itr->second;
            if(mask != 0 && stores[mask] == -1)
                stores[mask] = i;
            ans = max(ans , i - stores[mask]);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    // cout << s.findTheLongestSubstring("eleetminicoworoep") << endl;
    // cout << s.findTheLongestSubstring("leetcodeisgreat") << endl;
    cout << s.findTheLongestSubstring("ee") << endl;
}

