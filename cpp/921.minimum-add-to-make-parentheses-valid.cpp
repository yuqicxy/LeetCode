/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */
#include <string>
#include <iostream>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(auto character : s){
            if(character == '('){
                stk.push(character);
            }else if(!stk.empty()  && stk.top() == '('){
                stk.pop();
            }else{
                stk.push(character);
            }
        }
        return (int)stk.size();
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minAddToMakeValid("())") << endl;
    cout << s.minAddToMakeValid("(((") << endl;
}