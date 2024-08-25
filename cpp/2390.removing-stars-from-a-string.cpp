/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */
#include <string>
#include <deque>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        deque<char> stk;
        for(string::size_type i = 0;i < s.size(); ++i){
            if(s[i] != '*'){
                stk.push_back(s[i]);
                continue;
            }
            if(!stk.empty())
                stk.pop_back();
        }

        return string(stk.begin(),stk.end());
    }
};
// @lc code=end

int main(){
    Solution s;
    // string str{"leet**cod*e"};
    string str{"erase*****"};
    std::cout << s.removeStars(str);
}

