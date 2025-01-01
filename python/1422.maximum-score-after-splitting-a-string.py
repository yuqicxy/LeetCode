#
# @lc app=leetcode id=1422 lang=python3
#
# [1422] Maximum Score After Splitting a String
#
class MySolution:
    def maxScore(self, s: str) -> int:
        arr = []
        num = 0
        for c in s:
            if c == "0":
                num += 1
            arr.append(num)
        N = len(arr)
        ones = N - num
        ans = 0
        for i in range(N-1):
            ans = max(ans, 2 * arr[i] + ones - i - 1)
        return ans
    
class Solution1:
    def maxScore(self, s: str) -> int:
        ones = s.count("1")
        zeros = 0
        ans = 0 

        for i in range(len(s) - 1):
            if s[i] == "1":
                ones -= 1
            else:
                zeros += 1
        
            ans = max(ans, zeros + ones)
        
        return ans
# @lc code=start
class Solution:
    def maxScore(self, s: str) -> int:
        ones = 0
        zeros = 0
        best = -inf

        for i in range(len(s) - 1):
            if s[i] == "1":
                ones += 1
            else:
                zeros += 1
            
            best = max(best, zeros - ones)
            
        if s[-1] == "1":
            ones += 1
        
        return best + ones
# @lc code=end

so = Solution()
s = "011101"
print(so.maxScore(s))
s = "00111"
print(so.maxScore(s))
s = "1111"
print(so.maxScore(s))
