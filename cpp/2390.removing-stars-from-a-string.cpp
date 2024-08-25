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
        string result;
        for(string::size_type i = 0;i < s.size(); ++i){
            if(s[i] != '*'){
                result += s[i];
                continue;
            }
            if(!result.empty())
                result.pop_back();
        }

        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    // string str{"leet**cod*e"};
    string str{"erase*****"};
    std::cout << s.removeStars(str);
}

