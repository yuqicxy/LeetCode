#
# @lc app=leetcode id=916 lang=python3
#
# [916] Word Subsets
#

import collections

# @lc code=start
class Solution:
    def wordSubsets(self, words1: list[str], words2: list[str]) -> list[str]:
        counter = collections.Counter()
        for w in words2:
            counter |= collections.Counter(w)
        return [w for w in words1 if not (counter - collections.Counter(w))]
# @lc code=end
s = Solution()
words1 = ["amazon","apple","facebook","google","leetcode"]
words2 = ["e","o"]
print(s.wordSubsets(words1,words2))
words1 = ["amazon","apple","facebook","google","leetcode"]
words2 = ["l","e"]
print(s.wordSubsets(words1,words2))