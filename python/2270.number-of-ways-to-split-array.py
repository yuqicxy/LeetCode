#
# @lc app=leetcode id=2270 lang=python3
#
# [2270] Number of Ways to Split Array
#

# @lc code=start
class Solution:
    def waysToSplitArray(self, nums: list[int]) -> int:
        Sn = sum(nums) / 2
        Si = 0
        count = 0
        for i in range(len(nums)-1):
            Si += nums[i]
            if Si >= Sn:
                count += 1
        return count
# @lc code=end
s = Solution()
nums = [10,4,-8,7]
print(s.waysToSplitArray(nums))
nums = [2,3,1,0]
print(s.waysToSplitArray(nums))
