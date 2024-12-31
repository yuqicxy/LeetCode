#
# @lc app=leetcode id=983 lang=python3
#
# [983] Minimum Cost For Tickets
#

# @lc code=start
class Solution:
    def mincostTickets(self, days: list[int], costs: list[int]) -> int:
        travel = set(days)
        DP = [0] * 366
        for d in range(1,366):
            if d in travel:
                DP[d] = min(DP[max(0,d-1)] + costs[0], DP[max(0, d-7)] + costs[1], DP[max(0, d - 30)] + costs[2])
            else:
                DP[d] = DP[d-1]
        return DP[-1]
# @lc code=end

s = Solution()
days = [1,4,6,7,8,20]
costs = [2,7,15]
print(s.mincostTickets(days, costs))

days = [1,2,3,4,5,6,7,8,9,10,30,31]
costs = [2,7,15]
print(s.mincostTickets(days, costs))