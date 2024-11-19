/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <exception>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        array<array<short, 1001>,1001> m{};
        for (auto i = 0; i < text1.size(); ++i)
            for (auto j = 0; j < text2.size(); ++j)
                m[i + 1][j + 1] = text1[i] == text2[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
        return m[text1.size()][text2.size()];
    }
};
// @lc code=end

int main(){
    Solution s;
    string text1 = "abcde", text2 = "ace";
    cout << s.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}