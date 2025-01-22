#
# @lc app=leetcode id=2017 lang=python3
#
# [2017] Grid Game
#
class StupidSolution:
    directions = [[0,1],[1,0]]

    def gridGame(self, grid: list[list[int]]) -> int:
        costs = self.BFS(grid)
        M = 2
        N = len(grid[0])
        i,j = 1, N-1
        while i >= 0 and j >= 0: 
            grid[i][j] = 0
            d = costs[i][j][1]
            i -= Solution.directions[d][0]
            j -= Solution.directions[d][1]
        costs = self.BFS(grid)
        return costs[-1][-1][0]
        
    def BFS(self, grid:list[list[int]]):
        M = 2
        N = len(grid[0])
        costs = [[[0,0]] * N for i in range(M)]
        stk = []
        stk.append([0,0])
        costs[0][0] = [grid[0][0],0]
        while stk:
            [r,c] = stk.pop()
            for i in range(len(Solution.directions)):
                row = r + Solution.directions[i][0]
                col = c + Solution.directions[i][1]
                if 0 <= row < M and 0 <= col < N and grid[row][col] + costs[r][c][0] >= costs[row][col][0]:
                    stk.append([row,col])
                    costs[row][col] = [grid[row][col] + costs[r][c][0], i]
        return costs

import math

# @lc code=start
class Solution:
    directions = [[0,1],[1,0]]
    def gridGame(self, grid: list[list[int]]) -> int:
        bottom = 0
        top = sum(grid[0])
        ans = math.inf
        for t, b in zip(grid[0], grid[1]):
            top -= t
            ans = min(ans, max(top, bottom))
            bottom += b
        return ans
# @lc code=end

s= Solution()
# grid = [[2,5,4],[1,5,1]]
# print(s.gridGame(grid))
# grid = [[3,3,1],[8,5,2]]
# print(s.gridGame(grid))
# grid = [[1,3,1,15],[1,3,3,1]]
# print(s.gridGame(grid))
grid = [[20,3,20,17,2,12,15,17,4,15],[20,10,13,14,15,5,2,3,14,3]] #63
print(sum(grid[1]) - grid[-1][-1])
print(s.gridGame(grid))
