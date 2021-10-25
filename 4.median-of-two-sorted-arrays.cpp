/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const size_t M = nums1.size();
        const size_t N = nums2.size();
        if (M > N) return findMedianSortedArrays(nums2, nums1);
        double max_of_left = 0, min_of_right = 0;
        size_t halflen = (M + N + 1) >> 1;
        size_t imin = 0, imax = M;
        while (imin <= imax) {
            int i = (imin + imax) >> 1;
            int j = halflen - i;

            if (i > 0 && nums1.at(i - 1) > nums2.at(j)) {
                imax = i - 1;
            }
            else if (i < M && nums2.at(j - 1) > nums1.at(i)) {
                imin = i + 1;
            }
            else {
                if (i == 0) max_of_left = nums2.at(j - 1);
                else if (j == 0) max_of_left = nums1.at(i - 1);
                else max_of_left = max(nums1.at(i - 1), nums2.at(j - 1));

                if ((M + N) % 2 == 1) {
                    return max_of_left;
                }

                if (i == M) min_of_right = nums2.at(j);
                else if (j == N) min_of_right = nums1.at(i);
                else min_of_right = min(nums1.at(i), nums2.at(j));

                return (max_of_left + min_of_right) / 2.0f;
            }
        }
        return 0;
    }
};
// @lc code=end

