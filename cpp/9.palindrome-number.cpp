/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include<iostream>
#include<vector>
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        int tmp = x;
        unsigned int reversed = 0;
        while(tmp != 0){
            int digit = tmp % 10;
            reversed = reversed * 10 + digit;
            tmp = tmp / 10;
        }

        if(reversed == x)
            return true;
        
        return false;
    }
};
// @lc code=end
int main(){
    Solution s;
    std::cout << std::boolalpha;
    std::cout << s.isPalindrome(121) << std::endl;
    return 0;
}
