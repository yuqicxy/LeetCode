#
# @lc app=leetcode id=2683 lang=python3
#
# [2683] Neighboring Bitwise XOR
#

# @lc code=start
class Solution:
    def doesValidArrayExist(self, derived: list[int]) -> bool:
        return sum(derived) % 2 == 0
# @lc code=end

