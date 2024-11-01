/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string makeFancyString(string s) {
        int j = 2;
        for(int i = 2; i < s.size(); ++i){
            if(s[i] != s[j - 1] || s[i] != s[j - 2]){
                s[j++] = s[i];
            }
        }
        s.resize(min(j,(int)s.size()));
        return s;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.makeFancyString("leeetcode") << endl;
    cout << s.makeFancyString("aaabaaaa") << endl;
    cout << s.makeFancyString("aab") << endl;
}