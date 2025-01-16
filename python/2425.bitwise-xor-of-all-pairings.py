#
# @lc app=leetcode id=2425 lang=python3
#
# [2425] Bitwise XOR of All Pairings
#

from functools import reduce 
from operator import xor

# @lc code=start
class Solution:
    def xorAllNums(self, nums1: list[int], nums2: list[int]) -> int:
        return (len(nums1) % 2 * reduce(xor, nums2)) ^ (len(nums2) % 2 * reduce(xor, nums1))
        n1 = len(nums1)
        n2 = len(nums2)
        ans = 0
        if n1 % 2 != 0:
            for num in nums2:
                ans ^= num  
        if n2 % 2 != 0:
            for num in nums1:
                ans ^= num 
        return ans
# @lc code=end
s = Solution()
nums1 = [2,1,3]
nums2 = [10,2,5,0]
print(s.xorAllNums(nums1,nums2))
nums1 = [1,2]
nums2 = [3,4]
print(s.xorAllNums(nums1,nums2))