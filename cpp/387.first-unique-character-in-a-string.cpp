/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        //pair<count,pos>
        unordered_map<char, pair<int, int>> m; 
        int idx = s.length();
        for (int i = 0; i < s.length(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for (auto &p : m) {
            if (p.second.first == 1) idx = min(idx, p.second.second);
        }
        return idx == s.length() ? -1 : idx;
    }
};
// @lc code=end

