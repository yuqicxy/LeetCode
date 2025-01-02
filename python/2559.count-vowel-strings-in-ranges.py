#
# @lc app=leetcode id=2559 lang=python3
#
# [2559] Count Vowel Strings in Ranges
#

# @lc code=start
class Solution:
    def vowelStrings(self, words: list[str], queries: list[list[int]]) -> list[int]:
        prefixVowels  = [0]
        vowel = ['a','e','i','o','u']
        count = 0
        for w in words:
            if w[0] in vowel and w[-1] in vowel:
                count += 1
            prefixVowels.append(count)
        ans = []
        for q in queries:
            ans.append(prefixVowels[q[1] + 1] - prefixVowels[q[0]])
        return ans
        
# @lc code=end
s = Solution()
words = ["aba","bcb","ece","aa","e"]
queries = [[0,2],[1,4],[1,1]]
print(s.vowelStrings(words, queries))
words = ["a","e","i"]
queries = [[0,2],[0,1],[2,2]]
print(s.vowelStrings(words, queries))
