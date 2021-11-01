/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> lastResult; 
        if(digits.empty()) return lastResult;
        std::map<char,std::vector<char>> map;
        char currentLetter = 'a';
        for(int i = 2; i < 10; ++i){
            std::vector<char> charVec;
            char c = i + '0';
            int iterateNum = 3;
            if(i == 7 || i == 9)
                iterateNum = 4;
            for(int j = 0; j < iterateNum; ++j){
                charVec.push_back(currentLetter);
                currentLetter += 1;
            }
            map[c] = charVec; 
        }
        lastResult.push_back(""); 
        for(auto digit : digits){
            vector<string> currentResult;
            for(auto c : map[digit]){
                for( auto n: lastResult){
                    currentResult.push_back(n + string(1,c));
                }
            }
            std::swap(lastResult,currentResult);
        }
        return lastResult;
    }
};
// @lc code=end

