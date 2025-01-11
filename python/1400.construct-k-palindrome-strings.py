#
# @lc app=leetcode id=1400 lang=python3
#
# [1400] Construct K Palindrome Strings
#

import collections

# @lc code=start
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        counter = collections.Counter(s)
        t = sum(val % 2 for key, val in counter.items())
        return t <= k <= len(s)
# @lc code=end

so = Solution()
s = "annabelle"
k = 2
print(so.canConstruct(s,k))

s = "leetcode"
k = 3
print(so.canConstruct(s,k))

s = "true"
k = 4
print(so.canConstruct(s,k))