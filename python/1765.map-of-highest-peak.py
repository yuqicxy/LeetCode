#
# @lc app=leetcode id=1765 lang=python3
#
# [1765] Map of Highest Peak
#

class NoobSolution:
    def highestPeak(self, isWater: list[list[int]]) -> list[list[int]]:
        M = len(isWater)
        N = len(isWater[0])
        ans = [[0] * N for i in range(M)]
        zeros = [[i,j] for i,row in enumerate(isWater) for j, num in enumerate(row) if num == 1]
        for i in range(M):
            for j in range(N):
                distance = 0
                if not isWater[i][j]:
                    distance = 10**9
                    for zero in zeros:
                        distance = min(distance, abs(zero[0] - i) + abs(zero[1] - j))
                ans[i][j] = distance
        return ans

from collections import deque

# @lc code=start
class Solution:
    directions = [
        [0,1],[1,0],[-1,0],[0,-1]
    ]
    
    def highestPeak(self, isWater: list[list[int]]) -> list[list[int]]:
        M = len(isWater)
        N = len(isWater[0])
        ans = [[-1] * N for i in range(M)]
        bfs = deque([])
        for i,row in enumerate(isWater):
            for j, num in enumerate(row):
                if num == 1:
                    ans[i][j] = 0     
                    bfs.append([i,j])
        while bfs:
            r,c = bfs.popleft()
            for dir in self.directions:
                nr = r + dir[0]
                nc = c + dir[1]
                if 0 <= nr < M and 0 <= nc < N and ans[nr][nc] == -1:
                    ans[nr][nc] = ans[r][c] + 1
                    bfs.append([nr,nc])
        return ans
# @lc code=end
s = Solution()
isWater = [[0,1],[0,0]]
print(s.highestPeak(isWater))
isWater = [[0,0,1],[1,0,0],[0,0,0]]
print(s.highestPeak(isWater))