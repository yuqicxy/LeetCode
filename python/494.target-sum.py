#
# @lc app=leetcode id=494 lang=python3
#
# [494] Target Sum
#

class NoobSolution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        dp = [0]
        for num in nums:
            dp = [v for val in dp for v in (val-num,val + num)]
        return dp.count(target)


#  Sum(Positive) - Sum(Negative) = Target
#  Sum(P) + Sum(N) + Sum(P) - Sum(N) = Sum + Target
#  2 * Sum(P) = Sum + Target
#
#  Sum(P) = (Sum + Target) / 2
#

class DP1DSolution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        numSum = sum(nums);
        if numSum < target or target + numSum < 0 or (numSum + target) % 2 > 0:
            return 0
        return self.subsetSum(nums, int((target + numSum) / 2))
    
    
    def subsetSum(self, nums: list[int], target : int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        for num in nums:
            for i in range(target,num-1,-1):
                dp[i] += dp[i - num]
        return dp[target]
    
import collections;

# @lc code=start
# DP 1D
class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        if not nums or sum(nums) < target: 
            return 0
        dp = {};
        dp[0] = 1
        for i in range(0,len(nums)):
            temp_dp = collections.defaultdict(int)
            for k,v in dp.items():
                temp_dp[k + nums[i]] += v
                temp_dp[k - nums[i]] += v
            dp = temp_dp
        return dp[target];

# @lc code=end

s = Solution()
print(s.findTargetSumWays([1,1,1,1,1],3))
print(s.findTargetSumWays([1],1))
print(s.findTargetSumWays([100],-200))
