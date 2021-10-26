/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
/**
 * @brief 
 *Example:
 *   isMatch("aa","a") → false
 *   isMatch("aa","aa") → true
 *   isMatch("aaa","aa") → false
 *   isMatch("aa", "a*") → true
 *   isMatch("aa", ".*") → true
 *   isMatch("ab", ".*") → true
 *   isMatch("aab", "c*a*b") → true
 * 
 */
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @brief recursive solution
     * 
     * @param s input string
     * @param p pattern
     * @return true  successful match
     * @return false failure
     */
    // bool isMatch(string s, string p) {
    //     if(p.empty()) return s.empty();
    //     if(p[1]=='*'){
    //         return (isMatch(s,p.substr(2)) || !s.empty())
    //         && ((s[0] == p[0] ||  p[0] == '.') && isMatch(s.substr(1),p));
    //     }
    //     else
    //     {
    //         return (!s.empty()
    //         && (s[0] == p[0] || p[0] == '.')
    //         && isMatch(s.substr(1),p.substr(1)));
    //     }
    // }

    //Dynamic programming method
    bool isMatch(string s, string p) {
        //TBD
    }
};
// @lc code=end

