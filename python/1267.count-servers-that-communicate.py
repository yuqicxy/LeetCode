#
# @lc app=leetcode id=1267 lang=python3
#
# [1267] Count Servers that Communicate
#

# @lc code=start
class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        X = [sum(row) for row in grid]
        Y = [sum(col) for col in zip(*grid)]
        return sum(X[i] + Y[j] > 2 for i in range(len(grid)) for j in range(len(grid[0])) if grid[i][j])
# @lc code=end
s = Solution()
grid = [[1,0],[0,1]]
print(s.countServers(grid))
grid = [[1,0],[1,1]]
print(s.countServers(grid))
grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
print(s.countServers(grid))