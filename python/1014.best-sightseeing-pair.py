#
# @lc app=leetcode id=1014 lang=python3
#
# [1014] Best Sightseeing Pair
#

# Linear programming
# max{ nums[i] + nums[j] + i - j } 
# constraints  0 <= i < j < N

# @lc code=start
class Solution:
    # maxPre = values[i] + i
    # maxPost = values[j] - j
    def maxScoreSightseeingPair(self, values: list[int]) -> int:
        maxPre = 0;
        maxPost = 0;
        for i, value in enumerate(values):
            maxPost = max(maxPost, maxPre + value - i)
            maxPre = max(maxPre, value + i)
        return maxPost
            
# @lc code=end

s = Solution()
values = [8,1,5,2,6]
print(s.maxScoreSightseeingPair(values))
values = [1,2]
print(s.maxScoreSightseeingPair(values))