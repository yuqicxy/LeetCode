#
# @lc app=leetcode id=689 lang=python3
#
# [689] Maximum Sum of 3 Non-Overlapping Subarrays
#

# @lc code=start
class MySolution:
    def maxSumOfThreeSubarrays(self, nums: list[int], k: int) -> list[int]:
        prefixSum = []
        for i in range(len(nums) - k + 1):
            prefixSum.append(sum(nums[i:i+k]))

        best = 0
        left = [0] * len(prefixSum)
        for i in range(len(prefixSum)):
            if prefixSum[i] > prefixSum[best]:
                best = i
            left[i] = best

        best = len(prefixSum) - 1
        right = [0] * len(prefixSum)
        for i in range(len(prefixSum) - 1, -1, -1):
            if prefixSum[i] >= prefixSum[best]:
                best = i
            right[i] = best

        maxSum = 0;
        ans = None
        for j in range(k, len(prefixSum) - k):
            l = left[j - k]
            r = right[j + k]
            if ans is None or ((prefixSum[l] + prefixSum[j] + prefixSum[r]) > (prefixSum[ans[0]] + prefixSum[ans[1]] + prefixSum[ans[2]])):
                ans = [l, j, r]
        return ans

# @lc code=end
class Solution:
    def maxSumOfThreeSubarrays(self, nums, k):
        n = len(nums)
        maxsum = 0
        sum = [0]
        for i in nums:
            sum.append(sum[-1] + i)

        # DP for starting index of the left max sum interval
        tot = sum[k] - sum[0]
        posLeft = [0] * n
        for i in range(k, n):
            if sum[i + 1] - sum[i + 1 - k] > tot:
                posLeft[i] = i + 1 - k
                tot = sum[i + 1] - sum[i + 1 - k]
            else:
                posLeft[i] = posLeft[i - 1]


        # DP for starting index of the right max sum interval
        posRight = [n - k] * n
        tot = sum[n] - sum[n - k]
        for i in range(n - k - 1, -1, -1):
            if sum[i + k] - sum[i] > tot:
                posRight[i] = i
                tot = sum[i + k] - sum[i]
            else:
                posRight[i] = posRight[i + 1]


        ans = [0, 0, 0]
        # test all possible middle interval
        for i in range(k, n - 2 * k + 1):
            l = posLeft[i - 1]
            r = posRight[i + k]
            tot = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r])
            if tot > maxsum:
                maxsum = tot
                ans = [l, i, r]
        return ans

s = Solution()
nums = [1,2,1,2,6,7,5,1]
k = 2
print(s.maxSumOfThreeSubarrays(nums,k))
nums = [1,2,1,2,1,2,1,2,1]
k = 2
print(s.maxSumOfThreeSubarrays(nums,k))
