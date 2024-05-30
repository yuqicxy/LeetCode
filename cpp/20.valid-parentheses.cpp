/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack; 
        for(unsigned i = 0; i < s.length(); ++i){
            const char c = s.at(i);
            if(c == '(' || c == '[' || c == '{'){
                charStack.push(c);
                continue;
            }
            else if(!charStack.empty()){
                const char s = charStack.top();
                if((s == '(' && c == ')') || (s == '[' && c == ']') || (s == '{' && c == '}'))
                {
                    charStack.pop();
                    continue;
                }   
            }
            return false;
        }
        if(charStack.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end

int main(){
    Solution solu;
    std::cout << solu.isValid("(]");
}