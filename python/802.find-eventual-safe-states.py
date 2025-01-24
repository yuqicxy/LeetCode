#
# @lc app=leetcode id=802 lang=python3
#
# [802] Find Eventual Safe States
#

# @lc code=start
class Solution:
    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:
        N = len(graph)
        visited = [False] * N
        safeNode = [False] * N
        
        def dfs(i:int):
            if visited[i]: return False
            visited[i] = True
            if safeNode[i]: return True
            isSafe = True
            for node in graph[i]:
                if not safeNode[node]:
                   isSafe = isSafe and dfs(node)
            safeNode[i] = isSafe
            return isSafe
        
        for i in range(N):
            dfs(i)
        return [idx for idx,v in enumerate(safeNode) if v]
# @lc code=end

s = Solution()
graph = [[1,2],[2,3],[5],[0],[5],[],[]]
print(s.eventualSafeNodes(graph))
graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
print(s.eventualSafeNodes(graph))
