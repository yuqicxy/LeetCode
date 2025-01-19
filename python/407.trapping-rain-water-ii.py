#
# @lc app=leetcode id=407 lang=python3
#
# [407] Trapping Rain Water II
#
class NoobSolution:
    def trapRainWater(self, heightMap: list[list[int]]) -> int:
        M = len(heightMap)
        N = len(heightMap[0])
        container = [[0] * N for i in range(M)]
        for r in range(M):
            left = 0
            right = N - 1
            max_left = 0
            max_right = 0
            while left < right:
                if heightMap[r][left] <= heightMap[r][right]:
                    if heightMap[r][left] > max_left:
                        max_left = heightMap[r][left]
                    else:
                        container[r][left] = max_left - heightMap[r][left]
                    left += 1
                else:
                    if heightMap[r][right] > max_right:
                        max_right = heightMap[r][right]
                    else:
                        container[r][right] = max_right - heightMap[r][right]
                    right -= 1
        ans = 0
        for c in range(N):
            bottom = 0
            top = M - 1
            max_top = 0
            max_bottom = 0
            while bottom < top:
                if heightMap[bottom][c] <= heightMap[top][c]:
                    if heightMap[bottom][c] > max_bottom:
                        max_bottom = heightMap[bottom][c]
                    else:
                        ans += min(max_bottom - heightMap[bottom][c], container[bottom][c])
                    bottom += 1
                else:
                    if heightMap[top][c] > max_top:
                        max_top = heightMap[top][c]
                    else:
                        ans += min(max_top - heightMap[top][c], container[top][c])
                    top -= 1
        return ans 
    
# @lc code=start

import heapq
class Solution:
    def trapRainWater(self, heightMap: list[list[int]]) -> int:
        if not heightMap or not heightMap[0]:
            return 0
			
		# Initial
		# Board cells cannot trap the water
        m, n = len(heightMap), len(heightMap[0])
        if m < 3 or n < 3:
            return 0
			
		# Add Board cells first
        heap = []
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
                    heightMap[i][j] = -1
					
		# Start from level 0
        level, res = 0, 0
        
        while heap:
            height, x, y = heapq.heappop(heap)
            level = max(height, level)

            for i, j in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
                if 0 <= i < m and 0 <= j < n and heightMap[i][j] != -1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
					
					# If cell's height smaller than the level, then it can trap the rain water
                    if heightMap[i][j] < level:
                        res += level - heightMap[i][j]

					# Set the height to -1 if the cell is visited
                    heightMap[i][j] = -1

        return res
# @lc code=end
s = Solution()
heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
print(s.trapRainWater(heightMap))
heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
print(s.trapRainWater(heightMap))
heightMap = [[12,13,1,12],[13,4,13,12],[13,8,10,12],[12,13,12,12],[13,13,13,13]]
print(s.trapRainWater(heightMap)) #14