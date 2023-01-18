/*
 * @lc app=leetcode id=11 lang=typescript
 *
 * [11] Container With Most Water
 */

// @lc code=start
function maxArea(height: number[]): number {
    let max = 0;
    let len = height.length;
    let left = 0, right = len - 1;
    while(left != right){
        let lh = height[left];
        let rh = height[right];
        let val = Math.min(lh,rh);
        max = Math.max(val*(right-left),max);

        if(lh < rh)
            left++;
        else
            right--;
    }

    return max;
};
// @lc code=end

