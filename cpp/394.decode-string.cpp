/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
#include <stack>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> bracketStr;
        bracketStr.push("");
        int tmpNum  = 0;
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                tmpNum = tmpNum * 10 + (s[i] - '0');
            }else if(s[i] == '[') {
                bracketStr.push("");
                nums.push(tmpNum);
                tmpNum = 0;
            }
            else if(s[i] == ']'){
                string str = bracketStr.top();
                bracketStr.pop();
                string result = "";
                if(!nums.empty()){
                    int n = nums.top();
                    nums.pop();
                    while(n--){
                        result += str;
                    }
                }
                bracketStr.top() += result;
            }else{
                bracketStr.top() += s[i];
            }
        }
        return bracketStr.top();
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("2[abc]3[cd]ef") << endl;
}