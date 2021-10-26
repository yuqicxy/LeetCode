/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @brief brutal force solution
     * 
     * Wikipedia:
     * https://en.wikipedia.org/wiki/Longest_palindromic_substring#Slow_algorithm
     * 
     * @param s 
     * @return string 
     */
    string longestPalindrome(string s) {
        vector<char> oddS;
        oddS.resize(s.length() * 2 + 1);
        oddS.push_back('#');
        for(size_t i = 0; i < s.length(); ++i){
            oddS.push_back(s.at(i));
            oddS.push_back('#');
        }

        vector<int> palindromeRadii; 
        palindromeRadii.resize(s.length() * 2 + 1);
        size_t size = oddS.size();
        for(size_t center = 0; center < size; ++center){
            int radius = 0;
            while(center - (radius + 1) >= 0 
            && center + (radius + 1) < size 
            && oddS[center-(radius + 1)] == oddS[center + (radius + 1)])
            {
                radius++;
            }
            palindromeRadii[center] = radius;
        }
    }
};
// @lc code=end

