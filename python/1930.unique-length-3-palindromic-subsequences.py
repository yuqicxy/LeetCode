#
# @lc app=leetcode id=1930 lang=python3
#
# [1930] Unique Length-3 Palindromic Subsequences
#
import string
# @lc code=start
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        ans = 0
        for c in string.ascii_lowercase:
            l = s.find(c)
            r = s.rfind(c)
            if l > -1:
                ans += len(set(s[l + 1:r]))
        return ans
# @lc code=end


so = Solution()
s = "aabca"
print(so.countPalindromicSubsequence(s))
s = "adc"
print(so.countPalindromicSubsequence(s))
s = "bbcbaba"
print(so.countPalindromicSubsequence(s))