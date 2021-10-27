/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> leftBracketStack;
        leftBracketStack.push(-1);
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '(')
                leftBracketStack.push(i);
            else{
                leftBracketStack.pop();
                if(leftBracketStack.empty()){
                    leftBracketStack.push(i);
                }else{
                    ans = max(ans,i - leftBracketStack.top());
                }
            }
        }
        return ans;
    }
};
// @lc code=end

