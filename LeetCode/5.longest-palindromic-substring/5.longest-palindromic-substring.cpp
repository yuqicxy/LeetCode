/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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
        if(s.size() < 2) return s;

        vector<char> oddS;
        oddS.push_back('#');
        for(size_t i = 0; i < s.length(); ++i){
            oddS.push_back(s.at(i));
            oddS.push_back('#');
        }

        int maxSize = 0;
        int maxSizeCenter = 0;

        int size = oddS.size();
        for(int center = 0; center < size; ++center){
            int radius = 0;
            while(((center - (radius + 1) >= 0)
            && (center + (radius + 1) < size))
            && (oddS.at(center-(radius + 1)) == oddS.at(center + (radius + 1))))
            {
                radius++;
            }
            radius = radius-1;
            if(radius > maxSize){
                maxSize = radius;
                maxSizeCenter = center;
            }
        }

        stringstream ss;
        string result;
        for(int i = maxSizeCenter - (maxSize + 1); i <= maxSizeCenter+ maxSize + 1; ++i){
            if(oddS.at(i) == '#')
                continue;
            ss<<oddS.at(i);
        }
        ss>>result;
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::cout<<s.longestPalindrome("a");
}