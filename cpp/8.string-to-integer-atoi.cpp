/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if(s.empty())   return 0;
        int i = 0;
        int result = 0;
        int sign = 1;
        while(i < s.length()){
           if(s.at(i) == ' ')
                ++i;
            else
                break;
        }
        if(i < s.length() && (s.at(i) == '+' || s.at(i) == '-'))
            sign = 1 - 2 * (s.at(i++) == '-');

        while(i < s.length())
        {
            if(s.at(i) >= '0' && s.at(i) <= '9'){
                int digit = s.at(i) - '0';
                if(result > INT_MAX/10 || (result == INT_MAX/10 && digit > 7)){
                    if(sign > 0) return INT_MAX;
                    else return INT_MIN;
                }
                result = result * 10 + digit;
            }
            else{
                break;
            }
            ++i;
        }
        return result * sign;
    }
};
// @lc code=end

