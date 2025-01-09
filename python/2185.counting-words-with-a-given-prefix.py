#
# @lc app=leetcode id=2185 lang=python3
#
# [2185] Counting Words With a Given Prefix
#

# @lc code=start
class Solution:
    def prefixCount(self, words: list[str], pref: str) -> int:
        return sum(1 for w in words if w.startswith(pref))
        
# @lc code=end
s = Solution()
words = ["pay","attention","practice","attend"]
pref = "at"
print(s.prefixCount(words, pref))

words = ["sxyjellhlh"]
pref = "sxyjellhlh"
print(s.prefixCount(words, pref))