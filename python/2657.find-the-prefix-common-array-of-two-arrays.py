#
# @lc app=leetcode id=2657 lang=python3
#
# [2657] Find the Prefix Common Array of Two Arrays
#

from collections import Counter
# @lc code=start
class Solution:
    def findThePrefixCommonArray(self, A: list[int], B: list[int]) -> list[int]:
        counter = Counter()
        ans = []
        common = 0
        for i in range(len(A)):
            if counter[A[i]] > 0:
                common += 1
            else:
                counter[A[i]] = 1
            if counter[B[i]] > 0:
                common += 1
            else:
                counter[B[i]] = 1
            ans.append(common)
        return ans
            
# @lc code=end

s = Solution()
A = [1,3,2,4]
B = [3,1,2,4]
print(s.findThePrefixCommonArray(A,B))
A = [2,3,1]
B = [3,1,2]
print(s.findThePrefixCommonArray(A,B))