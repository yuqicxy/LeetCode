/*
 * @lc app=leetcode id=2286 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 */

#include <string>
#include <stack>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minLength(string s) {
        stack<char> mStk;

        for (auto &&character : s)
        {
            if((character == 'B' || character == 'D') && 
            !mStk.empty() && mStk.top() == (character - 1)){
                mStk.pop();
                continue;
            }
            mStk.push(character);
        }
        return (int)mStk.size();
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minLength("ABFCACDB") << endl; 
    cout << s.minLength("ACBBD") << endl; 
}