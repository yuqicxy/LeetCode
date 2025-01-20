#
# @lc app=leetcode id=2661 lang=python3
#
# [2661] First Completely Painted Row or Column
#

# @lc code=start
class Solution:
    def firstCompleteIndex(self, arr: list[int], mat: list[list[int]]) -> int:
        M = len(mat)
        N = len(mat[0])
        
        searchTable = { mat[i][j]:(i,j) for i in range(M) for j in range(N) }
                
        row = [0] * M
        col = [0] * N
        for i, val in enumerate(arr):
            r,c = searchTable[val]
            row[r] += 1
            col[c] += 1
            if row[r] == N or col[c] == M:
                return i
        return -1
# @lc code=end

s = Solution()
arr = [1,3,4,2]
mat = [[1,4],[2,3]]
print(s.firstCompleteIndex(arr,mat))
arr = [2,8,7,4,1,3,5,6,9]
mat = [[3,2,5],[1,4,6],[8,7,9]]
print(s.firstCompleteIndex(arr,mat))
arr = [1,4,5,2,6,3]
mat = [[4,3,5],[1,2,6]]
print(s.firstCompleteIndex(arr,mat))
