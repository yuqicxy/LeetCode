#
# @lc app=leetcode id=2466 lang=python3
#
# [2466] Count Ways To Build Good Strings
#

# @lc code=start
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        mod = (10**9 + 7)
        dp = [1]
        for i in range(1,high + 1):
            count = 0
            if i >= zero:
                count = (count + dp[i-zero]) % mod
            if i >= one:
                count = (count + dp[i-one]) % mod
            dp.append(count)
        return sum(dp[low:high + 1]) % mod
            
# @lc code=end

s = Solution()
low = 3
high = 3
zero = 1
one = 1
print(s.countGoodStrings(low,high,zero,one))
low = 2
high = 3
zero = 1
one = 2
print(s.countGoodStrings(low,high,zero,one))
