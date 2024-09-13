/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int count = 0;
        int result = 0;
        while(x != 0){
            int tmp = x % 10;
            if(tmp > 0 && result > (INT_MAX - tmp)/10)
                return 0;
            if(tmp < 0 && result < (INT_MIN - tmp)/10)
                return 0;
            result = result * 10 + tmp;
            x /= 10;
        }
        return result;
    }
};
// @lc code=end

