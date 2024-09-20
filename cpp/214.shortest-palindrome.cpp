/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        string revetStr = s;
        reverse(revetStr.begin(), revetStr.end());
        string tmp = s;
        tmp += "#";
        tmp += revetStr;
        auto pi = calKMPPrefixArray(tmp);
        revetStr = s.substr(pi[pi.size() - 1]);
        reverse(revetStr.begin(), revetStr.end());
        return(revetStr + s);
    }

    vector<int> calKMPPrefixArray(const string& pattern){
        vector<int> pi(pattern.size(), 0);
        for(int i = 1; i < pattern.size(); ++i){
            int j = pi[i - 1];
            while(j > 0 && pattern[i] != pattern[j])
                j = pi[j - 1];
            if(pattern[i] == pattern[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
};
// @lc code=end
int main(){
    Solution s;
    cout << s.shortestPalindrome("abcd") << endl;
    cout << s.shortestPalindrome("aacecaaa") << endl;

}
