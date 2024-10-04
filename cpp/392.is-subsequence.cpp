/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t N = s.size();
        size_t M = t.size();
        size_t j = 0;
        for(size_t i = 0; i < M && j < N; ++i){
            if(t[i] == s[j])
                ++j;
        }
        return j == N;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha << s.isSubsequence("abc", "ahbgdc") << endl;
    cout << boolalpha << s.isSubsequence("axc", "ahbgdc") << endl;
}
