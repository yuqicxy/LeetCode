#
# @lc app=leetcode id=1408 lang=python3
#
# [1408] String Matching in an Array
#

class KMP:
    def findPattern(word : str, pattern: str) -> int:
        pi = KMP.calcKMPPrefixArray(pattern)
        j = 0
        for i in range(len(word)):
            while j > 0 and word[i] != pattern[j]:
                j = pi[j - 1]
            if word[i] == pattern[j]:
                j += 1
            if j == len(pi):
                return i - len(pattern) + 1
        return -1
    

    def findByPi(word : str, pattern: str, pi: list[int]) -> int:
        j = 0
        for i in range(len(word)):
            while j > 0 and word[i] != pattern[j]:
                j = pi[j - 1]
            if word[i] == pattern[j]:
                j += 1
            if j == len(pi):
                return i - len(pattern) + 1
        return -1
    
    def calcKMPPrefixArray(pattern: str) -> list[int]:
        pi = [0] * len(pattern)
        for i in range(1, len(pattern)):
            j = pi[i - 1]
            while j > 0 and pattern[i] != pattern[j]:
                j = pi[j - 1]
            if pattern[i] == pattern[j]:
                j += 1
            pi[i] = j
        return pi

class MySolution:
    def stringMatching(self, words: list[str]) -> list[str]:
        PIs = []
        for word in words:
            PIs.append(KMP.calcKMPPrefixArray(word))
        ans = []
        for i in range(len(words)):
            for j in range(len(words)):
                if i == j: 
                    continue
                if len(words[j]) >= len(words[i]) and KMP.findByPi(words[j], words[i], PIs[i]) > -1:
                    ans.append(words[i])
                    break
        return ans
    
# @lc code=start

class Solution:
    def stringMatching(self, words: list[str]) -> list[str]:
        final_list = []
        mega_word = " ".join(words)
        ans = [word for word in words if mega_word.count(word) > 1]
        return ans
# @lc code=end

print(KMP.findPattern("leetcoder", "leetcode"))
s = Solution()
words = ["mass","as","hero","superhero"]
print(s.stringMatching(words))
words = ["leetcode","et","code"]
print(s.stringMatching(words))
words = ["blue","green","bu"]
print(s.stringMatching(words))
words = ["leetcoder","leetcode","od","hamlet","am"]
print(s.stringMatching(words))
