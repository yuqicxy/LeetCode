#
# @lc app=leetcode id=1769 lang=python3
#
# [1769] Minimum Number of Operations to Move All Balls to Each Box
#

# @lc code=start
class Solution:
    def minOperations(self, boxes: str) -> list[int]:
        ans = [0] * len(boxes)
        count = 0
        ops = 0
        for i in range(len(boxes)):
            ans[i] += ops
            count += 1 if boxes[i] == '1' else 0 
            ops += count
        count = 0
        ops = 0
        for i in range(len(boxes) - 1, -1, -1):
            ans[i] += ops
            count +=  1 if boxes[i] == '1' else 0 
            ops += count
        return ans
# @lc code=end


s = Solution()
print(s.minOperations("110"))
print(s.minOperations("001011"))
