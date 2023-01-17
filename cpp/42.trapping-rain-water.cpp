/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
// height =              [ 0, 1, 0, 2, 1,0, 1, 3, 2,1, 2,1]
// deriveate of height = [ 1,-1,-2,-1,-1,1,-2,-1,-1,1,-1]

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int sum = 0;
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while(left != right){
            if(height[left] <= height[right]){
                if(height[left] > maxLeft) maxLeft = height[left];
                else sum += maxLeft - height[left];
                ++left;
            }else if(height[right] < height[left]){
                if(height[right] > maxRight) maxRight = height[right];
                else sum += maxRight - height[right];
                --right;
            }
        }
        return sum;
    }
};
// @lc code=end

