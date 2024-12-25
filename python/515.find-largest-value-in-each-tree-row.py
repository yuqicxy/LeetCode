#
# @lc app=leetcode id=515 lang=python3
#
# [515] Find Largest Value in Each Tree Row
#
import sys;

class MySolution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root == None:
            return ans
        q1 = []
        q1.append(root)
        while len(q1) > 0:
            maxEle = -sys.maxsize - 1
            q2=[]
            for node in q1:          
                maxEle = max(maxEle, node.val)  
                if node.left != None:
                    q2.append(node.left)
                if node.right != None:
                    q2.append(node.right)
            ans.append(maxEle)
            q1 = q2
        return ans

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        maxes = []
        row = [root]
        while any(row):
            maxes.append(max(node.val for node in row))
            row = [kid for node in row for kid in (node.left, node.right) if kid]
        return maxes
# @lc code=end

