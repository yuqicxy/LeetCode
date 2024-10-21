/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set{};
        return maxUniqueSplit(s, 0, set);
    }

    int maxUniqueSplit(const string &s, int pos, unordered_set<string> &set){
        if ( pos >= s.size()) return 0;
        int maxLen = -1;
        for(int i = 1; i <= s.size() - pos; ++i){
            auto tmp = s.substr(pos, i);
            auto itr = set.begin();
            bool inserted = false;
            tie(itr, inserted) = set.insert(tmp);
            if(inserted)
            {
                maxLen = max(maxLen, 1 + maxUniqueSplit(s, pos + i, set));
                set.erase(itr);
            }
        }
        return maxLen;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.maxUniqueSplit("ababccc") << endl;
    cout << s.maxUniqueSplit("aba") << endl;
    cout << s.maxUniqueSplit("aa") << endl;
}