/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
// @lc code=end
#include <iostream>

int main(){
    Solution s;
    cout << s.rotateString("abcde", "cdeab") << endl;
    cout << s.rotateString("abcde", "abced") << endl;
    return 0;
}