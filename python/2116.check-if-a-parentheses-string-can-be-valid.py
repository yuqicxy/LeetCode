#
# @lc app=leetcode id=2116 lang=python3
#
# [2116] Check if a Parentheses String Can Be Valid
#

# @lc code=start
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        def validate(s: str, locked: str, op: str) -> bool:
            bal, wild = 0, 0
            for i in range(len(s)):
                if locked[i] == "1":
                    bal += 1 if s[i] == op else -1
                else:
                    wild += 1
                if wild + bal < 0:
                    return False
            return bal <= wild
        return len(s) % 2 == 0 and validate(s, locked, '(') and validate(s[::-1], locked[::-1], ')')
# @lc code=end

so =Solution()
s = "))()))"
locked = "010100"
print(so.canBeValid(s,locked))