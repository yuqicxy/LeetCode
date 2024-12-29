#
# @lc app=leetcode id=1639 lang=python3
#
# [1639] Number of Ways to Form a Target String Given a Dictionary
#
import functools

class MySolution:
    def numWays(self, words: list[str], target: str) -> int:
        def count(str):
            ansArr = []
            K = len(words[0])
            for k in range(K):
                ans = 0
                for word in words:
                    if word[k] == str:
                        ans += 1
                ansArr.append(ans)
            return ansArr
                
        K = len(words[0])
        N = len(target)
        DP = [0] * K
        for i,c in enumerate(target):
            newDP = [0] * K
            countsArr = count(c)
            prefixSum = 0
            for k in range(i,K):
                prefixSum += DP[k-1]
                if i == 0:
                    newDP[k] = countsArr[k]
                else:
                    newDP[k] = prefixSum * countsArr[k]
            DP = newDP
        return sum(DP) % (10**9 + 7)
    
import collections

# @lc code=start
class Solution:
    def numWays(self, words: list[str], target: str) -> int:
        N = len(target)
        mod = (10**9 + 7)
        DP = [1] + [0] * N
        K = len(words[0])
        for i in range(K):
            count = collections.Counter(w[i] for w in words)
            for j in range(N-1, -1,-1):
                DP[j+1] += (DP[j] * count[target[j]]) % mod
        return DP[N] % mod
# @lc code=end

s = Solution()
words = ["acca","bbbb","caca"]
target = "aba"
print(s.numWays(words, target))
words = ["abba","baab"]
target = "bab"
print(s.numWays(words, target))