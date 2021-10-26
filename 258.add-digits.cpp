/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
/**
 * @brief algorithm: congruence formula
 * 
 * https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
 * 
 */
class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        return 1 + (num-1)%9; 
    }
};
// @lc code=end

