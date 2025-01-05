#
# @lc app=leetcode id=2381 lang=python3
#
# [2381] Shifting Letters II
#
import itertools

# @lc code=start
class Solution:
    def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
        pos = [0] * (len(s) + 1)
        for shift in shifts:
            dir = 1 if shift[2] else -1
            pos[shift[0]] += dir
            pos[shift[1] + 1] -= dir
        pos = list(itertools.accumulate(pos))
        res = [chr((ord(s[i]) - ord('a') + pos[i]) % 26 + ord('a')) for i in range(len(s))]
        return "".join(res)
# @lc code=end
so = Solution()
s = "abc"
shifts = [[0,1,0],[1,2,1],[0,2,1]]
print(so.shiftingLetters(s,shifts))
s = "dztz"
shifts = [[0,0,0],[1,1,1]]
print(so.shiftingLetters(s,shifts))
