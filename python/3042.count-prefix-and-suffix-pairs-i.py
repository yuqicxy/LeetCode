#
# @lc app=leetcode id=3042 lang=python3
#
# [3042] Count Prefix and Suffix Pairs I
#

# @lc code=start
class Solution:
    def countPrefixSuffixPairs(self, words: list[str]) -> int:
        N = len(words)
        ans = 0
        for i in range(N):
            for j in range(i + 1, N):
               if self.isPrefixAndSuffix(words[i], words[j]):
                   ans += 1
        return ans
    
    def isPrefixAndSuffix(self, str1:str, str2: str)->bool:
        N = len(str1)
        if N > len(str2): 
            return False
        if str1 == str2[:N] and str1 == str2[-N:]:
            return True
        return False
        
# @lc code=end
s = Solution()

words = ["a","aba","ababa","aa"]
print(s.countPrefixSuffixPairs(words))
words = ["pa","papa","ma","mama"]
print(s.countPrefixSuffixPairs(words))
words = ["abab","ab"]
print(s.countPrefixSuffixPairs(words))

