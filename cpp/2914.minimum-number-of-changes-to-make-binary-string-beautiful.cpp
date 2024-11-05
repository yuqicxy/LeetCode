/*
 * @lc app=leetcode id=2914 lang=cpp
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

#include<string>
#include<iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i+=2)
            ans = s[i] == s[i + 1] ? ans : ans + 1;
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minChanges("1001") << endl;
    cout << s.minChanges("10") << endl;
    cout << s.minChanges("0000") << endl;
    cout << s.minChanges("11000111") << endl; //1
}