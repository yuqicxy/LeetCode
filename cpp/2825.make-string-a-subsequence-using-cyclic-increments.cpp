/*
 * @lc app=leetcode id=2825 lang=cpp
 *
 * [2825] Make String a Subsequence Using Cyclic Increments
 */

#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        const int diff = 'a' - 'z';
        int i = 0, j = 0;
        const int n = str1.size();
        const int m = str2.size();
        while(i < n && j < m){
            int res = str2[j] - str1[i];
            if(res == 0 || res == 1 || res == diff )
                ++j;
            ++i;
        }
        return j == m;
    }
};
// @lc code=end

int main(){
    Solution s;
    string str1 = "abc", str2 = "ad";
    cout << boolalpha;
    cout << s.canMakeSubsequence(str1, str2) << endl;
    str1 = "zc", str2 = "ad";
    cout << s.canMakeSubsequence(str1, str2) << endl;
    str1 = "ab", str2 = "d";
    cout << s.canMakeSubsequence(str1, str2) << endl;
}