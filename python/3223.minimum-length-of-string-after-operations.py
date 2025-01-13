#
# @lc app=leetcode id=3223 lang=python3
#
# [3223] Minimum Length of String After Operations
#

import collections

# @lc code=start
class Solution:
    def minimumLength(self, s: str) -> int:
        c = collections.Counter(s)
        return sum(1 if v % 2 else 2 for k,v in c.items())
# @lc code=end

so = Solution()
s = "abaacbcbb"
print(so.minimumLength(s))
s = "ucvbutgkohgbcobqeyqwppbxqoynxeuuzouyvmydfhrprdbuzwqebwuiejoxsxdhbmuaiscalnteocghnlisxxawxgcjloevrdcj"
print(so.minimumLength(s))

