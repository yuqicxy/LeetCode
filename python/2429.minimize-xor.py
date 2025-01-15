#
# @lc app=leetcode id=2429 lang=python3
#
# [2429] Minimize XOR
#

# @lc code=start
class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        n1 = bin(num1).count('1')
        n2 = bin(num2).count('1')
        # n1 = num1.bit_count()  # for python >= 3.10
        # n2 = num2.bit_count()
        i = 0
        while n1 != n2:
            if n1 > n2:
                if (1 << i) & num1 != 0:
                    num1 ^= (1 << i)
                    n1 -= 1
                i += 1
            if n1 < n2:
                if (1 << i) & num1 == 0:
                    num1 ^= (1 << i)
                    n2 -= 1
                i += 1
        return num1
# @lc code=end

s = Solution()
num1 = 3
num2 = 5
print(s.minimizeXor(num1, num2))
num1 = 1
num2 = 12
print(s.minimizeXor(num1, num2))