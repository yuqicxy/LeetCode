#
# @lc app=leetcode id=1368 lang=python3
#
# [1368] Minimum Cost to Make at Least One Valid Path in a Grid
#
import math

class StupidSolution:
    def minCost(self, grid: list[list[int]]) -> int:
        N = len(grid)
        M = len(grid[0])
        dp = [[math.inf] * M for i in range(N)]
        dp[0][0] = 0
        stk = []
        directions = [[0,1],[0,-1],[1,0],[-1,0]]
        stk.append([0,0])
        while len(stk) != 0:
            [row, col] = stk.pop()
            for i, dir in enumerate(directions):
                r,c = row + dir[0], col + dir[1]
                if not (0<= r < N and 0 <= c < M):
                    continue
                if grid[row][col] == i + 1 and dp[row][col] < dp[r][c]:
                    dp[r][c] = dp[row][col]
                    stk.append([r,c])
                elif dp[row][col] + 1 < dp[r][c]:
                    dp[r][c] = dp[row][col] + 1
                    stk.append([r,c])
        return dp[-1][-1]

# @lc code=start
class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        N = len(grid)
        M = len(grid[0])
        inf = 10**9
        dp = [[inf] * M for i in range(N)]
        cost = 0
        directions = [[0,1],[0,-1],[1,0],[-1,0]]
        bfs = []
        
        def dfs(row, col):
            if not (0 <= row < N and 0 <= col < M and dp[row][col] == inf):
                return
            dp[row][col] = cost
            bfs.append([row,col])
            dfs(row + directions[grid[row][col] - 1][0], col + directions[grid[row][col] - 1][1])
            
        dfs(0,0)
        while bfs:
            bfs, bfs2 = [], bfs
            cost += 1
            [dfs(r + i, c + j) for r,c in bfs2 for i,j in directions]
        
        return dp[-1][-1]
# @lc code=end
s = Solution()
grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
print(s.minCost(grid))
grid = [[1,1,3],[3,2,2],[1,1,4]]
print(s.minCost(grid))
grid = [[1,2],[4,3]]
print(s.minCost(grid))
grid = [[2,2,2],[2,2,2]]
print(s.minCost(grid))